#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "book.h"


void book::read_command(){
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
            if(in!="authors" && in!="title" && in!="tags" && in!="year"){
                file<<"Search "<<real<<" in "<<in<<std::endl; 
                file<<"Exception: command is wrong\n";

            }
            else {
                if(in=="title"){
                for(int i=0;i<data.size();i++){
                    if(data[i].authors!="" && data[i].title!="" && data[i].year!=0 && data[i].tags!=""){
                        std::cout<<"i:"<<i<<std::endl;
                    for(int z=0;z<data[i].title.size();z++) {  
                        for(int k=count;k<real.size();k++){
                            if(data[i].title[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" title"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].authors<<'"'<<data[i].year<<'"'<<data[i].tags<<'"'<<std::endl;;
                            }
                            break;
                            }
                            else count=0;

                    }
            }
        }
              
              }
                }
                else if(in=="authors"){
                    count=0;
                    std::cout<<real;
                for(int i=0;i<data.size();i++){
                    if(data[i].authors!="" && data[i].title!="" && data[i].year!=0 && data[i].tags!="")
                    for(int z=0;z<data[i].authors.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].authors[z]==real[k]){
                                count++;
                                std::cout<<count<<std::endl;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" authors"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].authors<<'"'<<data[i].year<<'"'<<data[i].tags<<'"'<<std::endl;
                            }
                            break;
                            }
                            else count=0;
                    }
            }
              
              }

                }
                else if(in=="tags"){
                     for(int i=0;i<data.size();i++){
                        if(data[i].authors!="" && data[i].title!="" && data[i].year!=0 && data[i].tags!="")
                    for(int z=0;z<data[i].tags.size();z++) {
                        for(int k=count;k<real.size();k++){
                            if(data[i].tags[z]==real[k]){
                                count++;
                                if(count==real.size()){
                                file<<"Search "<<real<<"in "<<" tags"<<std::endl;
                                file<<'"'<<data[i].title<<'"'<<data[i].authors<<'"'<<data[i].year<<'"'<<data[i].tags<<'"'<<std::endl;
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
                std::sort(data.begin(), data.end(), [](const book& book1, const book& book2) {
        return book1.year < book2.year;
    });
                 for (const auto& book : data) {
                    if(book.authors!="" && book.title!="" && book.year!=0 && book.tags!="")
        file << book.title << '"' << book.authors<<'"' <<book.year<<'"'<<book.tags<< std::endl;
    }
            }
            else if(real=="title"){
                file<<"sort in title"<<std::endl;
                std::sort(data.begin(), data.end(), [](const book& book1, const book& book2) {
        return book1.title < book2.title;
    });
               for (const auto& book : data) {
                    if(book.authors!="" && book.title!="" && book.year!=0 && book.tags!="")
        file << book.title << '"' << book.authors<<'"' <<book.year<<'"'<<book.tags<< std::endl;
    } 
            }
            else if(real=="authors"){
                file<<"sort in authors"<<std::endl;
                std::sort(data.begin(), data.end(), [](const book& book1, const book& book2) {
        return book1.authors < book2.authors;
    });
               for (const auto& book : data) {
                    if(book.authors!="" && book.title!="" && book.year!=0 && book.tags!="")
        file << book.title << '"' << book.authors<<'"' <<book.year<<'"'<<book.tags<< std::endl;
            }
        }
        else if(real=="tags"){
            file<<"sort in title"<<std::endl;
                std::sort(data.begin(), data.end(), [](const book& book1, const book& book2) {
        return book1.tags < book2.tags;
    });
               for (const auto& book : data) {
                    if(book.authors!="" && book.title!="" && book.year!=0 && book.tags!="")
        file << book.title << '"' << book.authors<<'"' <<book.year<<'"'<<book.tags<< std::endl;
        }
        
    }
}
}
}

    out.close();
    file.close();
}
void book::write_file(){
    std::ofstream file("out.txt", std::ios::out | std::ios::app);
    file<<"Catalog Read:book\n";
    for(int i=0;i<data.size();i++){
        if(data[i].authors=="" || data[i].title=="" || data[i].year==0 || data[i].tags==""){
            file<<"Exception: duplicate entry\n";
            file<<'"'<<data[i].title<<'"'<<data[i].authors<<'"'<<data[i].year<<'"'<<data[i].tags<<'"'<<std::endl;
        }
    }
    file.close();
}
void book::read_data(){
    std::ifstream file("data.txt");
    std::string line;
    int count=0,k=0;
    std::string name;
    std::string empty;
    file>>empty;
    std::vector<std::string> all;
    book new_data;
    while(getline(file,line)){
        if(line!="")
        for(int i=0;i<line.size();i++){
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
        new_data.authors=all[i++];
        if(all[i]==""){
            new_data.year=0;
            i++;
        }
        else new_data.year=std::stoi(all[i++]);
        new_data.tags=all[i++];
        data.push_back(new_data);
    }
}
book::book(){
    title="";
    authors="";
    year=0;
    tags="";
}