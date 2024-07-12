#include "betterimplementations.h"
#include <bits/stdc++.h>

bool isPalindrome(int x) {
    if (x < 0 || x % 10 == 0 && x != 0) return false; // used the 10 thing here
    int a = x, b = 0;
    while (x > 0) {
        b = b * 10 + x % 10;
        if (b > INT_MAX / 10) break; // better implementation of INT_MAX
        x = x / 10;
    }
    return b == a ? true : false; // JAVASCRIPT
}

long long sumOfDivisors(int N) {
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
