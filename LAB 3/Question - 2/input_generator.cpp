#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);  
    const int numRandomNumbers = 100000;
    ofstream input("input.txt");

    if (!input.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        input << randomNum;

        if (i < numRandomNumbers - 1) {
            input << ' ';
        }
    }

    input.close();
    cout << "Random integers have been stored in input.txt." << endl;

    return 0;
}