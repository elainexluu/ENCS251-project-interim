//student.cpp to implement your classes
#include "student.hpp"

//constructors
Student::Student() {

}

Student::Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _applicationID) {
	setFirstName(_firstName);
	setLastName(_lastName);
	setCGPA(_cgpa);
	setResearchScore(_researchScore);
	setApplicationID(_applicationID);
}

//get,set firstName
string Student::getFirstName() {
	return this->firstName;
}

void Student::setFirstName(string newFirstName) {
	this->firstName = newFirstName;
}

//get,set lastName
string Student::getLastName() {
	return this->lastName;
}

void Student::setLastName(string newLastName) {
	this->lastName = newLastName;
}

//get,set cgpa
float Student::getCGPA() {
	return this->cgpa;
}

void Student::setCGPA(float newCGPA) {
	this->cgpa = newCGPA;
}

//get,set researchScore
int Student::getResearchScore() {
	return this->researchScore;
}

void Student::setResearchScore(int newResearchScore) {
	this->researchScore = newResearchScore;
}

//get,set applicationID
int Student::getApplicationID() {
	return this->applicationID;
}

void Student::setApplicationID(int newApplicationID) {
	this->applicationID = newApplicationID;
}



//friend "compare" functions (CGPA, ResearchScore, FirstName, LastName)
string compareCGPA(const Student& stu1, const Student& stu2) {
	
	//check if equal
	if (stu1.cgpa == stu2.cgpa) {
		return "=";
	}

	//check if stu1 is greater
	if (stu1.cgpa > stu2.cgpa) {
		return ">";
	}

	//check if stu1 is lesser
	if (stu1.cgpa < stu2.cgpa) {
		return "<";
	}
}

string compareResearchScore(const Student& stu1, const Student& stu2) {
	//check if equal
	if (stu1.researchScore == stu2.researchScore) {
		return "=";
	}

	//check if stu1 is greater
	if (stu1.researchScore > stu2.researchScore) {
		return ">";
	}

	//check if stu1 is lesser
	if (stu1.researchScore < stu2.researchScore) {
		return "<";
	}
}

string compareFirstName(const Student& stu1, const Student& stu2) {
	
	//convert to lowercase
	string name1;
	string name2;

	for (int i = 0; i < stu1.firstName.length(); i++) {
		name1 += tolower(stu1.firstName[i]);
	}
	for (int i = 0; i < stu2.firstName.length(); i++) {
		name2 += tolower(stu2.firstName[i]);
	}

	//find length
	int length;
	
	if (stu1.firstName.length() > stu2.firstName.length()) {
		length = stu1.firstName.length();
	}
	else if (stu1.firstName.length() < stu2.firstName.length()) {
		length = stu2.firstName.length();
	}
	else {
		length = stu1.firstName.length();
	}


	//check for alphabetical order
	for (int i = 0; i < length; i++) {
		
		//check characters if ">"
		if (name1[i] > name2[i]) {
			return ">";
		}
		
		//check characters if "<"
		if (name1[i] < name2[i]) {
			return "<";
		}

		//loop continues if the characters are the same
	}

	//if the program has reached this point, both names are identical up until 
	//the length of the shortest name
	
	//return ">", "<", or "=" depending on which name is the shortest
	if (stu1.firstName.length() > stu2.firstName.length()) {
		return ">";
	}
	else if (stu1.firstName.length() < stu2.firstName.length()) {
		return "<";
	}
	else {
		//if both have the same length, the names are identical
		return "=";
	}
	
}

string compareLastName(const Student& stu1, const Student& stu2) {
	//convert to lowercase
	string name1;
	string name2;

	for (int i = 0; i < stu1.lastName.length(); i++) {
		name1 += tolower(stu1.lastName[i]);
	}
	for (int i = 0; i < stu2.lastName.length(); i++) {
		name2 += tolower(stu2.lastName[i]);
	}

	//find length
	int length;

	if (stu1.lastName.length() > stu2.lastName.length()) {
		length = stu1.lastName.length();
	}
	else if (stu1.lastName.length() < stu2.lastName.length()) {
		length = stu2.lastName.length();
	}
	else {
		length = stu1.lastName.length();
	}


	//check for alphabetical order
	for (int i = 0; i < length; i++) {

		//check characters if ">"
		if (name1[i] > name2[i]) {
			return ">";
		}

		//check characters if "<"
		if (name1[i] < name2[i]) {
			return "<";
		}

		//loop continues if the characters are the same
	}

	//if the program has reached this point, both names are identical up until 
	//the length of the shortest name

	//return ">", "<", or "=" depending on which name is the shortest
	if (stu1.lastName.length() > stu2.lastName.length()) {
		return ">";
	}
	else if (stu1.lastName.length() < stu2.lastName.length()) {
		return "<";
	}
	else {
		//if both have the same length, the names are identical
		return "=";
	}
}
