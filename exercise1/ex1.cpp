
#include "linked_list.cpp"
#include <iostream>
#include <random>
using namespace std;

// get the users input for the size of the list L
int userInput() {   
    int userValue;
    bool validValue = false;
    cout << "Enter the size of the list: ";
    do {
        cin >> userValue;
        if (userValue > 0) {
            validValue = true;
        } else {
            cout << "Error: Invalid value" << endl;
            cout << "Enter the size of the list: ";
        }
    } while (!validValue);  //Requests a value until a valid one is given (only works with negative values)
    return userValue;
}

int main() {
    int listSize = userInput(); 
    linked_list<int> L; 
    linked_list<int> histogram; 
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 9);
    int randomInt;
    for (int i=0; i < listSize; i++) { //Fills the L with "random" integers
        randomInt = distribution(generator);
        push_back(L, randomInt);  
    }
    print_list(L, false);

    int histogramSize = 0;
    // Fills the list histogram with the neccessary data
    for (int i=0; i < listSize; i++) {
        int currentNodeValue = accessNum(L, i);
        if (search(histogram, currentNodeValue) == -1) {
            push_back(histogram, currentNodeValue);
            histogramSize++;
        } else {
            increaseNumCount(histogram, search(histogram, currentNodeValue));
        }
    }

    for (int i = 1; i < histogramSize; i++) {
        for (int j = histogramSize - 1; j > i; j--) {
            if (accessNum(histogram, j) < accessNum(histogram, j - 1)) {
                insert(histogram, j - 1, accessNum(histogram, j), accessNumCount(histogram, j));
                delete_item(histogram, j + 1);
            }
        }
    }
    print_list(histogram, true);
}
