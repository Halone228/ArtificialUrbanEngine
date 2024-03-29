//
// Created by halon on 03.09.2023.
//

#ifndef AUE_BASEREGISTERS_H
#define AUE_BASEREGISTERS_H

#include <utility>

#include "../Mixin/uuid_obj.h"
#include "../types.h"
#include "map"
#include "string"
#include "type_traits"

namespace aue {
    class Type {
    public:
        Type(std::string u_n, std::string info)
                : unique_name(std::move(u_n)), info(std::move(info)) {}

        Type() : unique_name("Not Found") {};
        std::string unique_name;
        std::string info;
    };

    static ushort counter;
    static std::map<ushort, Type> types;
    static std::map<std::string, ushort> unique_to_id;

    class TypesManager {
    public:
        static ushort new_type(Type &new_type);

        static Type get_type(ushort id);
    };

    template<class Registered>
    class GenericRegister {
        std::map<table_id_t, Registered *> container;
        table_id_t counter{};

    public:
        table_id_t register_object(Registered *obj) {
            for (auto &i: container) {
                if (i.second->get_uuid() == obj->get_uuid())
                    return i.first;
            }
            auto num = counter++;
            container[num] = obj;
            return num;
        }

        Registered *get_object(table_id_t id) {
            auto item = container.find(id);
            if (item == container.end()) {
                return nullptr;
            }
            return item->second;
        }

        std::vector<Registered *> get_all_objects() {
            std::vector<Registered *> result(container.size());
            auto iter = container.begin();
            for (int i = 0; i < container.size(); ++i) {
                result[i] = iter->second;
                i++;
            }
            return result;
        }
    };
} // namespace aue
#endif // AUE_BASEREGISTERS_H
