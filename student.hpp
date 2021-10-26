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

class DomesticStudent : public Student {
public:
	//constructors
	DomesticStudent() {}
	DomesticStudent(string _firstName, string _lastName, float _cgpa, int _researchScore, int _appID) {}

	//get,set province
	string getProvince();
	void setProvince(string newProvince);

private:
	string province;
};

class InternationalStudent : public Student {
public:
	InternationalStudent() {}
	InternationalStudent(string _firstName, string _lastName, float _cgpa, int _researchScore, int _appID) {}

	//get,set country
	string getCountry();
	void setCountry(string newCountry);

	//get,set toefl
	ToeflScore getToefl();
	void setToefl(ToeflScore newToefl);

private:
	string country;
	ToeflScore toefl;
};

class ToeflScore {
public:
	ToeflScore(){}
	ToeflScore(int _reading, int _listening, int _speaking, int _writing){}


	//get,set functions			//set functions are bool, as 0 <= (new value) <= 30
	int getReading();
	bool setReading(int newReading);

	int getListening();
	bool setListening(int newListening);

	int getSpeaking();
	bool setSpeaking(int newSpeaking);

	int getWriting();
	bool setWriting(int newWriting);

	int getTotalScore();
	void setTotalScore();		//total score is the sum of all fields
								//therefore, this function sets total score
								//to the current sum of all fields

private:
	int reading = 0;
	int listening = 0;
	int speaking = 0;
	int writing = 0;
	int totalScore = 0;
};
