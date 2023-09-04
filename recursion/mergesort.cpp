#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int l, int m, int r)
{
    int left = l;
    int right = m + 1;
    vector<int> temp;
    while (left <= m && right <= r)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }
    while (left <= m)
    {
        temp.push_back(v[left]);
        left++;
    }
    while (right <= r)
    {
        temp.push_back(v[right]);
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        v[i] = temp[i - l];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}