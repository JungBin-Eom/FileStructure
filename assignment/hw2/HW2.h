#include <vector>
#include <string>

using namespace std;

class Course
{
public:
	string CourseNumber;
	int CreditHour;
	string Grade;

	Course();
};

class Student
{
public:
	char StudentNumber[11];
	char Name[25];
	char Address[25];
	char Date[15];
	int Credit;
	//vector<Course> enrolledCourse;

	Student();
};
