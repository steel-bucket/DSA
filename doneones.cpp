#include "doneones.h"
#include <bits/stdc++.h>

using namespace std;

void printvector(vector<int> myVector) {
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int evenlyDivides(int N) {
    int buffer = N;
    int result = 0;
    while (buffer > 0) {
        int digit = buffer - (buffer / 10) * 10;
        if (digit == 0) {
            buffer /= 10;
            continue;
        }
        if (N % digit == 0) {
            cout << digit << "   ";
            result++;
        }
        buffer /= 10;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int reverse(long long int x) {
    long long int buffer = x;
    long long int result = 0;
    bool isNegative = (x < 0);
    if (isNegative)buffer *= -1;
    while (buffer > 0) {
        if (result > INT_MAX / 10 || result < INT_MIN / 10)return 0;
        long long int digit = buffer % 10;
        result = result * 10 + digit;
        buffer /= 10;
    }
    if (isNegative)result *= -1;
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int reverseFunctionForIsPalindrome(long long int x) {
    long long int buffer = x;
    long long int result = 0;
    while (buffer > 0) {
        if (result > INT_MAX / 10 || result < INT_MIN / 10)return 0;
        long long int digit = buffer % 10;
        result = result * 10 + digit;
        buffer /= 10;
    }
    return result;
}

bool isNumberPalindrome(long long int givenNumber) {
    if (givenNumber < 0)return false;
    if (givenNumber == reverseFunctionForIsPalindrome(givenNumber))return true;
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<long long> lcmAndGcd(long long A, long long B) {
    //Euclidian Algorithm- 2 numbers have the same hcf if smaller one is subtracted from the larger one
    long long AA = A, BB = B;
    while (AA > 0 || BB > 0) {
        if (AA > BB) {
            AA -= BB;
        }
        if (AA < BB) {
            BB -= AA;
        }
        if (AA == BB) {
            return {(A * B) / AA, AA};
        }
    }
    return vector<long long>{A * B, A};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> divisors(int number) {
    vector<int> result;
    for (int i = 1; i * i < number; i++) {
        if (number % i == 0 && i * i != number) {
            result.push_back(i);
            result.push_back(number / i);
        } else if (i * i == number) {
            result.push_back(i);
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<long long> factorial(long long n, vector<long long> result, long long buffer) {
    if ((buffer + 1) * result.back() > n) return result;
    result.push_back((buffer + 1) * result.back());
    return factorial(n, result, buffer + 1);
}

vector<long long> factorialNumbers(long long n) {
    return factorial(n, {1}, 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(vector<int> &array, int index = 0) {
    if (index != array.size() / 2) {
        swap(array[index], array[array.size() - index - 1]);
        reverseArray(array, index + 1);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string clean(const string &s) {
    string result;
    for (auto &it: s) {
        if ((it >= 97 && it <= 122) || (it >= 48 && it <= 57)) {
            result += it;
            // result.append(to_string(it));
        }
        if (it >= 65 && it <= 90) {
            result += tolower(it);
            // result.append(to_string(tolower(it)));
        }
    }
    return result;
}

bool isStringPalindrome(string s) {
    for(int index = 0;index<s.size()/2;index++){
        if (index != s.size() / 2) {
            if (s[index] != s[s.size() - index - 1]) {
                return false;
            }
        }
    }
    return true;
}

bool isPalindrome(string s) {
    s = clean(s);
    return isStringPalindrome(s);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
