#include "heap.cpp"
#include "iostream"
#include <random>
#include <functional>
#include <list>
#include <memory>

using namespace std;

// get the users input for the size of the heap
int userInput() {
    int userValue;
    bool validValue = false;
    cout << "Enter the size of the heap: ";
    do {
        cin >> userValue;
        if (userValue > 0) {
            validValue = true;
        } else {
            cout << "Error: Invalid value" << endl;
            cout << "Enter the size of the heap: ";
        }
    } while (!validValue);  //Requests a value until a valid one is given (only works with negative values)
    return userValue;
}

// Sums up all heap items from top to bottom
float HeapSum(int size, string type) {
    float sum;
    for (int i = 0; i < size - 1; i++) {
        sum = top(); // save the value of the root
        pop(type); // remove the root and replace it with the next one
        sum += top(); // add the pr
        ChangeTop(sum);
    }
    return top();
}

int main() {
    int N = userInput(); // get the users value and save it
    std::default_random_engine generator;
    std::chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);
    float* heap_min = new float[N]; // initialize heap_min
    for (int i = 0; i < N; i++) { // fill heap_min with random float numbers
        heap_min[i] = random_num() * 10000.0;
    }
    float* heap_max = new float[N]; // initialize heap_max
    for (int i = 0; i < N; i++) { // fill heap_max with the same random float values as heap_min  
        heap_max[i] = heap_min[i];
    }
    Initialize(heap_min, N, "heapMin"); // Turn the list heap_min into a min heap
    float heapMinSum = HeapSum(N, "heapMin");
    cout << "Summing up all numbers from the smallest to the largest results in: " << heapMinSum << endl;
    Initialize(heap_max, N, "heapMax"); // Turn the list heap_max into a max heap
    float heapMaxSum = HeapSum(N, "heapMax");
    cout << "Summing up all numbers from the largest to the smallest results in: " << heapMaxSum << endl;
    float diff = abs(heapMaxSum - heapMinSum); // the absolute difference of the two summs
    cout << "The absolute difference of these two numbers is: " << diff << endl;
}

