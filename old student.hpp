//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student {
public:
	
	//constructors
	Student() {}
	Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _appID) {}

	//get,set firstName
	string getFirstName() {}
	void setFirstName(string newFirstName) {}

	//get,set lastName
	string getLastName() {}
	void setLastName(string newLastName) {}

	//get,set cgpa
	float getCGPA() {}
	void setCGPA(float newCGPA) {}

	//get,set researchScore
	int getResearchScore() {}
	void setResearchScore(int newResearchScore) {}

	//get,set applicationID
	int getApplicationID() {}
	void setApplicationID(int newApplicationID) {}

	//friend "compare" functions (CGPA, ResearchScore, FirstName, LastName)
	friend string compareCGPA(const Student& stu1, const Student& stu2){}

	friend string compareResearchScore(const Student& stu1, const Student& stu2) {}

	friend string compareFirstName(const Student& stu1, const Student& stu2) {}

	friend string compareLastName(const Student& stu1, const Student& stu2) {}

private:
	string firstName;
	string lastName;
	float cgpa;
	int researchScore;
	int applicationID;
};
