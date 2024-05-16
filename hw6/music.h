#ifndef MUSIC_H
#define MUSIC_H
#include <string>
#include "catalog.h"

class music : public catalog<music> {
private:
    std::string title;
    std::string artists;
    int year;
    std::string genre;

public:
    music();
    void read_data() override;
    void write_file() override;
    void read_command() override;
};

#endif