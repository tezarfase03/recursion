#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void combination(int index, vector<int> &arr, vector<int> &v, vector<vector<int>> &ans, int target)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        // recursion tree bnao smjh aaega
        // this for loop is about picking unique subaaray we can avoid taking the same element
        // like for example we avoid doing

        // its basically like avoiding the same element on the same index its like what is the pointing in picking th same element again and again to ceate rather we can do is we pick unique element on the same index  to form combination
        // [1,1,2] like here we have pick 1 at the 0th index and 1 at 1st index then again picking the same combination with these two sequence is no point
        // [2,2]

        // [2,2]

        for (int i = index; i < arr.size(); i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            v.push_back(arr[i]);
            combination(i + 1, arr, v, ans, target - arr[i]);
            v.pop_back();
        }
    }
    // to avoid duplicate combination we need to sorrt the array
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combination(0, candidates, v, ans, target);
        return ans;
    }
};