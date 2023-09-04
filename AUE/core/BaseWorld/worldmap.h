//
// Created by halone on 13.07.2023.
//

#ifndef AUE_WORLDMAP_H
#define AUE_WORLDMAP_H
#include "map"
#include "point.h"
#include "dummyobject.h"
#include "../constants.h"
#include "../Mixin/dumpdisk.h"
#include "routesmap.h"

namespace aue {
    typedef DummyObject* WObject;
    typedef aue::Point2D pos_t;
    class WorldMap : public DumpDiskMixin, public RoutesMap{
    private:
        std::map<pos_t, WObject> map2D;
        const std::string name;
    public:
        explicit WorldMap(std::string name) : name(std::move(name)){};
        [[nodiscard]] std::string get_name() const;
        WObject getObjectByPos(pos_t);
        AnswerCodes addObject(WObject object);
        [[nodiscard]] std::vector<WObject> getObjectsInSquare(pos_t left_down_point, pos_t right_up_point) const;
        void load(boost::filesystem::path save_directory) override;
        void save(boost::filesystem::path save_directory) override;
    };
}

#endif //AUE_WORLDMAP_H
