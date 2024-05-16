#ifndef SCHOOLMANAGESYSTEM_H
#define SCHOOLMANAGESYSTEM_H
#include <string>
#include "student.h"
#include "course.h"
namespace PA4{
class course;
class student;
class schoolmanage{
		private:
			course*courses;
			student*students;
		public:
			schoolmanage();
			~schoolmanage();
			void menu();
	};
}
#endif