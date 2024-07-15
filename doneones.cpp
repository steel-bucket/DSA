#include "doneones.h"
#include <bits/stdc++.h>

using namespace std;

void printvectorfunction(vector<int> myVector) {
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
}
void swapfunction(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
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
void selectionSort(int arr[], int n) {
    for(int i =0;i<n;i++) {
        int smallest= INT_MAX;
        int smallestindex= INT_MAX;
        for(int j=i;j<n;j++) {
            if(arr[j]<smallest) {
                smallest = arr[j];
                smallestindex=j;
            }
        }
        swap(arr[smallestindex], arr[i]);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int didSwap = 0;
        for (int j = 0; j < n-i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int endpointer = i + 1;
        for (int j = endpointer; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void mergefunction(int arr[], int l, int m, int r) {
    int pointer1 = l;
    int pointer2 = m + 1;
    vector<int> arr2;
    while (pointer1 <= m && pointer2 <= r) {
        if (arr[pointer2] >= arr[pointer1]) {
            arr2.push_back(arr[pointer1]);
            pointer1++;
        } else {
            arr2.push_back(arr[pointer2]);
            pointer2++;
        }
    }
    while (pointer1 <= m) {
        arr2.push_back(arr[pointer1]);
        pointer1++;
    }
    while (pointer2 <= r) {
        arr2.push_back(arr[pointer2]);
        pointer2++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = arr2[i - l];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    mergefunction(arr, l, m, r);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSortRecursive(int arr[], int n, int i, int j) {
    if (i == n)return;
    if (j == n - i - 1)bubbleSortRecursive(arr, n, i + 1, 0);
    else if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        bubbleSortRecursive(arr, n, i, j + 1);
    }
    else {
        bubbleSortRecursive(arr, n, i, j + 1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int print2largest(vector<int> &arr) {
    if (arr.empty())return -1;
    int largest = -1;
    int secondlargest = -1;
    for (auto &it: arr) {
        if (it > largest) {
            secondlargest = largest;
            largest = it;
        }
        else if (it > secondlargest && it != largest) {
            secondlargest = it;
        }
    }
    return secondlargest;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkforrotatedsortedarray(vector<int> &nums) {
    int size = nums.size();
    bool theswitch = false;
    for (int i = 0; i < size-1; i++) {
        if (nums[i] > nums[i + 1] && nums[i] < nums[size - 1])return false;
        if (nums[i] > nums[i + 1] && theswitch == true)return false;
        if (nums[i] > nums[i + 1] && theswitch == false)theswitch = true;
    }
    if (nums[size-1] > nums[0] && theswitch == true)return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int removeDuplicates(vector<int> &nums) {
    int result = 0;
    int pointer1 = 0;
    int pointer2 = 1;
    int size = nums.size();
    while (pointer2 < size) {
        if (nums[pointer1] != nums[pointer2]) {
            pointer1++;
            nums[pointer1] = nums[pointer2];
            result++;
        }
        pointer2++;
    }
    return result + 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverseforrotate(vector<int> &nums, int start, int end) {
    while(start<=end) {
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    if(k>size)k%=size;
    reverseforrotate(nums, 0, size - k - 1);
    reverseforrotate(nums, size - k, size-1);
    reverseforrotate(nums, 0, size-1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int searchInSorted(int arr[], int N, int K) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > K) {
            high = mid-1;
        } else if(arr[mid] < K) {
            low = mid+1;
        }else {
            return 1;
        }

    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    int pointer1 = 0;
    int pointer2 = 0;
    vector<int> result;
    while (pointer1 < n && pointer2 < m) {
        if (arr2[pointer2] > arr1[pointer1]) {
            if (result.empty() || result.back() != arr1[pointer1]) {
                result.push_back(arr1[pointer1]);
            }
            pointer1++;
        } else {
            if (result.empty() || result.back() != arr2[pointer2]) {
                result.push_back(arr2[pointer2]);
            }
            pointer2++;
        }
    }
    while (pointer1 < n) {
        if (result.empty() || arr1[pointer1] != result.back()) {
            result.push_back(arr1[pointer1]);
        }
        pointer1++;
    }
    while (pointer2 < m) {
        if (result.empty() || arr2[pointer2] != result.back()) {
            result.push_back(arr2[pointer2]);
        }
        // cout << endl<< "iteration "<< pointer2 << " "<<arr2[pointer2];
        pointer2++;
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int missingNumber(vector<int> &nums) {
    int sum =0;
    int size = nums.size();
    for (int i: nums)sum+=i;
    return (((size)*(size+1))/2 - sum);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int findMaxConsecutiveOnes(vector<int> &nums) {
    int result = 0;
    int buffer = 0;
    for (int i: nums) {
        if (i == 1) {
            buffer++;
        } else {
            result = max(result, buffer);
            buffer = 0;
        }
    }
    return max(result, buffer);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int singleNumber(vector<int>& nums) {
    int result=0;
    for (int i: nums)result^=i;
    return result;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
