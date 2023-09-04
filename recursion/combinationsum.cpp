// problem statement
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// so  here what we have to do is we have to find a sum using the elements of the array we can use any element multiple times to get our target;

// recursive tree bnao tv smjh aaega ache s hint lelo dekh kr k
// same pick aur non pick conditon hai thoda sa catch ye hai ki same index pr har baar call kr rhe hai recursive tree bnaoge tb smjh aa jaega

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void combination(int index, int size, vector<int> &v, vector<int> &arr, vector<vector<int>> &ans, int target)
    {
        if (index == size)
        {
            if (target == 0)
            {
                ans.push_back(v);
            }

            return;
        }
        // here we are checking if the current index ka value is less than the target
        // aisa kyu kyu ki hum target ko har baari ghata rhe hai na to ab k current element s chack karenege ki jo agr wo chota hua tb to nhi hi ghata skte hai

        if (arr[index] <= target)
        {
            v.push_back(arr[index]);
            // ye wala pick condition hai jisme ki hum har baar same index ko pick kr rhe hai

            combination(index, size, v, arr, ans, target - arr[index]);
            v.pop_back();
        }
        // not pick condition
        // yha pe yaad rakho ki ya har recursive tree k liye ye uske index +1 s start hoga
        combination(index + 1, size, v, arr, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        combination(0, n, v, candidates, ans, target);
        return ans;
    }
};