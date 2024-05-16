#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "course.h"
namespace PA4{
class course;
class student{
		private:
			std::string name;
			int id;
			course*courses;
		public:
			int num_courses;
			student();
			student(std::string Name,int Id);
			~student();
			int get_id()const;
			std::string get_name()const;
			void set_id(int id);
			void set_name(std::string name);
			void delete_student(std::string name,int id,student * &del_student,int current_student)const;
			void add_student(std::string stu_name,int id,student * &new_student,int current_student)const;
			void list_all_student(const student *all_student,int current_size);
			void add_student_to_course(course *&all_course,int current_course,int num_course,student & current_student);
			void drop_course_from_student(student & current_student,int num_courses);
			
	};
}
#endif