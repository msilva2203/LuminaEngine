#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#pragma once

#include "Core/Core.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"

#include <map>

namespace Lumina {

    class LUMINA_API AssetManager
    {
    public:

    private:
        std::map<Asset::AssetHandle, TRef<Asset>> LoadedAssets;

    };

}

#endif /* ASSET_MANAGER */