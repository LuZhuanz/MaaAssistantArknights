#pragma once

#include "AbstractResource.h"
#include "AsstDef.h"

#include <memory>

namespace Map
{
    class TileCalc;
}

namespace asst
{
    class TilePack final : public AbstractResource
    {
    public:
        enum class BuildableType
        {
            Invaild = -1,
            None = 0,
            Melee = 1,
            Ranged = 2,
            All = 3
        };
        enum class HeightType
        {
            Invaild = -1,
            Highland = 0,
            Floor = 1
        };
        enum class TileKey
        {
            Invaild = -1,
            Forbidden,
            Wall,
            Road,
            Home,
            EnemyHome
        };

        struct TileInfo
        {
            BuildableType buildable = BuildableType::Invaild;
            HeightType height = HeightType::Invaild;
            TileKey key = TileKey::Invaild;
            Point pos;
        };
    public:
        using AbstractResource::AbstractResource;
        virtual ~TilePack();

        virtual bool load(const std::string& dir) override;

        std::vector<TileInfo> calc(const std::string& stage_code, bool side) const;

    private:
        std::shared_ptr<Map::TileCalc> m_tile_calculator = nullptr;
    };
}