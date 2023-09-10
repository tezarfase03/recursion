#include <iostream>
using namespace std;

// if we go with the brute force it will give stack overflow
// x*myPow(x,n-1);
// intution
// if the power of n is even then we can write this as (x*x)^n
//  if we want to calculate 2^10 =(2*2)^5 = 4^5 = 4*4^4 ,4^4= (4*4)^2=16^2=(16*16)^1=(264)*264^0
//

double myPow(double x, int n)
{
    if (n == 0)
        return 1.0;
    // this case will handle the negative number
    // we will covert the negative power in integer
    if (n < 0)
        return (1 / myPow(x, -(n + 1)) / x);
    if (n % 2 == 0)
    {
        // for even power
        return myPow(x * x, n / 2);
    }
    else
    {
        // for odd power
        return x * myPow(x, n - 1);
    }
}
int main()
{
    double x = 2.0;
    int n = 2 ^ -31;

    cout << myPow(x, n);
    return 0;
}