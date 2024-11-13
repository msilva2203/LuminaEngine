#ifndef ASSET_H
#define ASSET_H

#pragma once

#include "Utility/Types.h"

#include <string>

namespace Lumina {

    /**
     * Abstract class of an asset
     */
    class Asset
    {
    public:

        // TODO: Replace with an unique uniform id generated per asset
        using AssetHandle = uint64;

        /**
         * Represents the type of the asset
         * 
         * To be expanded in the future to allow more asset types
         */
        enum class EType : uint8
        {
            None,
            Level,
            Texture2D
            //...
        };

        /**
         * Structure of properties representing the metadata of an asset
         * Used primarily for debug purposes and should probably be stripped from distribution 
         */
        struct Metadata
        {
            Asset::EType Type;
            std::string FilePath; 
        };

        virtual Asset::EType GetAssetType() const = 0;

    private:
        AssetHandle Handle;

    };

    #define DECLARE_ASSET(Type) \
        static Asset::EType GetStaticAssetType() { return Asset::EType::Type; } \
        virtual Asset::EType GetAssetType() const override { return GetStaticAssetType(); } \

}

#endif /* ASSET_H */