//
// Created by halon on 01.09.2023.
//

#include "core.h"
namespace aue {
    AnswerCodes Core::place_object(table_id_t obj, Point2D pos) {
        DummyObject new_object(pos, obj);
        return map.addObject(new_object);
    }

    AnswerCodes Core::place_route(table_id_t route, Point2D start, Point2D end) {
        map.add_route(start, end, RouteRegister.get_object(route));
        return AnswerCodes::OK;
    }

    WorldMap *Core::get_map() {
        return &map;
    }

    std::vector<problem_t> Core::get_metrics() {
        std::vector<problem_t> result(all_metrics->size());
        auto metrics_copy = *all_metrics;
        for(int i = 0; i<metrics_copy.size(); i++) {
            result[i] = metrics_copy[i]->get_problems();
        }
        return result;
    }
}