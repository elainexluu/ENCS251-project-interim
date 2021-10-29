// student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <vector>

//STUDENT FUNCTIONS ---------------------------------------------------------------------------

//constructors
Student::Student() {

}

Student::Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _applicationID) {
	//setFirstName(_firstName);

	firstName = _firstName;
	lastName = _lastName;
	cgpa = _cgpa;
	researchScore = _researchScore;
	applicationID = _applicationID;

	//setLastName(_lastName);
	//setCGPA(_cgpa);
	//setResearchScore(_researchScore);
	//setApplicationID(_applicationID);
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

//FRIEND COMPARE FUNCTIONS --------------------------------------------------------------------

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

	return "null";  // had to add to get rid of error
					// non-void function does not return a value in all control paths
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

	return "null";  // had to add to get rid of error
					// non-void function does not return a value in all control paths
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

			//cout << name1[i] << " " << name2[i];

			return "<";
		}

		//check characters if "<"
		if (name1[i] < name2[i]) {
			return ">";
		}

		//loop continues if the characters are the same
	}

	//if the program has reached this point, both names are identical up until 
	//the length of the shortest name

	//return ">", "<", or "=" depending on which name is the shortest
	if (stu1.firstName.length() > stu2.firstName.length()) {
		return "<";
	}
	else if (stu1.firstName.length() < stu2.firstName.length()) {
		return ">";
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
			return "<";
		}

		//check characters if "<"
		if (name1[i] < name2[i]) {
			return ">";
		}

		//loop continues if the characters are the same
	}

	//if the program has reached this point, both names are identical up until 
	//the length of the shortest name

	//return ">", "<", or "=" depending on which name is the shortest
	if (stu1.lastName.length() > stu2.lastName.length()) {
		return "<";
	}
	else if (stu1.lastName.length() < stu2.lastName.length()) {
		return ">";
	}
	else {
		//if both have the same length, the names are identical
		return "=";
	}

}

//DOMESTIC STUDENT FUNCTIONS ------------------------------------------------------------------

DomesticStudent::DomesticStudent() {

}

DomesticStudent::DomesticStudent(string _firstName, string _lastName, float _cgpa, int _researchScore, int _appID) : Student(_firstName, _lastName, _cgpa, _researchScore, _appID)
{


}

string DomesticStudent::getProvince() {
	return this->province;
}
void DomesticStudent::setProvince(string newProvince) {
	this->province = newProvince;
}


