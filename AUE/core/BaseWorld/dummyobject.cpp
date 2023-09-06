//
// Created by halon on 23.08.2023.
//

#include "dummyobject.h"
namespace aue{
    DummyObject::DummyObject(aue::Point2D position, table_id_t obj) {
        this->position = position;
        this->parent_id = obj;
    }

    const Point2D& DummyObject::get_pos() const{
        return position;
    }

    DummyObject* DummyObject::create(Point2D pos, table_id_t obj) {
        return new DummyObject{pos, obj};
    }
}