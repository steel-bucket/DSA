#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        int current = nums[i];
        int diff = target - nums[i];
    }

}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    for (int i: nums)cout << i << " ";
    cout << endl;
    vector<int> ts = twoSum(nums, 9);
    for (int i: ts)cout << i << " ";
    return 0;
}
