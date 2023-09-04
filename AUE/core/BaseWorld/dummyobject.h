//
// Created by halon on 23.08.2023.
//

#ifndef AUE_DUMMYOBJECT_H
#define AUE_DUMMYOBJECT_H
#include "point.h"
#include "../types.h"
namespace aue{
    class DummyObject{
    protected:
        Point2D position;
        table_id_t parent_id;
    public:
        DummyObject(Point2D position, table_id_t obj);
        [[nodiscard]] shape_type get_shape() const;
        [[nodiscard]] Point2D get_pos() const;
        static DummyObject* create(Point2D pos, table_id_t obj);
    };
}
#endif //AUE_DUMMYOBJECT_H