vector<DomesticStudent> sortDomesticStudents(vector<DomesticStudent> students, int option)
{
	DomesticStudent currentStudent;
	DomesticStudent nextStudent;

	int currentPlace = 0;
	bool anyChanges = true;

	while (anyChanges == true) {

		anyChanges = false;

		for (int i = 0; i < students.size() - 1; i++) {

			currentStudent = students[i];
			nextStudent = students[i + 1];

			//compare CGPA (option 1)
			if (option == 1 && compareCGPA(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getCGPA() << " < " << nextStudent.getCGPA() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare research score (option 2)
			if (option == 2 && compareResearchScore(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getResearchScore() << " < " << nextStudent.getResearchScore() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare first name (option 3)
			if (option == 3 && compareFirstName(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getFirstName() << " < " << nextStudent.getFirstName() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare last name (option 4)
			if (option == 4 && compareLastName(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getLastName() << " < " << nextStudent.getLastName() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}
		}
		//cout << "done loop" << anyChanges << endl;
	}




	//cout << "done" << endl;
	return students;
}

// overloaded < operator
// compares researchScore, cgpa, province for domestic students
bool operator <(const DomesticStudent& s1, const DomesticStudent& s2) {

	// convert provinces to lowercase
	// from compareFirstName and commpareLastName functions

	std::string province1;
	std::string province2;

	for (int i = 0; i < s1.province.length(); i++) {
		province1 += tolower(s1.province[i]);
	}

	for (int i = 0; i < s2.province.length(); i++) {
		province2 += tolower(s2.province[i]);
	}

	if (s2.researchScore < s1.researchScore) {
		return true;
	}
	else if ((s2.researchScore == s1.researchScore) && (s2.cgpa < s1.cgpa)) {
		return true;
	}
	else if (((s2.researchScore == s1.researchScore) && (s2.cgpa == s1.cgpa)) && (province1 < province2)) {
		return true;
	}
	else
		return false;

}

// overloaded <= operator
// compares researchScore, cgpa, province for domestic students
bool operator <=(const DomesticStudent& s1, const DomesticStudent& s2) {

	return !(s2 < s1);

}


//INTERNATIONAL STUDENT FUNCTIONS -------------------------------------------------------------


InternationalStudent::InternationalStudent() {

}

InternationalStudent::InternationalStudent(string _firstName, string _lastName, float _cgpa, int _researchScore, int _appID) : Student(_firstName, _lastName, _cgpa, _researchScore, _appID) {


}

string InternationalStudent::getCountry()
{
	return country;
}

void InternationalStudent::setCountry(string newCountry)
{

	country = newCountry;
}

ToeflScore InternationalStudent::getToefl()
{
	return toefl;
}

void InternationalStudent::setToefl(ToeflScore newToefl)
{

	toefl = newToefl;

}

// overloaded < operator
// compares researchScore, cgpa, country for international students
bool operator <(const InternationalStudent& s1, const InternationalStudent& s2) {

	// convert countries to lowercase
	// from compareFirstName and commpareLastName functions

	std::string country1;
	std::string country2;

	for (int i = 0; i < s1.country.length(); i++) {
		country1 += tolower(s1.country[i]);
	}

	for (int i = 0; i < s2.country.length(); i++) {
		country2 += tolower(s2.country[i]);
	}

	if (s2.researchScore < s1.researchScore) {
		return true;
	}
	else if ((s2.researchScore == s1.researchScore) && (s2.cgpa < s1.cgpa)) {
		return true;
	}
	else if (((s2.researchScore == s1.researchScore) && (s2.cgpa == s1.cgpa)) && (country1 < country2)) {
		return true;
	}
	else
		return false;
}

// overloaded <= operator
// compares researchScore, cgpa, country for international students
bool operator <=(const InternationalStudent& s1, const InternationalStudent& s2) {

	return !(s2 < s1);
}

// function to check if international students meet the minimum toefl requirements
bool compareToeflScore(const InternationalStudent &s) {

    ToeflScore t = s.toefl;

    t.setTotalScore();

    int total = t.getTotalScore();
    
    int read = t.getReading();
    
    int listen = t.getListening();
    
    int speak = t.getSpeaking();
    
    int write = t.getWriting();
    
    // check if the student's total toefl score is less than 93
    if ( (total < 93) )
    {
        return false;
    }
    
    if ((read < 20) || (listen < 20) || (speak < 20) || (write < 20)) {
        return false;
    }
    else {
        return true;
    }
    
}

//TOEFL SCORE FUNCTIONS -----------------------------------------------------------------------

ToeflScore::ToeflScore() {}
ToeflScore::ToeflScore(int _reading, int _listening, int _speaking, int _writing) {
	if (setReading(_reading) == false) {
		//give error message
	}
	if (setListening(_listening) == false) {
		//give error message
	}
	if (setSpeaking(_speaking) == false) {
		//give error message
	}
	if (setWriting(_writing) == false) {
		//give error message
	}
}

int ToeflScore::getReading() {
	return this->reading;
}

bool ToeflScore::setReading(int newReading) {
	if (newReading <= 30 && newReading >= 0) {
		this->reading = newReading;
		return true;
	}
	else {
		return false;
	}

}

int ToeflScore::getListening() {
	return this->listening;
}
bool ToeflScore::setListening(int newListening) {
	if (newListening <= 30 && newListening >= 0) {
		this->listening = newListening;
		return true;
	}
	else {
		return false;
	}
}

int ToeflScore::getSpeaking() {
	return this->speaking;
}
bool ToeflScore::setSpeaking(int newSpeaking) {
	if (newSpeaking <= 30 && newSpeaking >= 0) {
		this->speaking = newSpeaking;
		return true;
	}
	else {
		return false;
	}
}

int ToeflScore::getWriting() {
	return this->writing;
}
bool ToeflScore::setWriting(int newWriting) {
	if (newWriting <= 30 && newWriting >= 0) {
		this->writing = newWriting;
		return true;
	}
	else {
		return false;
	}
}

int ToeflScore::getTotalScore() {


	return this->totalScore;
}

void ToeflScore::setTotalScore() {
	this->totalScore = this->reading + this->listening + this->speaking + this->writing;

}

ostream& operator<<(ostream& out, const DomesticStudent& p)
{

	out << "Name of Domestic student: " << p.applicationID - 20210000 << ", is " << p.firstName << " " << p.lastName << endl;

	out << "Their CGPA " << " is " << p.cgpa << endl;

	out << "Their Research Score is " << p.researchScore << endl;

	out << "They are from Province: " << p.province << endl;



	return out;

}

ostream& operator<<(ostream& out, const InternationalStudent& p)
{

	ToeflScore t = p.toefl;

	t.setTotalScore();

	int x = t.getTotalScore();


	out << "Name of International student: " << p.applicationID - 20210100 << ", is " << p.firstName << " " << p.lastName << endl;

	out << "Their CGPA " << " is " << p.cgpa << endl;

	out << "Their Research Score is " << p.researchScore << endl;

	out << "They are from " << p.country << endl;

	out << "Their TOEFL total score is " << x << endl;


	return out;
}

vector<InternationalStudent> sortInternationalStudents(vector<InternationalStudent> students, int option)
{
	InternationalStudent currentStudent;
	InternationalStudent nextStudent;

	int currentPlace = 0;
	bool anyChanges = true;

	while (anyChanges == true) {

		anyChanges = false;

		for (int i = 0; i < students.size() - 1; i++) {

			currentStudent = students[i];
			nextStudent = students[i + 1];

			//compare CGPA (option 1)
			if (option == 1 && compareCGPA(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getCGPA() << " < " << nextStudent.getCGPA() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare research score (option 2)
			if (option == 2 && compareResearchScore(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getResearchScore() << " < " << nextStudent.getResearchScore() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare first name (option 3)
			if (option == 3 && compareFirstName(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getFirstName() << " < " << nextStudent.getFirstName() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}

			//compare last name (option 4)
			if (option == 4 && compareLastName(currentStudent, nextStudent) == "<") {

				//cout << i << ": " << currentStudent.getLastName() << " < " << nextStudent.getLastName() << endl;

				students[i] = nextStudent;
				students[i + 1] = currentStudent;

				anyChanges = true;
			}
		}
		//cout << "done loop" << anyChanges << endl;
	}




	//cout << "done" << endl;
	return students;
}
