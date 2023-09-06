//
// Created by halon on 01.09.2023.
//

#include "routesmap.h"

namespace aue {
    void RoutesMap::add_route(aue::Point2D from, aue::Point2D to, const aue::BaseRoute *route) {
        route_map[{from, to}] = route->get_side_capacity(0);
        route_map[{to, from}] = route->get_side_capacity(1);
        points.insert(from); points.insert(to);
    }

    route_map_t RoutesMap::get_route_map() const {
        return route_map;
    }

    Point2D RoutesMap::find_closest_point(aue::Point2D point) {
        if(points.empty()) return {};
        long double min_dist = std::numeric_limits<long double>::max();
        Point2D min_point{};
        for(auto& i : points){
            auto dist = i.get_sqr_dist(point);
            if(dist < min_dist) {
                min_dist = dist;
                min_point = i;
            }
        }
        return min_point;
    }
}