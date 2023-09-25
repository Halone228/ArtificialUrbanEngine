//
// Created by halone on 13.07.2023.
//

#include "eventloop.h"

namespace aue{
    template<typename _T>
    std::optional<_T> Event::get_by_name(std::string name) {
        if(data[name].type() == typeid(_T)) return {any_cast<_T>(data[name])};
        return std::nullopt;
    }

    subscriber_id_type EventLoop::add_subscriber(aue::descriptor_type desc, aue::func_type func) {
        subscribers[desc].push_front(func);
        auto sub = subscribers[desc].begin();
        auto generated = id_counter++;
        id_table[generated] = sub;
        return generated;
    }

    void EventLoop::push_event(aue::Event &event) {
        event_queue.push_back(event);
    }

    bool EventLoop::is_queue_empty() {
        return event_queue.empty();
    }

    AnswerCodes EventLoop::remove_subscriber(aue::subscriber_id_type id, descriptor_type desc) {
        if(id_table.find(id) == id_table.end()) return AnswerCodes::NOT_FOUND;

        auto iter = id_table[id];
        subscribers[desc].erase(iter);
        (void)id_table.erase(id);

        return AnswerCodes::OK;
    }

    void EventLoop::process_queue() {
        auto process_size = event_queue.size();
        for(size_t i = 0; i<process_size; i++){
            auto event = event_queue.back(); event_queue.pop_back();
            for(auto& func : subscribers[event.event_descriptor]){
                start_worker(func, event);
            }
        }
    }

    void EventLoop::start_worker(const aue::func_type& worker, aue::Event &event) {
        worker(event);
    }
}