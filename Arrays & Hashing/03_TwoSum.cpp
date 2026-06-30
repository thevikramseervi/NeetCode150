#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/

Approaches:
1. Brute Force
    TC = O(n ^ 2)
    SC = O(1)

2. Two Pointers
    TC = O(n log n)
    SC = O(n)

3. Hash Map
    TC = O(n)
    Sc = O(n)

===========================================================
*/

// ----------------- Brute Force --------------------------
vector<int> bruteforce(vector<int> &nums, int target) {
  int n = nums.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {};
}

// --------------------- Two Pointers ---------------------
vector<int> two_pointers(vector<int> &nums, int target) {
  int n = nums.size();
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = {nums[i], i};
  }
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[l].first + a[r].first < target) {
      l++;
    } else if (a[l].first + a[r].first > target) {
      r--;
    } else {
      break;
    }
  }
  return {a[l].second, a[r].second};
}

// ------------------ Hash Map ----------------------------
vector<int> hash_map(vector<int> &nums, int target) {
  int n = nums.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x = target - nums[i];
    if (mp[x]) {
      return {mp[x] - 1, i};
    }
    mp[nums[i]] = i + 1;
  }
  return {};
}

// ---------------------- Hash Map ------------------------

int main() {
  int n, target;
  cin >> n >> target;

  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
}
