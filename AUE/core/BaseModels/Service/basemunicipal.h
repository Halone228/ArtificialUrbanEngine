//
// Created by halone on 10.08.2023.
//

#ifndef AUE_BASEMUNICIPAL_H
#define AUE_BASEMUNICIPAL_H
#include "../baseobject.h"
#include "string"
#include "vector"
#include "../Living/baseliving.h"
#include "../../BaseWorld/worldmap.h"
#include "../../helpers.h"

namespace aue{
    class BaseMunicipal;
    static std::map<uint, std::vector<DummyObject*>> checked_objs;
    static std::map<uint, std::vector<DummyObject*>> checked_by;
    typedef std::string service_type;
    class BaseMunicipal : public BaseObject {
    protected:
        const uint max_employees;
        const uint radius;
        const service_type serviceType;
    public:
        [[nodiscard]] service_type get_service_type() const { return serviceType; };
        BaseMunicipal(const shape_type& shape, uint employees, uint radius, object_uuid_t uuid, service_type s_t) :
        BaseObject(shape, uuid), max_employees(employees), radius(radius), serviceType(s_t){};
        void on_built(aue::DummyObject obj, aue::WorldMap map) const override {};
        [[nodiscard]] uint get_max_employees() const { return max_employees; }
        [[nodiscard]] object_type& get_object_type() const override;
        ~BaseMunicipal() override = default;
    };
}

#endif //AUE_BASEMUNICIPAL_H
