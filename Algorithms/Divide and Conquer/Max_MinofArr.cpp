//Write a program find the maximum and minimum of an array using divide and conquer technique.

#include <iostream>
#include<climits>
#define MAX 100
using namespace std;

void findMinAndMax(int nums[], int low, int high, int &minNum, int &maxNum)
{
    // if the array contains only one element

    if (low == high)
    {
        if (maxNum < nums[low]) {
            maxNum = nums[low];
        }

        if (minNum > nums[high]) {
            minNum = nums[high];
        }

        return;
    }

    // if the array contains only two elements

    if (high - low == 1)
    {
        if (nums[low] < nums[high])
        {
            if (minNum > nums[low]) {
                minNum = nums[low];
            }

            if (maxNum < nums[high]) {
                maxNum = nums[high];
            }
        }
        else {
            if (minNum > nums[high]) {
                minNum = nums[high];
            }

            if (maxNum < nums[low]) {
                maxNum = nums[low];
            }
        }
        return;
    }

    // find the middle element
    int mid = (low + high) / 2;

    // recur for the left subarray
    findMinAndMax(nums, low, mid, minNum, maxNum);

    // recur for the right subarray
    findMinAndMax(nums, mid + 1, high, minNum, maxNum);
}

int main()
{
    int nums[MAX],n;
    cout << "Enter size : ";
    cin >> n;

    cout << "Enter elements : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // initialize the minimum element by INFINITY and the
    // maximum element by -INFINITY
    int maxNum = INT_MIN, minNum = INT_MAX;

    findMinAndMax(nums, 0, n - 1, minNum, maxNum);

    cout << "The minimum array element is " << minNum << endl;
    cout << "The maximum array element is " << maxNum << endl;

    return 0;
}
