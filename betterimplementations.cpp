#include "betterimplementations.h"
#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct Node {
    int val;
    Node *next;

    Node(int d, Node *n) {
        val = d;
        next = n;
    }

    explicit Node(int d) {
        val = d;
        next = nullptr;
    }
};

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


int getLongestSubarray(vector<int> &a, long long k) {
    int n = a.size();
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cout << "Round :" << i << endl;
        cout << "This is a[i] :" << a[i] << endl;
        cout << "This is sum :" << sum << endl;
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
            cout << "We're increasin maxLen. This is maxLen :" << maxLen << endl;
        }
        long long rem = sum - k;
        cout << "This is rem :" << rem << endl;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            cout << "preSumMap didn't found rem. This is len :" << len << endl;
            maxLen = max(maxLen, len);
            cout << "We're increasin maxLen. This is maxLen :" << maxLen << endl;
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
            cout << "preSumMap found rem. This is preSumMap[sum] :" << preSumMap[sum] << endl;
        }
    }

    return maxLen;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dutchnationalflagBetter(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1; // 3 pointers

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<int> RearrangebySign(vector<int> A) {
    int n = A.size();

    // Define array for storing the ans separately.
    vector<int> ans(n, 0);

    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        // Fill negative elements in odd indices and inc by 2.
        if (A[i] < 0) {
            ans[negIndex] = A[i];
            negIndex += 2;
        }

        // Fill positive elements in even indices and inc by 2.
        else {
            ans[posIndex] = A[i];
            posIndex += 2;
        }
    }

    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> majorityElementBetter(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        } else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        } else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int> > threesum(int n, vector<int> &arr) {
    vector<vector<int> > ans;
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
            } else if (sum > 0) {
                k--;
            } else {
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
int subarrayswithgivenxorK(vector<int> &A, int B) {
    map<int, int> pre;
    int aggregate = 0;
    int result = 0;
    int n1 = A.size();
    for (int i = 0; i < n1; i++) {
        aggregate ^= A[i];
        if (aggregate == B) {
            result++;
        }
        if (pre.find(aggregate ^ B) != pre.end()) {
            result += pre[aggregate ^ B];
        }
        pre[aggregate]++;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int> > mergeOverlappingIntervals(vector<vector<int> > &arr) {
    //SAME THING BUIT HE USED A DIFFERENT ARRAY HENCE NO erase()
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int> > ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void merge2sortedarrayswith0atend(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int end = m + n - 1;

    int pointer1 = m - 1;
    int pointer2 = n - 1;

    while (pointer1 >= 0 && pointer2 >= 0) {
        if (nums1[pointer1] > nums2[pointer2]) {
            nums1[end] = nums1[pointer1];
            pointer1--;
        } else {
            nums1[end] = nums2[pointer2];
            pointer2--;
        }
        end--;
    }

    while (pointer2 >= 0) {
        nums1[end] = nums2[pointer2];
        pointer2--;
        end--;
    }
}

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge2sortedarrayswith0atendAnotherImplementation(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<int> findMissingandRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int mergeforinvertion(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low; // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSortforinvertion(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSortforinvertion(arr, low, mid); // left half
    cnt += mergeSortforinvertion(arr, mid + 1, high); // right half
    cnt += mergeforinvertion(arr, low, mid, high); // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> &a, int n) {
    // Count the number of pairs:
    return mergeSortforinvertion(a, 0, n - 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int maxProduct(vector<int> &arr) {
    auto size = arr.size();
    long long int prefix = 1;
    long long int suffix = 1;
    long long int result = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (suffix == 0) suffix = 1;
        if (prefix == 0) prefix = 1;
        suffix *= arr[size - i - 1];
        prefix *= arr[i];
        result = max(result, max(prefix, suffix));
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int lowerBoundfunction(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int upperBoundfunction(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1; // look on the right
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = arr[mid];
            //look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// l m h
// nums[m] > nums[l] && nums[m] > nums[h] pivot on right
// nums[m] < nums[l] && nums[m] < nums[h] pivot on left or middle
// else no pivot
// WE WERE SO CLOSE TO FINISHING THE QUESTION
// WHEN CHOOSING IF STATEMENTS ALWAYS CHOOSE THE SIMPLER SIDE
int searchinrotatedsortedarray(vector<int> &nums, int target) {
    int l = 0;
    int h = nums.size() - 1;
    int m = (l + h) / 2;
    while (l <= h) {
        m = (l + h) / 2;
        // cout << l << " " << m << " " << h << endl;
        if (nums[m] == target)return m;
        if (nums[h] == target)return h;
        if (nums[l] == target)return l;
        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m])h = m - 1;
            else l = m + 1;
        } else {
            if (nums[m] < target && target <= nums[h])l = m + 1;
            else h = m - 1;
        }
    }
    // cout << l << " " << m << " " << h << endl;
    return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool searchInARotatedSortedArrayII(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            } else {
                //element does not exist:
                low = mid + 1;
            }
        } else {
            //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            } else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int findMinBetter(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        } else {
            //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        } else {
            //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool searchElementIn2DMatrix(vector<vector<int> > &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string removeOuterParenthesesMoreReadable(string s) {
    // just more readable
    string result; // To store the final result
    int balance = 0; // To keep track of the balance of parentheses

    // Iterate through each character in the string
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            // If balance is greater than 0, it means this '(' is not an
            // outermost parenthesis
            if (balance > 0) {
                result += s[i]; // Add the character to the result
            }
            balance++; // Increase the balance for '('
        } else {
            balance--; // Decrease the balance for ')'
            // If balance is greater than 0, it means this ')' is not an
            // outermost parenthesis
            if (balance > 0) {
                result += s[i]; // Add the character to the result
            }
        }
    }

    return result; // Return the final result after removing outermost
    // parentheses
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isIsomorphic(string str1, string str2) {
    int MAX_CHARS = 256;
    int m = (int) str1.length(), n = (int) str2.length();
    // Length of both strings must be same for one to one
    // correspondence
    if (m != n)
        return false;
    // To mark visited characters in str2
    bool marked[MAX_CHARS] = {false};
    // To store mapping of every character from str1 to
    // that of str2. Initialize all entries of map as -1.
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
    // Process all characters one by one
    for (int i = 0; i < n; i++) {
        // If current character of str1 is seen first
        // time in it.
        if (map[str1[i]] == -1) {
            // If current character of str2 is already
            // seen, one to one mapping not possible
            if (marked[str2[i]] == true)
                return false;

            // Mark current character of str2 as visited
            marked[str2[i]] = true;

            // Store mapping of current characters
            map[str1[i]] = str2[i];
        }
        // If this is not first appearance of current
        // character in str1, then check if previous
        // appearance mapped to same character of str2
        else if (map[str1[i]] != str2[i])
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool rotateString(string s, const string &goal) {
    int sl = (int) s.length(), gl = (int) goal.length();
    if (sl != gl)return false;
    for (int i = 0; i < sl; i++) {
        s += s[i];
        if (s.substr(i + 1, sl + 1) == goal)return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int beautySumBetter(string s) {
    int ans = 0;

    //iterating over each character of the string.
    for (auto i = 0; i < s.size(); ++i) {
        int cnt[26] = {}, max_f = 0, min_f = 0;

        //iterating over subarrays starting from i.
        for (auto j = i; j < s.size(); ++j) {
            int idx = s[j] - 'a';
            //updating maximum frequency.
            max_f = max(max_f, ++cnt[idx]);

            //updating minimum frequency.
            // if (min_f >= cnt[idx] - 1) {
            min_f = cnt[idx];
            for (int k = 0; k < 26; ++k)
                //finding minimum frequency of all characters.
                min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
            //  }

            //adding the difference between maximum and minimum frequency.
            ans += max_f - min_f;
        }
    }

    //returning the beauty sum.
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ListNode *reverseListRecursive(ListNode *head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursive step:
    // Reverse the linked list starting
    // from the second node (head->next).
    ListNode *newHead = reverseListRecursive(head->next);

    // Save a reference to the node following
    // the current 'head' node.
    ListNode *front = head->next;

    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;

    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;

    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool detectCycleOrnNot(ListNode *head) {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    ListNode *slow = head;
    ListNode *fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true; // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ListNode *detectCycleAndReturnlistNode(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr && slow != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!(fast && fast->next))
        return nullptr;
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }
    return slow;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node *DeleteNthNodefromEnd(Node *head, int N) {
    // Create two pointers, fastp and slowp
    Node *fastp = head;
    Node *slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? headB : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
    }
    return ptr1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// int helperForadddOne(Node *temp) {
//     if (temp == NULL) return 1;
//     int carry = helperForadddOne(temp->next);
//     temp->data += carry;
//     if (temp->data < 10) return 0;
//     temp->data = 0;
//     return 1;
// }

// Node *addOne(Node *head) {
//     int carry = helperForadddOne(head);
//     if (carry == 1) {
//         Node *newNode = new Node(1);
//         newNode->next = head;
//         head = newNode;
//     }
//     return head;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long powerforCountGN(long long num, long long exp, long long result) {
    if (exp == 0) return result;
    if (exp & 1) return powerforCountGN(num, exp - 1, (result * num) % 1);
    else return powerforCountGN((num * num) % 1, exp / 2, result);
}

int countGoodNumbers(long long n) {
    long long temp = powerforCountGN(20, n / 2, 1);
    return (n & 1) ? (temp * 5) % 1 : temp;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int helperforfindxor(int n) {
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    if (n % 4 == 3) return 0;
    return n;
}


int findXOR(int l, int r) {
    return helperforfindxor(l - 1) ^ helperforfindxor(r);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<long long int> twoOddNum(const long long int arr[], long long int N) {
    long s = 0;
    for (int i = 0; i < N; i++) s = s ^ arr[i];
    int right = (s & s - 1) ^ s;
    long long int b1 = 0, b2 = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] & right) b1 ^= arr[i];
        else b2 ^= arr[i];
    }
    if (b1 > b2) return {b1, b2};
    return {b2, b1};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
