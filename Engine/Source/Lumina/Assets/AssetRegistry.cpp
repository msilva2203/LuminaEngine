#include "AssetRegistry.h"

namespace Lumina {

    /**
     * Get the number of assets in the asset registry
     * @returns The number of elements in the asset registry
     */
    size_t AssetRegistry::Num() const
    {
        return this->Registry.size();
    }

    /**
     * Check if the asset registry contains the asset
     * @param Handle The handle of the asset
     * @returns True if the asset registry contains the asset, false otherwise
     */
    bool AssetRegistry::Contains(AssetHandle Handle) const
    {
        return (this->Registry.find(Handle) != this->Registry.end());
    }

    /**
     * Clear the asset registry
     */
    void AssetRegistry::Clear()
    {
        this->Registry.clear();
    }

    /**
     * Get the metadata of an asset
     * @param Handle The handle of the asset
     * @returns The metadata of the asset
     */
    Asset::Metadata& AssetRegistry::Get(const AssetHandle Handle)
    {
        return this->Registry.at(Handle);
    }

    /**
     * Get the metadata of an asset (const)
     * @param Handle The handle of the asset
     * @returns The metadata of the asset
     */
    const Asset::Metadata& AssetRegistry::Get(const AssetHandle Handle) const
    {
        return this->Registry.at(Handle);
    }

}