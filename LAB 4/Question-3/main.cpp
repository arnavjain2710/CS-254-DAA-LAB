#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(vector<int> arr, int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;

    // Iterate through the array elements
    for (int i = 0; i < N; i++)
    {
        // Push the current element onto the max heap
        pq.push(arr[i]);

        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }

    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}

// Driver's code:
int main()
{
    // int K = 4;
    // vector<int> arr = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
    // int N = arr.size();
    // The output is:
    // Kth Smallest Element is: 5

    // int K = 2;
    // vector<int> arr = {3, 2, 1, 5, 6, 4};
    // int N = arr.size();
    // The output is:
    // Kth Smallest Element is: 2

    int x;
    vector<int> arr;
    ifstream input("input.txt");
    while (input >> x)
        arr.push_back(x);
    input.close();
    int N = arr.size();
    int K = N / 2;
    // The output is:
    // Kth Smallest Element is: 50101

    // Function call
    cout << "Kth Smallest Element is: " << kthSmallest(arr, N, K);
}
