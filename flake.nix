{
  description = "Lumina Engine is an open source game development engine.";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    nixgl = {
      url = "github:guibou/nixGL";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    { self, nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
      libPath =
        with pkgs;
        lib.makeLibraryPath [
          libGL
          libxkbcommon
          vulkan-headers
          vulkan-loader
          vulkan-tools
          vulkan-validation-layers
          wayland
          xorg.libX11
          xorg.libXcursor
          xorg.libXi
          xorg.libXrandr
        ];
      LuminaEngine = pkgs.stdenv.mkDerivation {
        pname = "LuminaEngine";
        version = "0.1.0";

        src = ./.;

        # TODO: make some packages only available in build phase
        buildInputs = with pkgs; [
          clang
        ];

        LD_LIBRARY_PATH = libPath;
      };
    in
    {
      formatter.x86_64-linux = pkgs.nixfmt-rfc-style;
      packages.x86_64-linux.LuminaEngine = LuminaEngine;
      devShells.x86_64-linux.default = LuminaEngine;
    };
}
