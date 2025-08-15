/*Implement a problem of smallest number with at least no trailing
zeroes in factorial.
Statement: Given a number n. The task is to find the smallest number
whose factorial contains at least n trailing zeroes.
*/

#include <iostream>
using namespace std;

int no_of_zeroes(int x);

int findNum(int n)
{
    int low = 0;
    int high = 5 * n;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int zeroes = no_of_zeroes(mid);
        if (zeroes >= n)
        {
            ans = mid;
            high = mid - 1; // Try to find a smaller number
        }
        else
        {
            low = mid + 1; // Increase the number to find more zeroes
        }
    }
    return ans;
}

int no_of_zeroes(int x)
{
    int denom = 5;
    int zeroes = 0;
    while (x >= denom)
    {
        zeroes += (x / denom);
        denom *= 5;
    }
    return zeroes;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Output:-" << findNum(n) << endl;
}

//INPUT:-Enter the number: 3

//OUTPUT:-15
