#ifndef EDITOR_ASSET_MANAGER_H
#define EDITOR_ASSET_MANAGER_H

#pragma once

#include "Assets/AssetManager.h"
#include "Assets/AssetRegistry.h"

namespace Lumina {

    /**
     * Specialization of the asset manager to be used only in the editor
     */
    class LUMINA_API EditorAssetManager : public AssetManager
    {
    public:
        virtual TRef<Asset> GetAsset(AssetHandle Handle) const override;
        virtual bool IsAssetHandleValid(AssetHandle Handle) const override;
        virtual bool IsAssetLoaded(AssetHandle Handle) const override;

        const Asset::Metadata& GetAssetMetadata(AssetHandle Handle) const;

    private:
        // The editor asset manager contains an asset registry, keeping all metadata available
        AssetRegistry Registry;
    };

}

#endif /* EDITOR_ASSET_MANAGER_H */