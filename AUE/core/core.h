//
// Created by halon on 01.09.2023.
//

#ifndef AUE_CORE_H
#define AUE_CORE_H
#include "BaseWorld/worldmap.h"
#include "Metrics/basemetric.h"
#include "BaseModels/Routes/baseroute.h"

namespace aue {
    class Core {
    protected:
        WorldMap map;
        std::vector<BaseMetric*>* all_metrics = &metrics_register;
    public:
        AnswerCodes place_object(table_id_t obj, Point2D pos);
        AnswerCodes place_route(route_id_t route, Point2D start, Point2D end);
        WorldMap* get_map();
        std::vector<problem_t> get_metrics();
        Core() : map("base"){};
    };
}

#endif //AUE_CORE_H
