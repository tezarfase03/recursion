#include <bits/stdc++.h>
using namespace std;

int onesubsequence(int i, int arr[], int n, int sum, int k)
{
    if (i == n)
    {

        if (sum == k)
        {

            return 1;
        }
        else
        {
            return 0;
        }
    }

    sum += arr[i];

    int l = onesubsequence(i + 1, arr, n, sum, k);

    sum -= arr[i];

    int r = onesubsequence(i + 1, arr, n, sum, k);

    return l + r;
}
int main()
{

    int arr[] = {1, 2, 1, 2, 1, 0, 1, 3, 1};
    int k = 2;
    int n = 9;

    cout << onesubsequence(0, arr, n, 0, 2);

    return 0;
}