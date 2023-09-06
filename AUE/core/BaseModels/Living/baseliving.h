//
// Created by halone on 10.08.2023.
//

#ifndef AUE_BASELIVING_H
#define AUE_BASELIVING_H
#include "../baseobject.h"
#include "../Service/basemunicipal.h"

namespace aue{
    class BaseLiving : public BaseObject{
    protected:
        const ushort floor_count;
        const ushort flat_on_floor;
        const ushort entrance_count;
        const uint max_living;
    public:
        BaseLiving(object_uuid_t uuid, shape_type shape, ushort f_c, ushort f_n_f, ushort e_c, uint m_l)
        : BaseObject(shape, uuid),
        floor_count(f_c), flat_on_floor(f_n_f), entrance_count(e_c), max_living(m_l){};
        [[nodiscard]] uint get_max_living() const;
        [[nodiscard]] ushort get_floors_count() const;
        [[nodiscard]] ushort get_flat_on_floor() const;
        [[nodiscard]] ushort get_entrance_count() const;
        [[nodiscard]] object_type& get_object_type() const override;
        void on_built(aue::DummyObject obj, aue::WorldMap map) const override{};
    };
}

#endif //AUE_BASELIVING_H
