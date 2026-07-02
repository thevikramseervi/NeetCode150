#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Products of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/

Approaches:
1. Brute Force
    TC = O(n^2)
    SC = O(1)

2. Optimal prefix & suffix
    TC = O(n)
    SC = O(1) - extra space
         O(n) - space for output array
===========================================================
*/

// -------------------- Brute Force -----------------------
vector<int> productExceptSelf_bruteForce(vector<int> &nums) {
  vector<int> res;
  for (int i = 0; i < nums.size(); ++i) {
    int val = 1;
    for (int j = 0; j < nums.size(); ++j) {
      if (i != j) {
        val = val * nums[j];
      }
    }
    res.push_back(val);
  }
  return res;
}

// --------------------- Optimal --------------------------
vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> res(n);
  res[0] = 1;
  for (int i = 1; i < n; ++i) {
    res[i] = res[i - 1] * nums[i - 1];
  }
  int postfix = 1;
  for (int i = n - 1; i >= 0; --i) {
    res[i] *= postfix;
    postfix *= nums[i];
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 4, 6};
  productExceptSelf(nums);
}
