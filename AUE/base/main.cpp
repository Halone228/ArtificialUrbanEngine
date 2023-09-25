//
// Created by halone on 13.07.2023.
//

#ifndef AUENGINE_MAIN_H
#define AUENGINE_MAIN_H
#include "boost/uuid/string_generator.hpp"
#include "../core/BaseModels/Living/baseliving.h"
#include "../core/BaseWorld/point.h"
#include "../core/Metrics/basemetric.h"
using namespace aue;
auto new_1 = aue::BaseLiving{
    boost::uuids::string_generator()("9c0a9603-05af-4842-a8f0-80b6d0d9f7b7"),
    {aue::Point2D(1,1), aue::Point2D(-1,1), aue::Point2D(0,1)},
    2,
    4,
    2,
    2*4*2*2
};
auto new_2 = aue::BaseLiving{
    boost::uuids::string_generator()("c52f0fa7-d805-43b7-9396-6e53324e07b5"),
    {aue::Point2D(1, 1), aue::Point2D(1, -1), aue::Point2D(-1, -1), aue::Point2D(-1, 1)},
    5, 4, 2, 5*4*2*2
};

class PlotnMetric : public BaseMetric{
public:
    long double plotnost{};
    PlotnMetric() : BaseMetric((std::string &) "plotnost"){}
    void update(WorldMap* map) override{
        auto raw_m = map->get_raw_map();
        uint sum{};
        uint max_x = 0;
        uint max_y = 0;
        uint min_x = UINT32_MAX;
        uint min_y = UINT32_MAX;
        for(auto& i : raw_m){
            if(i.second.get_id() == living_object){
                auto obj = (BaseLiving*) ObjectRegister.get_object(i.second.get_id());
                sum += obj->get_max_living();
                max_x = (max_x > i.second.get_pos().getX()) ? max_x : i.second.get_pos().getX();
                max_y = (max_y > i.second.get_pos().getY()) ? max_y : i.second.get_pos().getY();
                min_x = (min_x < i.second.get_pos().getX()) ? min_x : i.second.get_pos().getX();
                min_y = (min_y < i.second.get_pos().getY()) ? min_y : i.second.get_pos().getY();
            }
        }
        this->plotnost = double(sum)/double(((max_x-min_x)*(max_y-min_y)));
    }
    [[nodiscard]] problem_t get_problems() override {
        return {StatusEnum::NO_PROBLEM, std::to_string(plotnost)};
    }
};
#endif //AUENGINE_MAIN_H
