#include <iostream>
#include <string>
#include <cctype>
#include "student.h"
#include "course.h"
namespace PA4{
student::student(){
	name="";
	id=0;
	courses=nullptr;
	num_courses=0;
}
student::student(const std::string Name,const int Id){
	name=Name;
	id=Id;
}
student::~student(){
	if(courses!=nullptr){
	delete [] courses;
	courses=nullptr;
	}
}
int student::get_id()const{
	return id;
}
void student::set_id(int Id){
	id=Id;
}
std::string student::get_name()const{
	return name;
}
void student::set_name(std::string Name){
	name=Name;
}
void student::add_student(std::string stu_name,int id,student * &new_student,int current_student)const{
	student *register_student=new student[current_student+1];
	for(int i=0;i<current_student;i++){
		register_student[i]=new_student[i];

	}
	register_student[current_student].set_name(stu_name);
	register_student[current_student].set_id(id);
	delete [] new_student;
	new_student=register_student;

}
void student::delete_student(std::string name,int id,student * &del_student,int current_student)const{
	student *register_student=new student[current_student-1];
	int k=0;
	for(int i=0;i<current_student;i++){
		if(del_student[i].name!=name && del_student[i].id!=id){
			register_student[k]=del_student[i];
			k++;
		}
	}
	delete [] del_student;
	del_student=register_student;

}
void student::list_all_student(const student *all_student,int current_size){
	for(int i=0;i<current_size;i++){
		std::cout<<i+1<<":"<<all_student[i].name<<std::endl;
	}

}
void student::add_student_to_course(course *&all_course,int current_course,int num_course,student &current_student){
	int choice;
    for(int i = 0; i < current_course; i++) {
        std::cout << i + 1 << ": " <<all_course[i].get_code()<<" "<<all_course[i].get_name() << std::endl;
    }
    std::cin >> choice;
    course *new_course = new course[num_course + 1];
    for(int i = 0; i < num_course; i++) {
        new_course[i] = current_student.courses[i];
    }
    new_course[num_course] = all_course[choice - 1];
    delete[] current_student.courses;
    current_student.courses = new_course;

    student *new_student = new student[all_course[choice-1].total + 1];
	for(int i = 0; i < all_course[choice-1].total; i++) {
    	new_student[i] = all_course[choice-1].students[i];
	}	
	new_student[ all_course[choice-1].total]=current_student;
    all_course[choice-1].total++;
    delete [] all_course[choice-1].students;
    all_course[choice-1].students=new_student;
}
void student::drop_course_from_student(student & current_student,int num_courses){
	for(int i=0;i<num_courses;i++){
		std::cout<<i+1<<" "<<current_student.courses[i].get_code()<<" "<<current_student.courses[i].get_name()<<std::endl;
	}
	course *new_course = new course[num_courses -1];
	int k=0,choice;
	std::cin>>choice;
	for(int i=1;i<num_courses+1;i++){
		if(i!=choice){
			new_course[k]=current_student.courses[i-1];
			k++;
		}
	}
	delete [] current_student.courses;
	current_student.courses=new_course;
		

}
}