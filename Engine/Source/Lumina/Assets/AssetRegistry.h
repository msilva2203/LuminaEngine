#ifndef ASSET_REGISTRY_H
#define ASSET_REGISTRY_H

#pragma once

#include "Asset.h"

#include <unordered_map>
#include <iterator>

namespace Lumina {

    /**
     * Maps each asset with the corresponding metadata
     */
    class LUMINA_API AssetRegistry
    {
        using Iterator = std::unordered_map<AssetHandle, Asset::Metadata>::iterator;
        using ConstIterator = std::unordered_map<AssetHandle, Asset::Metadata>::const_iterator;
    public:
        size_t Num() const;
        bool Contains(AssetHandle Handle) const;
        void Clear();

        Asset::Metadata& Get(const AssetHandle Handle);
        const Asset::Metadata& Get(const AssetHandle Handle) const;

        Iterator begin() { return this->Registry.begin(); }
        Iterator end() { return this->Registry.end(); }
        ConstIterator begin() const { return this->Registry.cbegin(); }
        ConstIterator end() const { return this->Registry.cend(); }

    private:
        std::unordered_map<AssetHandle, Asset::Metadata> Registry;
    };

}

#endif ASSET_REGISTRY_H