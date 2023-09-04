//
// Created by halone on 13.07.2023.
//

#ifndef AUE_EVENTLOOP_H
#define AUE_EVENTLOOP_H
#include "map"
#include "string"
#include "any"
#include "queue"
#include "functional"
#include "list"
#include "../constants.h"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "optional"
namespace aue {
    typedef std::string descriptor_type;
    struct Event {
        descriptor_type event_descriptor;
        std::map<std::string, std::any> data;
        template<typename _T> std::optional<_T> get_by_name(std::string name);
    };
    typedef std::function<void(Event)> func_type;
    typedef boost::uuids::uuid subscriber_id_type;
    class EventLoop {
    private:
        static std::list<Event> event_queue;
        static std::map<descriptor_type, std::list<func_type>> subscribers;
        static std::map<subscriber_id_type, std::list<func_type>::iterator> id_table;
    public:
        static subscriber_id_type add_subscriber(descriptor_type desc, func_type func);
        static void push_event(Event& event);
        static AnswerCodes remove_subscriber(subscriber_id_type id, descriptor_type desc);
        static void start_worker(const func_type& worker, Event& event);
        static void process_queue();
        static bool is_queue_empty();
    };
}
#endif //AUE_EVENTLOOP_H
