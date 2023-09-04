#include <iostream>
using namespace std;
int PI(int arr[], int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    while (i < j)
    {
        // we have give condition that i<j but we have designed it in this way so that it can corss each other just by one element and thas how we will return the i or j according to our choice

        while (arr[i] <= pivot && i <= j) /*you can also write this as i<=high-1 */
        {
            i++;
        }
        // why are we traversing it to the low and high because the i will stop at the grater element than pivot and j will stop at left side which will be smallest element than the pivot both i and j can cross so that they can swap the pivot and return the index
        while (arr[j] > pivot) /*you can also write this as i<=low+1 */
        {
            j--;
        }
        if (i < j)
            // this swap will only workk if i <j and if it crosses that means the smalles elemnt has been sent on the left side and the greater element than the pivot is sent on the right side of the partiton index
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    // we can return either i-1 or j
    // we are returning i-1 why? because it will stop at the grater element than the pivot  after crossing j so we return i-1
    // we are returning j because it will stop at the smallest elemnt than the pivot after crossing i
    return i - 1;
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partionindex = PI(arr, low, high);
        mergesort(arr, low, partionindex - 1);
        mergesort(arr, partionindex + 1, high);
    }
}
int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    mergesort(arr, 0, 7);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}