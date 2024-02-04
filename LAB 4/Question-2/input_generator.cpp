#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);  
    const int numRandomNumbers = 100000;
    ofstream input_a("input_a.txt");

    if (!input_a.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        input_a << randomNum;

        if (i < numRandomNumbers - 1) {
            input_a << ' ';
        }
    }

    input_a.close();
    cout << "Random integers have been stored in input.txt." << endl;

     ofstream input_b("input_b.txt");

    if (!input_b.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        input_b << randomNum;

        if (i < numRandomNumbers - 1) {
            input_b << ' ';
        }
    }

    input_b.close();
    cout << "Random integers have been stored in input.txt." << endl;

    return 0;
}