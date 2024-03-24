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

    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        p[i]={ values[i] , weights[i] };
    }

    // enter the weight limit
    ifstream input2("max_weight.txt");
    int weight_limit;
    while (input2 >> x)
        weight_limit = x;
    input2.close();


    sort(p , p+n);

    int max_value = 0;
    int i=n-1;
    while(i>=0)
    {
        if(weight_limit - p[i].second>=0)
        {
            weight_limit -= p[i].second;
            max_value += p[i].first;
        }
        i--;
    }

    // output the answer
    cout<<max_value<<endl;
    // cout<<n<<endl;


    return 0;
}