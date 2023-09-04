#include <bits/stdc++.h>
using namespace std;
// brute force approach using a map and a vector
// in this we keep track of which element has been mapped
class Solution
{

public:
    void per(vector<int> &arr, unordered_map<int, int> &mp, vector<int> &v, vector<vector<int>> &ans)
    {
        if (v.size() == arr.size())
        {
            ans.push_back(v);
            return;
        }
        // for loop hamesa 0 s hi start hoga jo agr element present hai to skip kr jjaenge
        for (int i = 0; i < arr.size(); i++)
        {
            // this if condition is to check if the current element has been already in the map we just simply avoid it and increment the i value
            if (mp[arr[i]] == 0)
            {
                v.push_back(arr[i]);
                mp[arr[i]] = 1;
                // calling recursion
                // tumhara doubt tha ki hum to hamesa same element pr call kr rhe hai to aage wala element kaise lenge uska answer hai map se jo agr map m pahle se hai to hum recursion call nhi kr rhe hai jo agr nhi hai tb kr rhe hai
                per(arr, mp, v, ans);
                mp[arr[i]] = 0;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> mp;
        per(nums, mp, v, ans);
        return ans;
    }
};

// second approach int thos approach we are not taking any map we are just using swapping
// tumhara soch ye tha ki two pointer k jaisa tum isko treat kiya tha
// jo ki ye hai ki index mera 1st pointer ho jaega aur i mera second pointer ho jaega
// tb 2 condition hoga ki index ==i rahega to same element swap hoga aur tum keh skte ho ki no swap condition ho jaegga aur dono diffrence rahega to swap ho jaega
// isme hum ek extra space use kr rhe hai vector
class Solution
{
public:
    void per(int index, vector<int> &arr, vector<int> &v, vector<vector<int>> &ans)
    {
        if (v.size() == arr.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < arr.size(); i++)
        {

            v.push_back(arr[i]);

            swap(arr[i], arr[index]);
            per(index + 1, arr, v, ans);
            swap(arr[i], arr[index]);
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;

        per(0, nums, v, ans);
        return ans;
    }
};

// without using a vector
// same swap approach but vector k bina use ka

class Solution
{
public:
    void per(int index, vector<int> &arr, vector<vector<int>> &ans)
    {
        // jaise hi index apna array ka soze ka hoga swap kr denge
        if (index == arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for (int i = index; i < arr.size(); i++)
        {

            // v.push_back(arr[i]);

            swap(arr[i], arr[index]);
            per(index + 1, arr, ans);
            swap(arr[i], arr[index]);
            //   v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;

        per(0, nums, ans);
        return ans;
    }
};