#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "catalog.h"

class book : public catalog<book> {
private:
    std::string authors;
    std::string title;
    int year;
    std::string tags;

public:
    book();
    void read_data() override;
    void write_file() override;
    void read_command() override;
};
#endif