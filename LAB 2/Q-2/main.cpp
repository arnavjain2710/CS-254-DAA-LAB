#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int m, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (A[i] > A[j])
            A[k--] = A[i--];
        else
            A[k--] = A[j--];
    }

    while (j >= 0)
        A[k--] = A[j--];
}

int main()
{
    int x;
    vector<int> a, b;

    ifstream array_a("../array_a.txt");
    while (array_a >> x)
        a.push_back(x);
    sort(a.begin(), a.end());
    array_a.close();

    ifstream array_b("../array_b.txt");
    while (array_b >> x)
        b.push_back(x);
    sort(b.begin(), b.end());
    array_b.close();

    vector<int> A;
    for (int y : a)
        A.push_back(y);
    for (int y : b)
        A.push_back(y);

    int n = A.size();
    int m = a.size();
    merge(A, m, n - m);

    ofstream outputFile("output.txt");
    for (int y : A)
        outputFile << y << " ";
    outputFile.close();
    return 0;
}
