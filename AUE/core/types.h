//
// Created by halon on 22.08.2023.
//

#ifndef AUE_TYPES_H
#define AUE_TYPES_H
#include <cstdlib>
#include "boost/uuid/uuid.hpp"
#include "BaseWorld/point.h"
#include "vector"
using table_id_t = unsigned int;
using id_t = unsigned int;
using object_type = unsigned short;
using object_uuid_t = boost::uuids::uuid;
using shape_type = std::vector<aue::Point2D>;
using ushort = unsigned short;
using uint = unsigned int;

#endif //AUE_TYPES_H
