#include <bits/stdc++.h>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    unordered_map<int, int> um;
    vector<int> res;

    // Map element to its index
    for (int i = 0; i < nums.size(); ++i) {
        um[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {

        // Check if the complement exists in the map
        auto it = um.find(target - nums[i]);
        if (it != um.end() && it->second != i) {
            res.push_back(nums[i]);
            res.push_back(nums[it->second]);
            break;
        }
    }

    return res;
}

int three_sum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        // Check if the complement can be built by using two other elements
        auto res = two_sum(nums, target - nums[i]);
        if (res.size()) {
            return nums[i] * res[0] * res[1];
        }
    }
    return 0;
}

int main() {
    ifstream in;
    in.open("day1.in");
    std::vector<int> nums;

    while(!in.eof()) {
        int num;
        in >> num;
        nums.push_back(num);
    }

    std::cout << three_sum(nums, 2020) << "\n";
    in.close();
}
