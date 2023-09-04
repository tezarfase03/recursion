#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int bs(int arr[], int target, int start, int end)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
    {
        return bs(arr, target, mid + 1, end);
    }
    else
    {
        return bs(arr, target, start, mid - 1);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 0;
    int end = 9;
    cout << bs(arr, target, 0, end);

    return 0;
}