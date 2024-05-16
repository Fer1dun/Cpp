#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "movie.h"



void movie::read_command(){
    std::ifstream out("commands.txt");
    std::string line2;
    std::string type;
    std::string type1;
    std::string type2;
    std::string type3;
    std::string real="";
    std::string in="";
    std::ofstream file("out.txt", std::ios::out | std::ios::app);
    int count=0;
    if(out.is_open()){
        while(out>>type){
        real="";
        in="";
        std::cout<<type<<std::endl;
        if(type=="search"){
            out>>type1;
            out>>type2;
            out>>type3;
            for(int x=0;x<type1.size()-2;x++){
                real+=type1[x+1];
            }
            for(int x=0;x<type3.size()-2;x++){
                in+=type3[x+1];
            }
            if(in!="director" && in!="title" && in!="genre" && in!="year" && in!="starring"){
                file<<"Search "<<real<<" in "<<in<<std::endl; 
                file<<"Exception: command is wrong\n";

            }
            else {
                if(in=="title"){
                for(int i=0;i<data.size();i++){
                    if(data[i].director!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="" && data[i].starring!=""){
                    for(int z=0;z<data[i].title.size();z++) {  
                        for(int k=count;k<real.size();k++){
                            if(data[i].title[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" title"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].director<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<data[i].starring<<std::endl;
                            }
                            break;
                            }
                            else count=0;

                    }
            }
        }
              
              }
                }
                else if(in=="director"){
                    count=0;
                    std::cout<<real;
                for(int i=0;i<data.size();i++){
                    if(data[i].starring!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="" && data[i].director!="")
                    for(int z=0;z<data[i].director.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].director[z]==real[k]){
                                count++;
                                std::cout<<count<<std::endl;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" director"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].director<<'"'<<data[i].year<<'"'<<data[i].genre<<" "<<data[i].starring<<std::endl;
                            }
                            break;
                            }
                            else count=0;
                    }
            }
              
              }

                }
                else if(in=="genre"){
                     for(int i=0;i<data.size();i++){
                        if(data[i].starring!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="" && data[i].director!="")
                    for(int z=0;z<data[i].genre.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].genre[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" genre"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].director<<'"'<<data[i].year<<'"'<<data[i].genre<<" "<<data[i].starring<<std::endl;
                            }
                            break;
                            }
                            else count=0;
                    }
            }
              
              }
                }
                else if(in=="starring"){
                    for(int i=0;i<data.size();i++){
                        if(data[i].starring!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="" && data[i].director!="")
                    for(int z=0;z<data[i].starring.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].starring[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" starring"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].director<<'"'<<data[i].year<<'"'<<data[i].genre<<" "<<data[i].starring<<std::endl;
                            }
                            break;
                            }
                            else count=0;
                    }
            }
              
              }
                }
            }

        }
        else if(type=="sort"){
            out>>type1;
            for(int x=0;x<type1.size()-2;x++){
                real+=type1[x+1];
            }
            if(real=="year"){
                file<<"sort in year"<<std::endl;
                std::sort(data.begin(), data.end(), [](const movie& movie1, const movie& movie2) {
        return movie1.year < movie2.year;
    });
                 for (const auto& movie : data) {
                    if(movie.director!="" && movie.title!="" && movie.year!=0 && movie.genre!="" && movie.starring!="")
        file << movie.title << '"' << movie.director<<'"' <<movie.year<<'"'<<movie.genre<<'"'<<movie.starring<<std::endl;
    }
            }
            else if(real=="title"){
                file<<"sort in title"<<std::endl;
                std::sort(data.begin(), data.end(), [](const movie& movie1, const movie& movie2) {
        return movie1.title < movie2.title;
    });
               for (const auto& movie : data) {
                    if(movie.director!="" && movie.title!="" && movie.year!=0 && movie.genre!="" && movie.starring!="")
        file << movie.title << '"' << movie.director<<'"'<<movie.year<<'"'<<movie.genre<<'"'<<movie.starring<<std::endl;
    } 
            }
            else if(real=="director"){
                file<<"sort in director"<<std::endl;
                std::sort(data.begin(), data.end(), [](const movie& movie1, const movie& movie2) {
        return movie1.director< movie2.director;
    });
               for (const auto& movie : data) {
                    if(movie.director!="" && movie.title!="" && movie.year!=0 && movie.genre!="" && movie.starring!="")
        file << movie.title << '"' << movie.director<<'"' <<movie.year<<'"'<<movie.genre<<'"'<<movie.starring<<std::endl;
            }
        }
        else if(real=="genre"){
            file<<"sort in genre"<<std::endl;
                std::sort(data.begin(), data.end(), [](const movie& movie1, const movie& movie2) {
        return movie1.genre < movie2.genre;
    });
               for (const auto& movie : data) {
                    if(movie.director!="" && movie.title!="" && movie.year!=0 && movie.genre!="" && movie.starring!="")
        file << movie.title << '"' << movie.director<<'"' <<movie.year<<'"'<<movie.genre<<'"'<<movie.starring<<std::endl;
        }
        
    }
    else if(real=="starring"){
        file<<"sort in starring"<<std::endl;
                std::sort(data.begin(), data.end(), [](const movie& movie1, const movie& movie2) {
        return movie1.starring < movie2.starring;
    });
               for (const auto& movie : data) {
                    if(movie.director!="" && movie.title!="" && movie.year!=0 && movie.genre!="" && movie.starring!="")
        file << movie.title << '"' << movie.director<<'"' <<movie.year<<'"'<<movie.genre<<'"'<<movie.starring<<std::endl;
        }

    }
}
}
}
    out.close();
    file.close();
}
void movie::read_data(){
    std::ifstream file("data.txt");
    std::string line;
    int count=0,k=0;
    std::string name="";
    std::string empty;
    file>>empty;
    std::vector<std::string> all;
    movie new_data;
    while(getline(file,line)){
        for(int i=0;i<line.size();i++){
            if(line!="")
            if(line[i]=='"'){
                count++;
            }
            else if(count%2==1){
                name+=line[i];
            }
            else {
                all.push_back(name);
                name="";
                k++;
            }
        }
    }
    file.close();
    for(int i=0;i<k;){
        new_data.title=all[i++];
        new_data.director=all[i++];
        if(all[i]==""){
            new_data.year=0;
            i++;
        }
        else new_data.year=std::stoi(all[i++]);
        new_data.genre=all[i++];
        new_data.starring=all[i++];
        data.push_back(new_data);
    }
}

movie::movie() {
    title="";
    director="";
    year=0;
    genre="";
    starring="";
}
void movie::write_file(){
std::ofstream file("out.txt", std::ios::out | std::ios::app);
    file<<"Catalog Read:movie\n";
    for(int i=0;i<data.size();i++){
        if(data[i].director=="" || data[i].title=="" || data[i].year==0 || data[i].genre=="" || data[i].starring==""){
            file<<"Exception: duplicate entry\n";
            file<<'"'<<data[i].title<<'"'<<data[i].director<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<data[i].starring<<std::endl;
        }
    }
    file.close();
}