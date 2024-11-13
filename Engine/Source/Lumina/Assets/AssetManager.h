#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#pragma once

#include "Core/Core.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"

#include <unordered_map>

namespace Lumina {

    /**
     * Abstract class of the asset manager, to be specialized in runtime and editor
     * 
     * Contains static functions that should be independent of current specialization
     */
    class LUMINA_API AssetManager
    {
    public:
        // These functions are to implemented per asset manager specialization
        virtual TRef<Asset> GetAsset(AssetHandle Handle) const = 0;
        virtual bool IsAssetHandleValid(AssetHandle Handle) const = 0;
        virtual bool IsAssetLoaded(AssetHandle Handle) const = 0;

    public:
        /**
         * Get the asset independently of current asset manager version (runtime or editor)
         * @param Handle The handle of the asset
         * @returns A reference to the asset, nullptr if invalid ref
         */
        template <typename T>
        static TRef<T> GetAsset(AssetHandle Handle)
        {
            TRef<Asset> OutAsset;
            LUMINA_CORE_ASSERT(OutAsset, "Unable to get asset");
            LUMINA_CORE_ASSERT(OutAsset->GetAssetType() == T::GetStaticAssetType(), "Asset is not of requested type");
            return static_pointer_cast<T>(OutAsset);
        }

    protected:
        std::unordered_map<AssetHandle, TRef<Asset>> LoadedAssets;

    };

}

#endif /* ASSET_MANAGER */