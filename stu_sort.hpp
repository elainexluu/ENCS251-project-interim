//header file stu_sort.hpp to declare your sorting functions
#include "student.hpp"
#include <string> //you will have to use string in C++
#include <vector>
#include <iterator>

// OVERALL SORT FUNCTION -----------------------------------------------------------------------

vector<DomesticStudent> overallSort(vector<DomesticStudent> const &intStudent);

vector<InternationalStudent> overallSort(vector<InternationalStudent> const &intStudent);

// using function templates so it sorts either DomesticStudent type or InternationalStudent type
// where T is a type parameter and can be replaced by any type

// swap function
template <typename T>
void swapV(T& student1, T& student2) {     // pass by reference
    T temp = student1;
    student1 = student2;
    student2 = temp;
}

// partition function
// chooses rightmost element as the pivot
// to reduce chance of worst case time complexity, could make it pick median of three as the pivot
template <typename T>
typename std::vector<T>::iterator partitionV(typename std::vector<T>& student, int indexOfLow, int indexOfHigh) {

    // setting the rightmost element (highest index) as the pivot
    typename std::vector<T>::iterator pivot;
    pivot = student.begin();
    advance(pivot, indexOfHigh);

    // creating the counter iterator to go through the vector
    typename std::vector<T>::iterator i;
    i = student.begin();
    advance(i, indexOfLow); // set it to the beginning of the elements

    for (int j = indexOfLow; j < indexOfHigh; j++) {

        // uses overloaded operator <= for corresponding type
        if (student.at(j) <= student.at(distance(student.begin(), pivot))) {

            // move all elements smaller than the pivot to the left of it
            swapV(student.at(distance(student.begin(), i)), student.at(j));

            i++;
        }
    }

    // move all elements larger than the pivot to the right of it
    swapV(student.at(distance(student.begin(), pivot)), student.at(distance(student.begin(), i)));

    return (i);
}

// quicksort function
template <typename T>
void quicksortV(typename std::vector<T>& student, int indexOfLow, int indexOfHigh) {

    // check that the part to sort is more than 1 element
    if (indexOfLow < indexOfHigh) {

        typename std::vector<T>::iterator partItr;

        // partition returns the iterator of the pivot after rearranging all smaller values \
            to the left of it and all larger values to the right of it
        partItr = partitionV(student, indexOfLow, indexOfHigh);

        // find the index corresponding to the iterator
        int partIndex = static_cast<int>(distance(student.begin(), partItr));

        // sorts before partition
        quicksortV(student, indexOfLow, partIndex - 1);

        // sorts after partition
        quicksortV(student, partIndex + 1, indexOfHigh);
    }
}

// note (if any confusion):
// distance(student.begin(), Itr) returns the distance (type long) between \
    the iterator at the beginning to the iterator at the given spot in the vector.
// i.e. distance(a, b) == b - a
// this is used to find the index that the iterator corresponds to
