#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "catalog.h"
#include "book.h"
#include "movie.h"
#include "music.h"


int main(int argc, char const* argv[]) {
    std::string data;
    std::ifstream file("data.txt");
    if (file.is_open()) {
        file >> data;
        if (data == "book") {
            catalog<book>* books = new book();
            books->read_data();
            books->write_file();
            books->read_command();
            delete books; // Belleği serbest bırakmak için delete kullanın
        } else if (data == "music") {
            catalog<music>* musics = new music();
            musics->read_data();
            musics->write_file();
            musics->read_command();
            delete musics; // Belleği serbest bırakmak için delete kullanın
        } else if (data == "movie") {
            catalog<movie>* movies = new movie();
            movies->read_data();
            movies->write_file();
            movies->read_command();
            delete movies; // Belleği serbest bırakmak için delete kullanın
        }
    }

    return 0;
}