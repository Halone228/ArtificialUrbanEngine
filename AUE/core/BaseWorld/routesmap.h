//
// Created by halon on 01.09.2023.
//

#ifndef AUE_ROUTESMAP_H
#define AUE_ROUTESMAP_H
#include "map"
#include "vector"
#include "point.h"
#include "../BaseModels/Routes/baseroute.h"
#include "set"
#include "limits"

namespace aue {
    class RoutesMap {
    protected:
        std::map<std::pair<Point2D,Point2D>, ushort> route_map;
        std::set<Point2D> points;
    public:
        RoutesMap() : route_map(){};
        void add_route(Point2D from, Point2D to, const BaseRoute* route);
        Point2D find_closest_point(Point2D point);
    };
}

#endif //AUE_ROUTESMAP_H
