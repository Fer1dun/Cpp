#include <iostream>
#include <string>
#include <cctype>
#include "course.h"
#include "student.h"
namespace PA4{
course::course(){
	name="";
	code="";
	students=nullptr;
	total=0;
}
course::course(const std::string Name,const std::string Code){
	name=Name;
	code=Code;
}
course::~course(){
	if(students!=nullptr){
	delete [] students;
	students=nullptr;
	}
}
std::string course::get_code()const{
	return code;
}
void course::set_code(std::string Code){
	code=Code;
}
std::string course::get_name()const{
	return name;
}
void course::set_name(std::string Name){
	name=Name;
}

void course::add_course(std::string stu_name,std::string code,course * &new_course,int current_course)const{
	course *register_course=new course[current_course+1];
	for(int i=0;i<current_course;i++){
		register_course[i]=new_course[i];

	}
	register_course[current_course].set_name(stu_name);
	register_course[current_course].set_code(code);

	delete [] new_course;
	new_course=register_course;

}
void course::delete_course(std::string name,std::string code,course * &del_course,int current_course)const{
	course *register_course=new course[current_course-1];
	int k=0;
	for(int i=0;i<current_course;i++){
		if(del_course[i].name!=name && del_course[i].code!=code)
			register_course[k]=del_course[i];
		k++;
	}
	delete [] del_course;
	del_course=register_course;

}
void course::list_all_course(const course *all_course,int current_course){
	for(int i=0;i<current_course;i++){
		std::cout<<i+1<<":"<<all_course[i].code<<all_course[i].name<<std::endl;
	}
}
void course::list_student_registerd_course(course &total_course){
	for(int i=0;i<total_course.total;i++){
		std::cout<<i+1<<" "<<total_course.students->get_name()<<" "<<total_course.students->get_id()<<std::endl;
	}
}
}