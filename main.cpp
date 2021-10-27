//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include "student.hpp"
#include "stu_sort.hpp"

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */

int main(){
  //Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */

  vector <DomesticStudent> domestic_students_vector;
  vector <DomesticStudent>::iterator it;

  int stu_count = 1;
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;
    int app_id = 20210000 + stu_count;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());


    DomesticStudent ds1(firstName, lastName, cgpa, researchScore, app_id);

    ds1.setProvince(province);

    it = domestic_students_vector.end();
    it = domestic_students_vector.insert(it, ds1);
    

    //print the student info to the screen
    cout << "Domestic student " << stu_count << " " << firstName << " " 
	 << lastName << " from " << province << " province has cgpa of "
	 << cgpa << ", and research score of " << researchScore << endl;

    stu_count++;
  }

  //close your file
  domesticFile.close();



  //Read the domestic-stu.txt file and exit if failed
  string line_i;
  ifstream internationalFile("international-stu.txt");
  if (!internationalFile.is_open()) {
      cout << "Unable to open file international-stu.txt" << endl;
      return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(internationalFile, line_i);
  cout << "File format: " << line_i << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */


  vector <InternationalStudent> international_students_vector;
  vector <InternationalStudent>::iterator it_i;


  int stu_count_i = 1;
  while (getline(internationalFile, line_i)) {
      /*process each line, get each field separated by a comma.
       *We use istringstream to handle it.
       *Note in this example code here, we assume the file format
       *is perfect and do NOT handle error cases. We will leave the
       *error and exception handling of file format to Lab Assignment 4
       */
      istringstream ss_i(line_i);

      string FirstName, LastName, Country, CGPA, ResearchScore, Reading, Listening, Speaking, Writing;
      float cgpa_i;
      int researchScore_i;
      int reading;
      int listening;
      int speaking;
      int writing;
      int app_id_i = 20210100 + stu_count_i;


      //get firstName separated by comma
      getline(ss_i, FirstName, ',');

      //get lastName separated by comma
      getline(ss_i, LastName, ',');

      //get province separated by comma
      getline(ss_i, Country, ',');

      //get cpga separated by comma, and convert string to float
      getline(ss_i, CGPA, ',');
      cgpa_i = atof(CGPA.c_str());

      //get researchScore separated by comma, and convert it to int
      getline(ss_i, ResearchScore, ',');
      researchScore_i = atoi(ResearchScore.c_str());

      //get Reading separated by comma, and convert it to int
      getline(ss_i, Reading, ',');
      reading = atoi(Reading.c_str());

      //get Listening separated by comma, and convert it to int
      getline(ss_i, Listening, ',');
      listening = atoi(Listening.c_str());

      //get Speaking separated by comma, and convert it to int
      getline(ss_i, Speaking, ',');
      speaking = atoi(Speaking.c_str());

      //get Writing separated by comma, and convert it to int
      getline(ss_i, Writing, ',');
      writing = atoi(Writing.c_str());


      InternationalStudent is1(FirstName, LastName, cgpa_i, researchScore_i, app_id_i);

      is1.setCountry(Country);
      ToeflScore toefl1(reading, listening, speaking, writing);
      is1.setToefl(toefl1);

      it_i = international_students_vector.end();
      it_i = international_students_vector.insert(it_i, is1);

      //print the student info to the screen
      cout << "Internatinal student " << stu_count_i << " " << FirstName << " "
          << LastName << " from " << Country << " has cgpa of "
          << CGPA << ", and research score of " << ResearchScore << endl;

      stu_count_i++;
  }

  //close your file
  internationalFile.close();

  unsigned r = 0;

  
  cout << endl << domestic_students_vector.at(0);
  cout << endl << international_students_vector.at(0);



  
  
  return 0;

  
}
