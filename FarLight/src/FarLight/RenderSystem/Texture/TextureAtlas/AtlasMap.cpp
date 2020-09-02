// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Texture/TextureAtlas/AtlasMap.h"
#include "FarLight/RenderSystem/Texture/TextureAtlas/AtlasTile.h"

namespace FarLight
{
    Ref<AtlasMap> AtlasMap::Create(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& distanceBetweenTilesInPixels) noexcept
    {
        FL_CORE_ASSERT(texture != nullptr, "Texture should be instanciated!");
        FL_CORE_ASSERT(tileSize.x > 0 && tileSize.x <= texture->GetWidth()
            && tileSize.y > 0 && tileSize.y <= texture->GetHeight(), "Tile size should be greater than 0 and less or equal to corresponding texture size!");
        FL_CORE_ASSERT(distanceBetweenTilesInPixels.x >= 0 && distanceBetweenTilesInPixels.x < texture->GetWidth()
            && distanceBetweenTilesInPixels.y >= 0 && distanceBetweenTilesInPixels.y < texture->GetHeight(), "Distance between tiles in pixels should be greater or equal to 0 and less than corresponding texture size!");

        return CreateRef<AtlasMap>(texture, tileSize, distanceBetweenTilesInPixels);
    }

    AtlasMap::AtlasMap(const Ref<Texture2D>& texture, const glm::vec2& tileSize, const glm::vec2& distanceBetweenTilesInPixels) noexcept
        : m_Texture(texture)
        , m_TileSize(tileSize)
        , m_DistanceBetweenTilesInPixels(distanceBetweenTilesInPixels)
    {
        FL_CORE_ASSERT(texture != nullptr, "Texture should be instanciated!");
        FL_CORE_ASSERT(tileSize.x > 0 && tileSize.x <= texture->GetWidth()
            && tileSize.y > 0 && tileSize.y <= texture->GetHeight(), "Tile size should be greater than 0 and less or equal to corresponding texture size!");
        FL_CORE_ASSERT(distanceBetweenTilesInPixels.x >= 0 && distanceBetweenTilesInPixels.x < texture->GetWidth()
            && distanceBetweenTilesInPixels.y >= 0 && distanceBetweenTilesInPixels.y < texture->GetHeight(), "Distance between tiles in pixels should be greater or equal to 0 and less than corresponding texture size!");

        for (unsigned y = 0; y * (distanceBetweenTilesInPixels.y + tileSize.y) < m_Texture->GetHeight(); ++y)
        {
            m_AtlasTiles.emplace_back();
            for (unsigned x = 0; x * (distanceBetweenTilesInPixels.x + tileSize.x) < m_Texture->GetWidth(); ++x)
            {
                m_AtlasTiles[y].emplace_back(glm::vec2(x, y));
            }
        }
    }

    const Ref<AtlasTile>& AtlasMap::GetAtlasTile(const glm::vec2& offset, const glm::vec2& sizeInTileUnits) noexcept
    {
        FL_CORE_ASSERT(offset.x >= 0 && offset.x < m_AtlasTiles.front().size()
            && offset.y >= 0 && offset.y < m_AtlasTiles.size(), "Texture with this offset doesn't exist!");
        FL_CORE_ASSERT(sizeInTileUnits.x > 0 && sizeInTileUnits.x <= m_AtlasTiles.front().size() - offset.x
            && sizeInTileUnits.y > 0 && sizeInTileUnits.y <= m_AtlasTiles.size() - offset.y, "Tile size on any axis should be greater than 0 and less or equal to current texture tile size minus corresponding offset!");

        if (m_AtlasTiles[offset.y][offset.x].SizeInTiles != sizeInTileUnits)
        {
            m_AtlasTiles[offset.y][offset.x].SizeInTiles = sizeInTileUnits;

            unsigned leftOffset = static_cast<unsigned>(offset.x * m_DistanceBetweenTilesInPixels.x);
            unsigned upOffset = static_cast<unsigned>(offset.y * m_DistanceBetweenTilesInPixels.y);

            std::array<glm::vec2, 4> textureCoords;

            // Lower left
            textureCoords[0] = { (leftOffset + offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + offset.y * m_TileSize.y) / m_Texture->GetHeight() };
            // Lower right
            textureCoords[1] = { (leftOffset + (offset.x + sizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + offset.y * m_TileSize.y) / m_Texture->GetHeight() };
            // UpperRight
            textureCoords[2] = { (leftOffset + (offset.x + sizeInTileUnits.x) * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (offset.y + sizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };
            // UpperLeft
            textureCoords[3] = { (leftOffset + offset.x * m_TileSize.x) / m_Texture->GetWidth(), (upOffset + (offset.y + sizeInTileUnits.y) * m_TileSize.y) / m_Texture->GetHeight() };

            m_AtlasTiles[offset.y][offset.x].Tile = CreateRef<AtlasTile>(this, std::move(textureCoords));
        }

        return m_AtlasTiles[offset.y][offset.x].Tile;
    }
}
