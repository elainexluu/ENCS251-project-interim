// student.cpp to implement your classes
#include "student.hpp"

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

	out << "Name of Domestic student : " << p.applicationID - 20210000 << " is " <<  p.firstName << " " << p.lastName << endl;

	out << "His/Her CGPA " << " is " << p.cgpa << endl;

	out << "His/Her Research Score is " << p.researchScore << endl;

	out << "He/She is from Province: " << p.province << endl;



	return out;

}

ostream& operator<<(ostream& out, const InternationalStudent& p)
{

	out << "Name of International student : " << p.applicationID - 20210100 << " is " << p.firstName << " " << p.lastName << endl;

	out << "His/Her CGPA " << " is " << p.cgpa << endl;

	out << "His/Her Research Score is " << p.researchScore << endl;

	out << "He/She is from " << p.country << endl;

	return out;
}
