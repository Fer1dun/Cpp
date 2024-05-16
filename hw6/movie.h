#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "catalog.h"

class movie : public catalog<movie>{
private:
    std::string title;
    std::string director;
    int year;
    std::string genre;
    std::string starring;
public:
    movie();
    void read_data() override;
    void write_file() override;
    void read_command() override;
};

#endif