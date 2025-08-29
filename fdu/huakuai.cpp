//
// Created by 20143 on 2025/8/30.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> find_median_of_unique(const vector<int>& nums) {
    unordered_map<int, int> freq_map;
    // 统计每个数字的出现次数
    for (int num : nums) {
        freq_map[num]++;
    }

    vector<int> unique_nums;
    // 找出所有独立数（出现次数为1的元素）
    for (auto& entry : freq_map) {
        if (entry.second == 1) {
            unique_nums.push_back(entry.first);
        }
    }

    if (unique_nums.empty()) {
        return {-1};  // 返回 -1 表示没有独立数
    }

    // 对独立数进行排序
    sort(unique_nums.begin(), unique_nums.end());

    int n = unique_nums.size();
    // 计算中位数
    if (n % 2 == 1) {
        return {unique_nums[n / 2]};  // 奇数个独立数，返回中间的元素
    } else {
        int mid = n / 2;
        return {(unique_nums[mid - 1] + unique_nums[mid]) / 2};  // 偶数个独立数，返回中间两个元素的平均值
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for (int i = 0; i <= n - m; ++i) {
        vector<int> window(nums.begin() + i, nums.begin() + i + m);
        vector<int> result = find_median_of_unique(window);

        if (result[0] == -1) {
            cout << "No" << endl;
        } else {
            cout << result[0] << endl;
        }
    }

    return 0;
}
