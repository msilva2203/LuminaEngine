CXX       = clang++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++17
CXXFLAGS += -Wno-error=unused-parameter
CXXFLAGS += -Wno-error=unused-variable
CXXFLAGS += -Wno-error=unused-but-set-variable

LDFLAGS =

LuminaEngineSRC = \
		  Engine/Source/Renderer/Renderer.cpp \
		  Engine/Source/Renderer/Shader.cpp

all: libLuminaEngine.a

libLuminaEngine.a: $(LuminaEngineSRC:.cpp=.o)
	ar rcs $@ $^

.PHONY: clean
clean:
	find . -type f -iname "*.o" -exec rm "{}" \;

.PHONY: .clangd
.clangd:
	rm --force $@

	@echo Diagnostics: | tee --append $@
	@echo '  UnusedIncludes: Strict' | tee --append $@
	@echo '  MissingIncludes: Strict' | tee --append $@
	@echo CompileFlags: | tee --append $@
	@echo '  Add:' | tee --append $@

	@for flag in $(CXXFLAGS) ; do echo "    - $$flag" | tee --append $@ ; done
