#include <iostream>
#include <string>
#include <cctype>
#include "student.h"
#include "course.h"
#include "schoolmanagersystem.h"

namespace PA4{
schoolmanage::schoolmanage(){
	courses=nullptr;
	students=nullptr;
}
schoolmanage::~schoolmanage(){
	delete [] courses;
	delete [] students;
}
void schoolmanage::menu(){
	student *new_student=nullptr;
	course *new_course=nullptr;

	int choice=-1,choice2=-1,id,choice3=-1,choice4=-1,choice5=-1,current_student=0,current_course=0;
	std::string name,code,last_name,full_name;
	while(choice!=0){
		std::cout<<"0 exit\n 1 student \n 2 course\n 3 list all students\n 4 list all courses"<<std::endl;
		std::cin>>choice;
		std::cout<<"cho.:"<<choice;
		choice2=-1;
		if(choice==1){
			while(choice2!=0){
			std::cout<<"0 up \n 1 add student\n 2 select student "<<std::endl;
			std::cin>>choice2;
			if(choice2==1){
				std::cin>>name>>last_name>>id;
				full_name=name+" "+last_name;
				new_student->add_student(full_name,id,students,current_student);
				current_student++;
			}
			else if(choice2==2){
				std::cin>>name>>last_name>>id;
				choice3=-1;
				while(choice3!=0){
				std::cout<<"0 up\n 1 delete student\n 3 add selected student  to course\n 4 drop selected student from a course"<<std::endl;
				std::cin>>choice3;
				full_name=name+" "+last_name;
					if(choice3==1){
						new_student->delete_student(full_name,id,students,current_student);
						current_student--;
					}
					else if(choice3==3){
						for(int i=0;i<current_student;i++){
							if(full_name==students[i].get_name()){
								new_student->add_student_to_course(courses,current_course,students[i].num_courses,students[i]);
								students[i].num_courses++;
							}
						}
						

					}
					else if(choice3==4){
					for(int i=0;i<current_student;i++){
							if(full_name==students[i].get_name())
								new_student->drop_course_from_student(students[i],students[i].num_courses);
							students[i].num_courses--;
						}

					}
				}
			}
		}
		}
		else if(choice==2){
			choice4=-1;
			while(choice4!=0){
			std::cout<<"0 up \n 1 add course\n 2 select course "<<std::endl;
			std::cin>>choice4;
				if(choice4==1){
					std::cin>>code>>name>>last_name;
					full_name=name+" "+last_name;
					new_course->add_course(full_name,code,courses,current_course);
					current_course++;
				}
				else if(choice4==2){
					std::cin>>code>>name>>last_name;
					full_name=name+" "+last_name;
					choice5=-1;
					while(choice5!=0){
					std::cout<<"0 up\n 1 delete course\n 2 list_students_registered_to_the_selected_course"<<std::endl;
					std::cin>>choice5;
						if(choice5==1){
					new_course->delete_course(full_name,code,courses,current_course);
					current_course--;
					}
						else if(choice5==2){
							for(int i=0;i<current_course;i++){
								if(courses[i].get_name()==full_name){
							new_course->list_student_registerd_course(courses[i]);
							}
						}
						}
				}}
		}
	}
		else if(choice==3){
			new_student->list_all_student(students,current_student);
		}
		else if(choice==4){
			new_course->list_all_course(courses,current_course);

		}
	}
}
}