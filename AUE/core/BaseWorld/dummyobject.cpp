//
// Created by halon on 23.08.2023.
//

#include "dummyobject.h"
#include "../BaseModels/baseregisters.h"
namespace aue {
    DummyObject::DummyObject(aue::Point2D position, table_id_t obj) {
        this->position = position;
        this->parent_id = obj;
    }

    Point2D DummyObject::get_pos() const {
        return position;
    }

    shape_type DummyObject::get_shape() const {
        auto i = ObjectRegister::get_object(parent_id);
        if(i != nullptr) return i->get_shape();
    }

    DummyObject* DummyObject::create(Point2D pos, table_id_t obj) {
        return new DummyObject{pos, obj};
    }
}