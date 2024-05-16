#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "music.h"
void music::read_command(){
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
            if(in!="artists" && in!="title" && in!="genre" && in!="year"){
            	file<<"Search "<<real<<" in "<<in<<std::endl; 
                file<<"Exception: command is wrong\n";

            }
            else {
                if(in=="title"){
                for(int i=0;i<data.size();i++){
                    if(data[i].artists!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!=""){
                        std::cout<<"i:"<<i<<std::endl;
                    for(int z=0;z<data[i].title.size();z++) {  
                        for(int k=count;k<real.size();k++){
                            if(data[i].title[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" title"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].artists<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<std::endl;;
                            }
                            break;
                            }
                            else count=0;

                    }
            }
        }
              
              }
                }
                else if(in=="artists"){
                    count=0;
                    std::cout<<real;
                for(int i=0;i<data.size();i++){
                    if(data[i].artists!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="")
                    for(int z=0;z<data[i].artists.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].artists[z]==real[k]){
                                count++;
                                std::cout<<count<<std::endl;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" artists"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].artists<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<std::endl;
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
                        if(data[i].artists!="" && data[i].title!="" && data[i].year!=0 && data[i].genre!="")
                    for(int z=0;z<data[i].genre.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].genre[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" genre"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].artists<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<std::endl;
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
                std::sort(data.begin(), data.end(), [](const music& music1, const music& music2) {
        return music1.year < music2.year;
    });
                 for (const auto& music : data) {
                    if(music.artists!="" && music.title!="" && music.year!=0 && music.genre!="")
        file << music.title << '"' << music.artists<<'"' <<music.year<<'"'<<music.genre<< std::endl;
    }
            }
            else if(real=="title"){
                file<<"sort in title"<<std::endl;
                std::sort(data.begin(), data.end(), [](const music& music1, const music& music2) {
        return music1.title < music2.title;
    });
               for (const auto& music : data) {
                    if(music.artists!="" && music.title!="" && music.year!=0 && music.genre!="")
        file << music.title << '"' << music.artists<<'"' <<music.year<<'"'<<music.genre<< std::endl;
    } 
            }
            else if(real=="artists"){
                file<<"sort in authors"<<std::endl;
                std::sort(data.begin(), data.end(), [](const music& music1, const music& music2) {
        return music1.artists < music2.artists;
    });
               for (const auto& music : data) {
                   if(music.artists!="" && music.title!="" && music.year!=0 && music.genre!="")
        file << music.title << '"' << music.artists<<'"' <<music.year<<'"'<<music.genre<< std::endl;
            }
        }
        else if(real=="genre"){
            file<<"sort in title"<<std::endl;
                std::sort(data.begin(), data.end(), [](const music& music1, const music& music2) {
        return music1.genre < music2.genre;
    });
               for (const auto& music : data) {
                    if(music.artists!="" && music.title!="" && music.year!=0 && music.genre!="")
        file << music.title << '"' << music.artists<<'"' <<music.year<<'"'<<music.genre<< std::endl;
        }
        
    }
}
}
}

    out.close();
    file.close();
}
void music::read_data(){
    std::ifstream file("data.txt");
    std::string line;
    int count=0,k=0;
    std::string name="";
    std::string empty;
    file>>empty;
    std::vector<std::string> all;
    music new_data;
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
        new_data.artists=all[i++];
        if(all[i]==""){
            new_data.year=0;
            i++;
        }
        else new_data.year=std::stoi(all[i++]);
        new_data.genre=all[i++];
        data.push_back(new_data);
    }
}
music::music() {
    title="";
    artists="";
    year=0;
    genre="";
}
void music::write_file(){
    std::ofstream file("out.txt", std::ios::out | std::ios::app);
    file<<"Catalog Read:music\n";
    for(int i=0;i<data.size();i++){
        if(data[i].artists=="" || data[i].title=="" || data[i].year==0 || data[i].genre==""){
            file<<"Exception: duplicate entry\n";
            file<<'"'<<data[i].title<<'"'<<data[i].artists<<'"'<<data[i].year<<'"'<<data[i].genre<<'"'<<std::endl;
        }
    }
    file.close();

}