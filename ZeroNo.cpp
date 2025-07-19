/* Assign 1:- Implement a problem of number of zeroes.
Statement: Given an array of 1s and 0s which has all 1s first followed
by all 0s? Find the number of 0s. Count the number of zeroes in the
given array*/

#include <iostream>
using namespace std;

int countZeroes(int arr[], int n) {
    int low = 0, high = n - 1;
    int firstZeroIndex = n;  // assume no 0s

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == 0) {
            firstZeroIndex = mid;     // Found a 0, but look for earlier
            high = mid - 1;
        } else {
            low = mid + 1;            // Go right for 0s
        }
    }

    return n - firstZeroIndex;  // Total 0s = from first 0 to end
}

int main() {
    int arr[] = {1, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of 0s: " << countZeroes(arr, n);
    return 0;
}

//INPUT:-int arr[] = {1, 1, 1, 0, 0};
//OUTPUT:-Number of 0s: 2
