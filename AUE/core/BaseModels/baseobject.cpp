//
// Created by halone on 13.07.2023.
//

#include "baseobject.h"
namespace aue {


    BaseObject::BaseObject(shape_type shape, object_uuid_t id) : shape_points(std::move(shape)), object_id(id)
    {
        this->id = ObjectRegister.register_object(this);
    }

    object_uuid_t BaseObject::getId() const {
        return object_id;
    }

    table_id_t BaseObject::get_table_id() const {
        return id;
    }

    shape_type BaseObject::get_shape() const {
        return shape_points;
    }
}
