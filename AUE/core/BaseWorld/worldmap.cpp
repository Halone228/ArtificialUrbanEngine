//
// Created by halone on 13.07.2023.
//

#include "worldmap.h"
namespace aue {
    WObject* WorldMap::getObjectByPos(pos_t position) {
        auto val = map2D.find(position);
        return val != map2D.end() ? &val->second : nullptr;
    }

    AnswerCodes WorldMap::addObject(WObject object) {
        if(map2D.find(object.get_pos()) != map2D.end()) return AnswerCodes::POSITION_ENGAGED;
        map2D[object.get_pos()] = object;
        return AnswerCodes::OK;
    }

    std::vector<const WObject*> WorldMap::getObjectsInSquare(aue::pos_t left_down_point, aue::pos_t right_up_point) const {
        auto left_iter = map2D.upper_bound(left_down_point);
        auto right_iter = map2D.lower_bound(right_up_point);
        std::vector<const WObject*> result;
        do {
            if(left_iter == map2D.end()) break;
            result.push_back(&left_iter->second);
            left_iter++;
        } while (left_iter != right_iter);
        return result;
    }

    void WorldMap::load(boost::filesystem::path save_directory) {

    }
    void WorldMap::save(boost::filesystem::path save_directory) {

    }

    std::string WorldMap::get_name() const {
        return name;
    }

    std::map<pos_t, WObject> WorldMap::get_raw_map() const {
        return map2D;
    }

    size_t WorldMap::get_objects_count() const {
        return map2D.size();
    }
}

