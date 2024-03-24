#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream input("weights.txt");
    vector<int> weights;
    int x;
    while (input >> x)
        weights.push_back(x);
    input.close();

    int n = weights.size();

    ifstream input1("values.txt");
    vector<int> values;
    while (input1 >> x)
        values.push_back(x);
    input1.close();

    // enter the weight limit
    ifstream input2("max_weight.txt");
    int weight_limit;
    while (input2 >> x)
        weight_limit = x;
    input2.close();

    vector<vector<int>> dp(n+2, vector<int>(weight_limit+2, 0));
    for(int i = 1; i <= n; ++i) {
        for(int w = 1; w <= weight_limit; ++w) {
            if(weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else 
                dp[i][w] = dp[i-1][w];
        }
    }


    // output the answer
    cout<<dp[n][weight_limit]<<endl;
    // cout<<n<<endl;


    return 0;
}

// Time Complexity: O(N * W). where ‘N’ is the number of elements and ‘W’ is capacity. 
// Auxiliary Space: O(N * W). The use of a 2-D array of size ‘N*W’.