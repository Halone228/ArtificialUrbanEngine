//
// Created by halon on 03.09.2023.
//

#include "baseregisters.h"

namespace aue {
    ushort TypesManager::new_type(aue::Type &new_type) {
        if (unique_to_id.find(new_type.unique_name) != unique_to_id.end()) return unique_to_id[new_type.unique_name];
        ushort num = counter++;
        unique_to_id[new_type.unique_name] = num;
        types[num] = new_type;
        return num;
    }

    Type TypesManager::get_type(ushort id) {
        return types[id];
    }
}
