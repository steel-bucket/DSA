#include <bits/stdc++.h>
using namespace std;

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


int main() {
    vector<int> nums = {-3,2,4,5,-6};
    for (auto &i: nums)cout << i << " ";
    cout << endl;
    int result = maxProduct(nums);
    cout << result;
    return 0;
}
