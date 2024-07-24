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
    for (int index = 0; index < s.size() / 2; index++) {
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
    for (int i = 0; i < n; i++) {
        int smallest = INT_MAX;
        int smallestindex = INT_MAX;
        for (int j = i; j < n; j++) {
            if (arr[j] < smallest) {
                smallest = arr[j];
                smallestindex = j;
            }
        }
        swap(arr[smallestindex], arr[i]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int didSwap = 0;
        for (int j = 0; j < n - i - 1; j++) {
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
    for (int i = 0; i < n - 1; i++) {
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
    } else {
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
        } else if (it > secondlargest && it != largest) {
            secondlargest = it;
        }
    }
    return secondlargest;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool checkforrotatedsortedarray(vector<int> &nums) {
    int size = nums.size();
    bool theswitch = false;
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1] && nums[i] < nums[size - 1])return false;
        if (nums[i] > nums[i + 1] && theswitch == true)return false;
        if (nums[i] > nums[i + 1] && theswitch == false)theswitch = true;
    }
    if (nums[size - 1] > nums[0] && theswitch == true)return false;
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
    while (start <= end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int> &nums, int k) {
    int size = nums.size();
    if (k > size)k %= size;
    reverseforrotate(nums, 0, size - k - 1);
    reverseforrotate(nums, size - k, size - 1);
    reverseforrotate(nums, 0, size - 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int searchInSorted(int arr[], int N, int K) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > K) {
            high = mid - 1;
        } else if (arr[mid] < K) {
            low = mid + 1;
        } else {
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
    int sum = 0;
    int size = nums.size();
    for (int i: nums)sum += i;
    return (((size) * (size + 1)) / 2 - sum);
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
int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int i: nums)result ^= i;
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> twoSumbruteforce(vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (nums[j] + nums[i] == target && i != j) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> twoSumhashtable(vector<int> &nums, int target) {
    int size = nums.size();
    map<int, int> numbersmap;
    for (int i = 0; i < size; i++) {
        if (numbersmap.find(target - nums[i]) == numbersmap.end()) {
            numbersmap[nums[i]] = i;
        } else {
            return {numbersmap[target - nums[i]], i};
        }
    }
    return {5};
}

vector<int> twoSumsort(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int p1 = 0;
    int p2 = size - 1;
    while (p1 != p2) {
        if (nums[p1] + nums[p2] == target) {
            return {1};
        } else if (nums[p1] + nums[p2] > target) {
            p2--;
        } else {
            p1++;
        }
    }
    return {0};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dutchnationalflag(vector<int> &nums) {
    int red = 0, white = 0, blue = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0)red++;
        else if (nums[i] == 1)white++;
        else blue++;
    }
    while (blue--)nums[blue + white + red] = 2;
    while (white--)nums[white + red] = 1;
    while (red--)nums[red] = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int moorevoting(vector<int> &nums) {
    int count = 0;
    int buffer = nums[0];
    for (int num: nums) {
        if (num == buffer) {
            count++;
        } else if (num != buffer && count > 0) {
            count--;
        } else {
            buffer = num;
            count++;
        }
    }
    return buffer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int maxSubArray(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)return nums[0];
    int sum = 0;
    int result = INT_MIN;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
        if (sum < result)result = sum;
        if (sum < 0)sum = 0;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int maxProfit(vector<int> &prices) {
    int low = 0;
    int result = 0;
    int size = prices.size();
    for (int high = 0; high < size; high++) {
        if (prices[low] > prices[high]) {
            low = high;
        }
        result = max(result, prices[high] - prices[low]);
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> rearrangeArray(vector<int> &nums) {
    stack<int> even;
    stack<int> odd;
    int size = nums.size();
    vector<int> result(size);
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] < 0)odd.push(nums[i]);
        else even.push(nums[i]);
    }
    for (int j = 0; j < size; j++) {
        if (j % 2 == 0) {
            int num = even.top();
            even.pop();
            result[j] = num;
        } else {
            int num = odd.top();
            odd.pop();
            result[j] = num;
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverse(vector<int> &nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(vector<int> &nums) {
    int breakpoint = -1;
    int size = nums.size();
    for (int i = size - 1; i >= 1; i--) {
        if (nums[i] > nums[i - 1]) {
            breakpoint = i - 1;
            break;
        }
    }
    if (breakpoint == -1) {
        reverse(nums, 0, size - 1);
        return;
    }
    int secondlargest = -1;
    int buffer = INT_MAX;
    for (int j = breakpoint + 1; j < size; j++) {
        if (nums[j] - nums[breakpoint] <= buffer && nums[j] - nums[breakpoint] > 0) {
            secondlargest = j;
            buffer = nums[j] - nums[breakpoint];
        }
    }
    swap(nums[breakpoint], nums[secondlargest]);
    reverse(nums, breakpoint + 1, size - 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> leaders(int n, int arr[]) {
    vector<int> result;
    int maxi = arr[n - 1];
    result.push_back(maxi);
    if (n == 1)return result;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxi) {
            result.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int bufferx = 1;
    int buffery = 1;
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0)bufferx = 0;
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0)buffery = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
            if (matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) if (bufferx == 0)matrix[i][0] = 0;
    for (int j = 0; j < n; j++) if (buffery == 0)matrix[0][j] = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void transpose(vector<vector<int> > &matrix) {
    int m = matrix.size();
    for (int i = 0; i < m; i++)for (int j = 0; j < m; j++)if (i > j)swap(matrix[i][j], matrix[j][i]);
}

void reversematrix(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}


void rotate(vector<vector<int> > &matrix) {
    transpose(matrix);
    int m = matrix.size();
    for (int i = 0; i < m; i++)reversematrix(matrix[i]);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result;
    pair<int, int> topleft = {0, 0};
    pair<int, int> bottomright = {rows - 1, cols - 1};

    while (topleft.first <= bottomright.first && topleft.second <= bottomright.second) {
        for (int i = topleft.second; i <= bottomright.second; i++)result.push_back(matrix[topleft.first][i]);
        topleft.first++;
        for (int i = topleft.first; i <= bottomright.first; i++)result.push_back(matrix[i][bottomright.second]);
        bottomright.second--;
        if (topleft.first <= bottomright.first) {
            for (int i = bottomright.second; i >= topleft.second; i--) {
                result.push_back(matrix[bottomright.first][i]);
            }
            bottomright.first--;
        }
        if (topleft.second <= bottomright.second) {
            for (int i = bottomright.first; i >= topleft.first; i--) { result.push_back(matrix[i][topleft.second]); }
            topleft.second++;
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int subarraySumfunction(vector<int> &nums, int k) {
    map<int, int> pre;
    int size = nums.size();
    int sum = 0;
    int result = 0;
    pre[0] = 1;
    if (size == 1 && nums[0] != k)return 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
        int rem = sum - k;
        if (pre.find(rem) != pre.end()) {
            result += pre[rem];
        }
        pre[sum]++;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> nextarray(vector<int> nums) {
    int size = nums.size();
    if (size == 1)return {1, 1};
    vector<int> result(size + 1);
    result[0] = 1;
    result[size] = 1;
    for (int i = 1; i < size; i++) {
        result[i] = nums[i - 1] + nums[i];
    }
    return result;
}

vector<vector<int> > generatepascal(int numRows) {
    vector<vector<int> > result;
    result.push_back({1});
    for (int i = 0; i < numRows - 1; i++) {
        result.push_back(nextarray(result[i]));
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> majorityElement(vector<int> &nums) {
    int size = nums.size();
    if (size == 1)return {nums[0]};
    int
            c1 = 0,
            c2 = 0,
            e1 = INT_MIN,
            e2 = INT_MIN;
    if (nums[0] == nums[1])c2++;
    vector<int> result;
    int satisfactory = size / 3;
    for (int i = 0; i < size; i++) {
        if (nums[i] == e1)c1++;
        else if (nums[i] == e2)c2++;
        else if (c1 == 0) {
            e1 = nums[i];
            c1++;
        } else if (c2 == 0) {
            e2 = nums[i];
            c2++;
        } else {
            c1--;
            c2--;
        }
    }

    int c11 = 0;
    int c22 = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] == e1)c11++;
        if (nums[i] == e2)c22++;
    }
    if (c11 > satisfactory)result.push_back(e1);
    if (c22 > satisfactory)result.push_back(e2);
    if (e1 == e2)return {e1};
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int> > threeSumbruteforce(vector<int> &nums) {
    int size = nums.size();
    set<vector<int> > st;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                if (i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
            }
        }
    }
    vector<vector<int> > result(st.begin(), st.end());
    return result;
}

vector<vector<int> > threeSumhashmap(vector<int> &nums) {
    int size = nums.size();
    set<vector<int> > resultset;
    for (int i = 0; i < size; i++) {
        set<int> s;
        for (int j = i + 1; j < size; j++) {
            int third = -1 * (nums[i] + nums[j]);
            if (s.find(third) != s.end()) {
                vector<int> v = {nums[i], nums[j], third};
                sort(v.begin(), v.end());
                resultset.insert(v);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int> > result(resultset.begin(), resultset.end());
    return result;
}

vector<vector<int> > twoSumforthreesum(vector<int> &nums, int target, int start) {
    auto size = nums.size();
    map<int, int> numbersmap;
    vector<vector<int> > result;
    for (int i = start; i < size; i++) {
        if (numbersmap.find(target - nums[i]) == numbersmap.end()) {
            numbersmap[nums[i]] = i;
        } else {
            result.push_back({nums[numbersmap[target - nums[i]]], nums[i]});
        }
    }
    return result;
}


vector<vector<int> > threeSumwithtwosum(vector<int> &nums) {
    auto size = nums.size();
    set<vector<int> > resultset;
    for (int i = 0; i < size; i++) {
        int k = -1 * (nums[i]);
        vector<vector<int> > vec = twoSumforthreesum(nums, k, i + 1);
        if (!vec.empty()) {
            for (auto &j: vec) {
                j.push_back(-k);
                sort(j.begin(), j.end());
                resultset.insert(j);

            }
        }
    }
    vector<vector<int> > result(resultset.begin(), resultset.end());
    return result;
}
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int LargestSubarraywith0Sum(vector<int> &arr, int n) {
    map<int, int> pre;
    int sum = 0;
    int result = 0;
    int currentlength = 0;
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (pre.find(sum) != pre.end()) {
            currentlength = i - pre[sum];
            result = max(result, currentlength);
            pre[sum] = min(i, pre[sum]);
        } else pre[sum] = i;
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int> > merge(vector<vector<int> > &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0];
    });
    int i = 0;
    while (true) {
        if (i >= intervals.size() - 1) { break; }
        if (intervals[i][1] >= intervals[i + 1][0] && intervals[i][1] <= intervals[i + 1][1]) {
            intervals[i][1] = intervals[i + 1][1];
            intervals.erase(intervals.begin() + i + 1);
        } else if (intervals[i][1] >= intervals[i + 1][0] && intervals[i][1] > intervals[i + 1][1]) {
            intervals.erase(intervals.begin() + i + 1);
        } else i++;
    }
    return intervals;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> findTwoElement(vector<int> arr, int n) {
    int repeating = -1;
    int missing = -1;
    long long nn1 = ((n) * (n + 1)) / 2;
    long long nn12n16 = ((n) * (n + 1) * (2 * n + 1)) / 6;
    for (auto &i: arr) {
        nn1 -= i;
        nn12n16 -= i * i;
    }
    repeating = ((nn12n16 / nn1) + (nn1)) / 2;
    missing =(( nn12n16 / nn1) - (nn1)) / 2;
    return {
        missing,repeating
    };
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertforinversionCount(vector<long long> &temp, long long num, long long &result, int current) {
    int l = 0;
    int h = temp.size() - 1;
    int m;
    while (l <= h) {
        m = (l + h) / 2;
        if (temp[m] > num) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    temp.insert(temp.begin() + l, num);
    result += current - l;
}

long long int inversionCountbinarysearch(long long arr[], int n) {
    vector<long long> temp;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        insertforinversionCount(temp, arr[i], result, i);
    }
    return result;
}
long long inversionCountMultiset(long long arr[], int n) {
    multiset<long long> st;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(arr[i]);
        result += distance(it, st.end());
        st.insert(arr[i]);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int binarysearch(vector<int> &nums, int target) {
    int l = 0;
    int h = nums.size();
    while (l <= h) {
        int m = (l + h) / 2;
        if (nums[m] > target)h = m - 1;
        else if (nums[m] < target)l = m + 1;
        else return m;
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findFloor(vector<long long> v, long long n, long long x) {
    long long l = 0;
    long long h = n -1;
    long long m;
    while (l <= h) {
        m = (l + h) / 2;
        if(v[m] == x)return m;
        else if (v[m] < x)l = m + 1;
        else h = m - 1;
    }
    return h;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> getFloorAndCeil(int x, const vector<int> &arr) {
    int floor = -1;
    int ceil = -1;
    int floordistance = INT_MAX;
    int ceildistance = INT_MAX;
    for (const int &i: arr) {
        if(i==x)return {i,i};
        if (i < x && x - i < floordistance) {
            floor = i;
            floordistance = x - i;
        }
        if (i > x && i - x < ceildistance) {
            ceil = i;
            ceildistance = i - x;
        }
    }
    return {floor, ceil};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int h = nums.size()-1;
    int m = (l + h) / 2;
    int result = m;
    while (l <= h) {
        m = (l + h) / 2;
        if (nums[m] >= target){result = m;h = m - 1;}
        else if (nums[m] < target)l = m + 1;
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findstarting(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] > x) {
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int findending(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            ans = mid;
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int a = findstarting(nums, n, target);
    int b = findending(nums, n, target);
    // if (a != -1 && nums[a] == target)result.push_back(a);
    // else result.push_back(-1);
    // if (b > -1 && nums[b] == target)result.push_back(b);
    // else result.push_back(-1);
    return {a,b};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count(int arr[], int n, int x) {
    // int a = findstarting(arr, n, x); // Uncomment
    // int b = findending(arr, n, x); // Uncomment
    // if (a != -1)return b - a + 1; // Uncomment
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool searchinrotatedsortedarray2(vector<int> &nums, int target) {
    int l = 0;
    int h = nums.size() - 1;
    int m = (l + h) / 2;
    while (l <= h) {
        m = (l + h) / 2;
        cout << l << " " << m << " " << h << endl;
        if (nums[m] == target)return true;
        if (nums[h] == target)return true;
        if (nums[l] == target)return true;
        if (nums[l] < nums[m]) {
            if (nums[l] <= target && target < nums[m])h = m - 1;
            else l = m + 1;
        } else if (nums[l] > nums[m]){
            if (nums[m] < target && target <= nums[h])l = m + 1;
            else h = m - 1;
        } else {
            for(int i = m;i<h+1;i++) {
                if(nums[i] == target)return true;
            }
            h = m-1;
        }
    }
    cout << l << " " << m << " " << h << endl;
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findMin(vector<int> &nums) {
    int l = 0;
    int size = nums.size();
    int h = size - 1;
    int m = (l + h) / 2;
    if(h == 0)return nums[0];
    if(h == 1)return min(nums[0], nums[1]);
    while (l <= h) {
        m = (l + h) / 2;
        cout << l << " " << m << " " << h << endl;
        if (m > 0 && m < size - 1 && nums[m] < nums[m - 1] && nums[m] < nums[m + 1])return nums[m];
        if (m == 0 && nums[m] < nums[m + 1] && nums[m] < nums[size - 1])return nums[m];
        if (m == size - 1 && nums[m] < nums[0] && nums[m] < nums[m-1])return nums[m];
        if(m == l) return min(nums[m], nums[h]);
        if(m == h) return min(nums[m], nums[l]);
        if (nums[m] > nums[l] && nums[m] > nums[h]) {
            l = m + 1;
        } else if (nums[m] < nums[l] && nums[m] < nums[h]) {
            h = m - 1;
        } else {
            return nums[l];
        }
    }
    cout << l << " " << m << " " << h << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int singleNonDuplicate(vector<int> &nums) {
    int l = 0;
    int h = nums.size() - 1;
    int m = (l + h) / 2;
    if (h == 0)return nums[0];
    int second;
    while (l <= h) {
        m = (l + h) / 2;
        if(m == 0) {
            if(nums[m] != nums[m+1])return nums[m];
        }
        if(m == nums.size() - 1) {
            if(nums[m] != nums[m-1])return nums[m];
        }
        if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])return nums[m];
        if (nums[m] == nums[m - 1])second = m;
        else if (nums[m] == nums[m+1])second = m+1;
        if (second % 2 == 0)h = m - 1;
        else if (second % 2 == 1)l = m + 1;
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long int floorSqrt(long long int x) {
    long long l = 0;
    long long h = x;
    long long m = x / 2;
    while (l <= h) {
        m = (l + h) / 2;
        if (m * m == x)return m;
        if (m * m < x && (m + 1) * (m + 1) > x)return m;
        if (m * m < x)l = m + 1;
        else h = m - 1;
    }
    return m;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
