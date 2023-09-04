//
// Created by halon on 03.09.2023.
//

#include "baseregisters.h"
namespace aue {
    ushort TypesManager::new_type(aue::Type& new_type) {
        if(unique_to_id.find(new_type.unique_name) != unique_to_id.end()) return unique_to_id[new_type.unique_name];
        ushort num = counter++;
        unique_to_id[new_type.unique_name] = num;
        types[num] = new_type;
        return num;
    }

    Type TypesManager::get_type(ushort id) {
        return types[id];
    }

    unsigned int ObjectRegister::register_object(BaseObject* obj) {
        for(auto& i : reg_table){
            if(i.second == obj) return i.first;
        }
        auto num = table_counter++;
        reg_table[num] = obj;
        return num;
    }

    BaseObject* ObjectRegister::get_object(unsigned int id) {
        auto item = reg_table.find(id);
        if(item == reg_table.end()){ return nullptr;}
        return item->second;
    }
}
