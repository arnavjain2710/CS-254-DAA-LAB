#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include <bits/stdc++.h>

using namespace std;
using ti = tuple<char, int, int>;

bool comp(ti t1, ti t2){
    if(get<1>(t1)<get<1>(t2))return false;
    else if(get<1>(t1)==get<1>(t2)){
        if(get<2>(t1)>get<2>(t2))return false;
        else return true;
    }
    else return true;
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
    priority_queue<ti, vector<ti>, decltype(&comp)> p(comp);
    for(int i=0;i<n;i++)
    {
        int a= job[i];
        int b = deadline[i];
        int c = profit[i];
        p.push({a,b,c});
    }
    int time{1}, max_profit{0};
    queue<char> seq;
    while(!p.empty()){
        ti curr = p.top();
        p.pop();
        if(time<=get<1>(curr)){
            time++;
            seq.push(get<0>(curr));
            max_profit += get<2>(curr);
        }
    }
    cout<<endl;
    while(!seq.empty()){
        char job = seq.front();
        cout<<job<<" ";
        seq.pop();
    }
    cout<<max_profit<<endl;
    return 0;
}