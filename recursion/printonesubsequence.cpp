#include <bits/stdc++.h>
using namespace std;
void Printsubsequence(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
bool onesubsequence(int i, vector<int> v, int arr[], int n, int sum, int k)
{
    if (i == n)
    {

        if (sum == k)
        {
            Printsubsequence(v);
            return true;
        }
        else
        {
            return false;
        }
    }

    sum += arr[i];
    v.push_back(arr[i]);
    if (onesubsequence(i + 1, v, arr, n, sum, k) == true)
    {
        return true;
    }
    sum -= arr[i];
    v.pop_back();
    if (onesubsequence(i + 1, v, arr, n, sum, k) == true)
        return true;
    return false;
}
int main()
{

    int arr[] = {1, 2, 1};
    int k = 2;
    int n = 3;
    vector<int> v;
    onesubsequence(0, v, arr, n, 0, 2);

    return 0;
}