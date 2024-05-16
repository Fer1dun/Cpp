#ifndef CATALOG_H
#define CATALOG_H
#include <string>

template <typename T>
class catalog {
protected:
    std::vector<T> data;
public:
    catalog(){
    	
    }
    virtual void read_data() = 0;
    virtual void read_command()=0;
    virtual void write_file()=0;
};

#endif