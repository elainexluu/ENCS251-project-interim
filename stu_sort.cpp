//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"
#include "student.hpp"
#include <vector>

// OVERALL SORT FUNCTION -----------------------------------------------------------------------

// overall sort for domestic students

vector<DomesticStudent> overallSort(vector<DomesticStudent> const &intStudent) {    // pass by constant reference

        vector<DomesticStudent> v;

        int vecSize = static_cast<int>(intStudent.size());

        v = intStudent;

        quicksortV(v, 0, vecSize - 1);  // call to quicksort with indicies of the leftmost and rightmost elements

    return v;

}

// overall sort for international students

vector<InternationalStudent> overallSort(vector<InternationalStudent> const &intStudent) {    // pass by constant reference

    vector<InternationalStudent> v;

    v = intStudent;
    
    vector<InternationalStudent>::iterator itr = v.begin();
    
    while (itr != v.end()) {

        // checks if student does not meet required teofl scores
        int d = static_cast<int>(distance(v.begin(), itr));

        if ( !(compareToeflScore(v.at(d))) ) {
            
            itr = v.erase(itr);     // reject the student
        }

        // if it does then increment the iterator to move to the next student
        else {

            ++itr;
        }
    }
    
    quicksortV(v, 0, static_cast<int>(v.size() - 1));  // call to quicksort with indicies of the leftmost and rightmost elements

    return v;

}
