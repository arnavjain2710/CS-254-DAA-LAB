#include <bits/stdc++.h>
using namespace std;

int main() {
    //receving input
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    int x;
    //initializing the variables
    int largest = INT_MIN, secondLargest = INT_MIN;


    //Loop for finding the desired output
    while (inputFile >> x) {
        if(x > largest) {
            secondLargest = largest;
            largest = x;
            continue;
        }
        if(x > secondLargest) secondLargest = x;
    }

    inputFile.close();

    //Printing outputs to the output file
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile << largest + secondLargest << endl;
    outputFile.close();
    cout << "Data has been written to output.txt." << endl;

    return 0;
}