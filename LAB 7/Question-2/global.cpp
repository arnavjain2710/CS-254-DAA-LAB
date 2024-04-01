#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
using ti = tuple<char, int, int>;

bool comp(ti t1, ti t2){
    if(get<1>(t1)>get<1>(t2))return false;
    else if(get<1>(t1)==get<1>(t2)){
        if(get<2>(t1)>get<2>(t2))return false;
        else return true;
    }
    else return true;
}

int helper(vector<ti>& v, int ind, int time, int n, int max_t, vector<vector<int>>& dp){
    if(time>max_t || ind>=n)return 0;
    if(dp[ind][time]!=-1)return dp[ind][time];
    int ans = helper(v, ind+1, time, n, max_t, dp);
    if(time<=get<1>(v[ind])) ans = max(ans, helper(v, ind+1, time+1, n, max_t, dp)+get<2>(v[ind]));
    return dp[ind][time] = ans;
}

int main(){
    ifstream input("deadline.txt");
    vector<int> deadline;
    int x;
    while (input >> x)
    {
        // cout<<"x "<<x<<endl;
        deadline.push_back(x);
    }
    input.close();

    int n = deadline.size();

    ifstream input1("profit.txt");
    vector<int> profit;
    while (input1 >> x)
        profit.push_back(x);
    input1.close();

    char y;
    ifstream input2("job.txt");
    vector<int> job;
    while (input2 >> y)
        job.push_back(y);
    input2.close();
    vector<ti> v(n);
    int max_t=0;
    for(int i=0;i<n;i++)
    {
        int a= job[i];
        int b = deadline[i];
        int c = profit[i];
        v[i] = {a, b, c};
        max_t=max(max_t, b);
    }
    
    // cout<<max_t<<endl;
    sort(v.begin(), v.end(), comp);
    vector<vector<int>> dp(n, vector<int>(max_t+1, -1));
    cout<<helper(v, 0, 1, n, max_t, dp)<<endl;
    return 0;
}

//time complexity: O(n*max_t)