#include <bits/stdc++.h>
using namespace std;
struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void findMaxProfit(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), comparison);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    int max_profit=0;
    for (int i = 0; i < n; i++)
        if (slot[i])
        {
            max_profit+=jobs[result[i]].profit ;
            cout << jobs[result[i]].id << ' ';
        }
    cout<<endl;
    cout<<"The maximum profit is: "<<max_profit<<endl;
}

int main() {
    int M =0;
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

    vector<Job> jobs ;
    for(int i=0;i<n;i++)
    {
        Job a;
        a.id = job[i];
        a.deadline = deadline[i];
        a.profit = profit[i];
        jobs.push_back(a);
    }
    findMaxProfit(jobs, n);
    return 0;
}


// T.C. - O(n.log(n))