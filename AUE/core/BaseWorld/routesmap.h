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

typedef std::map<std::pair<aue::Point2D,aue::Point2D>, ushort> route_map_t;
namespace aue {
    class RoutesMap {
    protected:
        route_map_t route_map;
        std::set<Point2D> points;
    public:
        RoutesMap() : route_map(){};
        void add_route(Point2D from, Point2D to, const BaseRoute* route);
        Point2D find_closest_point(Point2D point);
        [[nodiscard]] route_map_t get_route_map() const;
    };
}

#endif //AUE_ROUTESMAP_H
