#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream input("deadline.txt");
    vector<int> deadline;
    int x;
    while (input >> x)
        deadline.push_back(x);
    input.close();

    int n = deadline.size();

    ifstream input1("profit.txt");
    vector<int> profit;
    while (input1 >> x)
        profit.push_back(x);
    input1.close();

    
    return 0;
}