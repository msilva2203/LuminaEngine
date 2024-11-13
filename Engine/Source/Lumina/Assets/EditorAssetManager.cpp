#include "EditorAssetManager.h"

namespace Lumina {

    /**
     * Get an asset from currently loaded assets, loading the asset if not loaded
     * @param Handle The handle of the requested asset
     * @returns A reference to the asset, nullptr if invalid
     */
    TRef<Asset> EditorAssetManager::GetAsset(AssetHandle Handle) const
    {
        if (!IsAssetHandleValid(Handle)) {
            return nullptr;
        }

        TRef<Asset> OutAsset;
        if (IsAssetLoaded(Handle)) {
            OutAsset = LoadedAssets.at(Handle);
        } else {
            // TODO: Load the asset

        }
        return OutAsset;
    }

    /**
     * Check if asset handle is valid, checking the asset registry in this specialization
     * @param Handle The handle of the asset
     * @returns True if the asset handle is valid, false otherwise
     */
    bool EditorAssetManager::IsAssetHandleValid(AssetHandle Handle) const
    {
        if (Handle == 0) {
            return false;
        }
        return Registry.Contains(Handle);
    }

    /**
     * Check if the asset is loaded into memory
     * @param Handle The handle of the asset
     * @returns True if the asset is loaded into memory, false otherwise
     */
    bool EditorAssetManager::IsAssetLoaded(AssetHandle Handle) const
    {
        return (LoadedAssets.find(Handle) != LoadedAssets.end());
    }

    /**
     * Get metadata from an asset
     * @param Handle The handle of the asset
     * @returns The metadata of the asset, of asset type None if asset is not found
     */
    const Asset::Metadata& EditorAssetManager::GetAssetMetadata(AssetHandle Handle) const
    {
        // Static initialization of empty metadata
        static Asset::Metadata EmptyMetadata;

        auto& RegistryMap = Registry.GetRegistry();
        auto Iterator = RegistryMap.find(Handle);
        if (Iterator == RegistryMap.end()) {
            return EmptyMetadata;
        }
        return Iterator->second;
    }

}