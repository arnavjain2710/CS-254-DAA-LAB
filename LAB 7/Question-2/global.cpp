#include <bits/stdc++.h>
using namespace std;
struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.deadline < b.deadline);
}

int findMaxProfit(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), comparison);
    int maxDeadline = jobs[n-1].deadline;
    vector<int> dp(maxDeadline+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (dp[j] < dp[j-1] + jobs[i].profit) {
                dp[j] = dp[j-1] + jobs[i].profit;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
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

    std::cout << "Maximum profit is " << findMaxProfit(jobs, n) << std::endl;
    return 0;
}


// T.C. - O(n^2)