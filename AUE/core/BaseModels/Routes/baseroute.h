//
// Created by halon on 20.08.2023.
//

#ifndef AUE_BASEROUTE_H
#define AUE_BASEROUTE_H
#include <utility>
#include <vector>
#include <map>

#include "string"
#include "boost/uuid/uuid.hpp"
#include "tuple"
namespace aue {
    enum Directions{
        START_TO_END, END_TO_START, BIDIRECTIONAL
    };
    class BaseRoute;
    typedef boost::uuids::uuid route_uuid_t;
    typedef ushort route_id_t;
    typedef const ushort* route_lines;
    static ushort route_counter;
    static std::map<route_id_t, const BaseRoute*> route_register;
    class BaseRoute{
    private:
        const route_uuid_t uuid;
        const route_lines lines;
        const std::string name;
        const route_id_t id;
    public:
        BaseRoute(route_uuid_t uuid, route_lines lines, std::string name) : uuid(uuid),
        lines(lines), name(std::move(name)), id(route_counter++){
            route_register[id] = this;
        }
        [[nodiscard]] ushort get_side_capacity(size_t idx) const { return lines[idx]; }
        [[nodiscard]] std::string get_name() const { return name; }
        [[nodiscard]] route_uuid_t get_uid() const {return uuid; }
        [[nodiscard]] route_id_t get_id() const { return id; }
    };
}
#endif //AUE_BASEROUTE_H