//
// Created by halone on 10.08.2023.
//

#include "baseliving.h"

ushort aue::BaseLiving::get_entrance_count() const{
    return this->entrance_count;
}

ushort aue::BaseLiving::get_flat_on_floor() const{
    return this->flat_on_floor;
}

ushort aue::BaseLiving::get_floors_count() const {
    return this->floor_count;
}

object_type& aue::BaseLiving::get_object_type() const {
    return living_object;
}

uint aue::BaseLiving::get_max_living() const {
    return max_living;
}

