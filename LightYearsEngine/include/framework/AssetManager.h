#pragma once
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

namespace ly
{
    class AssetManager
    {
    private:
        static unique<AssetManager> mAssetManager;
        Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
        std::string mRootDirectory;
    protected:
        AssetManager(/* args */);
    
    public:
        static AssetManager& Get();
        ~AssetManager();
        shared<sf::Texture> LoadTexture(const std::string& path);
        void CleanCycle();
        void SetAssetRootDirectoryPath(const std::string& directory);
    };
    

    
} // namespace ly
