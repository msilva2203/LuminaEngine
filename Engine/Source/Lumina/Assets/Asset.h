#ifndef ASSET_H
#define ASSET_H

#pragma once

#include "Core/Core.h"
#include "Utility/Types.h"

#include <filesystem>

namespace Lumina {

    // TODO: Replace with an unique uniform id generated per asset
    using AssetHandle = uint64;

    /**
     * Abstract class of an asset
     */
    class LUMINA_API Asset
    {
    public:

        /**
         * Represents the type of the asset
         * 
         * To be expanded in the future to allow more asset types
         */
        enum class EType : uint8
        {
            None,
            Data,
            Level,
            Texture2D
            //...
        };

        /**
         * Structure of properties representing the metadata of an asset
         * Used primarily for debug purposes (editor) and should probably be stripped from distribution 
         */
        struct Metadata
        {
            AssetHandle Handle;
            Asset::EType Type;
            std::filesystem::path FilePath; 
        };

        // To be defined per asset using DECLARE_ASSET macro
        virtual Asset::EType GetAssetType() const = 0;

        AssetHandle GetAssetHandle() const { return this->Handle; }

    private:
        // Should be automatically generated
        AssetHandle Handle;

    };

    // Used to automatically implement necessary definitions in future assets
    #define DECLARE_ASSET(Type) \
        static Asset::EType GetStaticAssetType() { return Asset::EType::Type; } \
        virtual Asset::EType GetAssetType() const override { return GetStaticAssetType(); } \

}

#endif /* ASSET_H */