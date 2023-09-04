//
// Created by halone on 10.08.2023.
//

#include "BaseMunicipal.h"


uint aue::BaseMunicipal::get_employees() const {
    return this->employees;
}

aue::AnswerCodes aue::BaseMunicipal::set_employees(uint employees) {
    if(this->max_employees < employees) return AnswerCodes::OUT_OF_BOUND;
    this->employees = employees;
    return AnswerCodes::OK;
}

object_type & aue::BaseMunicipal::get_object_type() const {
    return municipal_object;
}

