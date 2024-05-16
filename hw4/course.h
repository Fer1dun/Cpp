#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "student.h"
namespace PA4{
class student;
class course{
		private:
			std::string name;
			std::string code;
		public:
			student*students;
			int total;
			course();
			course(std::string Name,std::string Code);
			~course();
			std::string get_code()const;
			std::string get_name()const;
			void set_code(std::string Code);
			void set_name(std::string Name);
			void add_course(std::string stu_name,std::string code,course * &new_course,int current_course)const;
			void delete_course(std::string name,std::string code,course * &del_course,int current_course)const;
			void list_all_course(const course *all_course,int current_course);
			void list_student_registerd_course(course &total_course);
	};
}

#endif