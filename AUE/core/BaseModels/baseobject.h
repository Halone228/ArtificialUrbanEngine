// Created by halone on 13.07.2023.
//

#ifndef AUE_BASEOBJECT_H
#define AUE_BASEOBJECT_H

#include <map>
#include <string>
#include "../types.h"
#include "../helpers.h"
#include "../BaseWorld/worldmap.h"
#include "baseregisters.h"
#include "../Mixin/uuid_obj.h"

namespace aue {
    static object_type object_counter;
    static object_type living_object = object_counter++;
    static object_type municipal_object = object_counter++;
    class BaseObject;
    static GenericRegister<BaseObject> ObjectRegister;
    class DummyObject;
    class BaseObject : public UUIDMixin{
    protected:
        const object_uuid_t object_id;
        table_id_t id;
        const shape_type shape_points;
    public:
        BaseObject() : object_id(), shape_points(){};
        explicit BaseObject(shape_type shape, object_uuid_t id);
        [[nodiscard]] object_uuid_t get_uuid() const override{return object_id;};
        [[nodiscard]] virtual object_type& get_object_type() const = 0;
        virtual void on_built(DummyObject obj, WorldMap map) const = 0;
        virtual ~BaseObject() = default;
        [[nodiscard]] table_id_t get_table_id() const;
        [[nodiscard]] shape_type get_shape() const;
    };
}
#endif //AUE_BASEOBJECT_H
