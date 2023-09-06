//
// Created by halone on 13.07.2023.
//

#ifndef AUENGINE_MAIN_H
#define AUENGINE_MAIN_H
#include "boost/uuid/random_generator.hpp"
#include "../core/BaseModels/Living/baseliving.h"
#include "../core/BaseWorld/point.h"
auto new_1 = aue::BaseLiving{
    boost::uuids::random_generator()(),
    {aue::Point2D(1,1), aue::Point2D(-1,1), aue::Point2D(0,1)},
    2,
    4,
    2,
    2*4*2*2
};
#endif //AUENGINE_MAIN_H
