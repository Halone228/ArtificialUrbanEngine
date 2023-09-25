//
// Created by halon on 31.08.2023.
//

#ifndef AUE_BASEMETRIC_H
#define AUE_BASEMETRIC_H
#include "../BaseWorld/worldmap.h"
#include "../BaseModels/baseregisters.h"
#include "../EventLoop/eventloop.h"

namespace aue {
    enum StatusEnum{
        NO_PROBLEM, WARN, PROBLEM
    };
    typedef std::string problem_info_t;
    typedef std::pair<StatusEnum, problem_info_t> problem_t;
    class BaseMetric;
    static std::vector<BaseMetric*> metrics_register;
    class BaseMetric {
    protected:
        const std::string name;
    public:
        explicit BaseMetric(std::string& name) : name(name) {
            metrics_register.push_back(this);
            EventLoop::add_subscriber(
                "map_update",
                [this](Event& event){
                    auto map = event.get_by_name<WorldMap*>("map");
                    if(!map.has_value()) return;
                    this->update(map.value());
                }
            );
        }
        [[nodiscard]] virtual problem_t get_problems() = 0;
        virtual void update(WorldMap* map) = 0;
        [[nodiscard]] std::string get_name() const { return name; }
    };
}

#endif //AUE_BASEMETRIC_H
