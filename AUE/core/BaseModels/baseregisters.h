//
// Created by halon on 03.09.2023.
//

#ifndef AUE_BASEREGISTERS_H
#define AUE_BASEREGISTERS_H
#include "string"
#include "map"
#include "../types.h"
#include "baseobject.h"
namespace aue {
    struct Type {
        std::string unique_name = "Not found";
        std::string info;
    };
    static ushort counter;
    static std::map<ushort, Type> types;
    static std::map<std::string, ushort> unique_to_id;
    class TypesManager {
    public:
        static ushort new_type(Type& new_type);

        static Type get_type(ushort id);
    };
    class BaseObject;
    using obj_ref = BaseObject*;
    static table_id_t table_counter;
    static std::map<unsigned int, obj_ref> reg_table;
    class ObjectRegister{
    public:
        static table_id_t register_object(obj_ref obj);
        static obj_ref get_object(table_id_t id);
    };
}
#endif //AUE_BASEREGISTERS_H
