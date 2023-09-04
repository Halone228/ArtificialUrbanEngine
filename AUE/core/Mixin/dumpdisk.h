//
// Created by halone on 17.07.2023.
//

#ifndef AUE_DUMPDISK_H
#define AUE_DUMPDISK_H
#include "boost/filesystem.hpp"
#include "optional"
class DumpDiskMixin{
public:
    virtual void save(boost::filesystem::path save_directory) = 0;
    virtual void load(boost::filesystem::path save_directory) = 0;
};
#endif //AUE_DUMPDISK_H
