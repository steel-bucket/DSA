#include "betterimplementations.h"
#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isNumberPalindromeBetter(int x) {
    if (x < 0 || x % 10 == 0 && x != 0) return false; // used the 10 thing here
    int a = x, b = 0;
    while (x > 0) {
        b = b * 10 + x % 10;
        if (b > INT_MAX / 10) break; // better implementation of INT_MAX
        x = x / 10;
    }
    return b == a ? true : false; // JAVASCRIPT
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long sumOfDivisorsBetter(int N) {
    long long result = 0;
    for (int i = 1; i < N + 1; i++) {
        result += (N / i) * i;
    }
    return result;
    //     Let n = 6,
    // => F(1) + F(2) + F(3) + F(4) + F(5) + F(6)
    // => 1 will occurs 6 times in F(1), F(2), F(3), F(4), F(5) and F(6)
    // => 2 will occurs 3 times in F(2), F(4) and F(6)
    // => 3 will occur 2 times in F(3) and F(6)
    // => 4 will occur 1 times in F(4)
    // => 5 will occur 1 times in F(5)
    // => 6 will occur 1 times in F(6)
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isStringPalindromeBetter(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end) {
        if (!isalnum(s[start])) {
            start++;
            continue;
        }
        if (!isalnum(s[end])) {
            end--;
            continue;
        }
        if (tolower(s[start]) != tolower(s[end]))return false;
        else {
            start++;
            end--;
        }
    }
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mergeBetter(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Iterative merge sort function
void mergeSortBetter(int arr[], int n) {
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            mergeBetter(arr, left_start, mid, right_end);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSortRecursiveBetter(int arr[], int n) {
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    bubbleSortRecursiveBetter(arr, n - 1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
