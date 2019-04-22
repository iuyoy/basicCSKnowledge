#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &nums, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        vector<int> left(nums.begin() + l, nums.begin() + mid + 1),
            right(nums.begin() + mid + 1, nums.begin() + r + 1);
        for (int i = 0, j = 0; l <= r; ++l) {
            if (i < left.size() && j < right.size()) {
                if (left[i] > right[j]) {
                    nums[l] = right[j++];
                } else
                    nums[l] = left[i++];
            } else if (i < left.size())
                nums[l] = left[i++];
            else
                nums[l] = right[j++];
        }
    }
}

int main() {
    vector<int> nums = {2, 3, 1, 4, 5};
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    mergeSort(nums, 0, nums.size());

    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}