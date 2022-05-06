
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

int main(int argc, char *argv[]) {
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

    // bubble sort list L
    for (int i = 1; i < listSize; i++) {
        for (int j = listSize - 1; j > i; j--) {
            if (access(L, j) < access(L, j - 1)) {
                insert(L, j - 1, access(L, j));
                delete_item(L, j + 1);
            }
        }
    }
    //print_list(L);
    
    // Fills the list histogram with the neccessary data
    for (int i=0; i < listSize; i++) {
        int currentNodeValue = access(L, i);
        if (search(histogram, currentNodeValue) == -1) {
            push_back(histogram, currentNodeValue);
        } else {
            increaseNumCount(histogram, search(histogram, currentNodeValue));
        }
    }
    print_list(histogram, true);
}
