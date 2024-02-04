#include <bits/stdc++.h>
using namespace std;
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }

int main()
{
    int x;
    // vector<int> nums1={1,3};
    vector<int> nums1;
    ifstream input_a("input_a.txt");
    while (input_a >> x)
        nums1.push_back(x);
    input_a.close();

    // vector<int> nums2={2};
    vector<int> nums2;
    ifstream input_b("input_b.txt");
    while (input_b >> x)
        nums2.push_back(x);
    input_b.close();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    double median;
    median = findMedianSortedArrays(nums1,nums2);
    cout<<"The median of the array is: "<<median<<endl;

    return 0;
}
// The output of this code was:
// The median of the array is: 49985.5