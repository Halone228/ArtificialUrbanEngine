//
// Created by halon on 08.09.2023.
//

#ifndef AUE_PYTHON_UUID_OBJ_H
#define AUE_PYTHON_UUID_OBJ_H
#include "../types.h"
class UUIDMixin{
public:
    virtual object_uuid_t get_uuid() const = 0;
};
#endif //AUE_PYTHON_UUID_OBJ_H
