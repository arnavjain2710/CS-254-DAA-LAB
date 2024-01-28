// implementation of Kardanes Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; vector<int> a;

    ifstream input("input.txt");
    while(input >> x) a.push_back(x);
    input.close();

    int maximum = INT_MIN, curr_sum = 0, n = a.size();
    for(int i = 0; i < n; ++i) {
        curr_sum += a[i];
        maximum = max(maximum, curr_sum);
        if(curr_sum < 0) curr_sum = 0;
    }
    cout << "The largest possible sum of a subarray is: " << maximum << endl;
    // cout<<curr_sum<<endl;
    return 0;
}
// the output through this algorithm is : 2147460803