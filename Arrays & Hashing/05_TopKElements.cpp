#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

/*
===========================================================
Problem: Top k Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements/

Approaches:
1. Sorting
    TC = O(n log n)
    SC = O(n)

2. Min Heap
    TC = O(n log k)
    SC = O(n + k)

3. Bucket Sort
    TC = O(n)
    SC = O(n)
===========================================================
*/

// -------------------- Sorting ---------------------------
vector<int> topKFrequent_sorting(vector<int> &nums, int k) {
  unordered_map<int, int> count;
  for (int num : nums) {
    count[num]++;
  }

  vector<pair<int, int>> arr;
  for (const auto &p : count) {
    arr.push_back({p.second, p.first});
  }
  sort(arr.rbegin(), arr.rend());

  vector<int> res;
  for (int i = 0; i < k; ++i) {
    res.push_back(arr[i].second);
  }
  return res;
}

// ------------------- Min Heap ---------------------------
vector<int> topKFrequent_minHeap(vector<int> &nums, int k) {
  unordered_map<int, int> cnt;
  for (int num : nums) {
    cnt[num]++;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
  for (auto &[num, freq] : cnt) {
    min_heap.push({freq, num});
    if (min_heap.size() > k) {
      min_heap.pop();
    }
  }

  vector<int> res;
  for (int i = 0; i < k; ++i) {
    res.push_back(min_heap.top().second);
    min_heap.pop();
  }
  return res;
}

// ------------------ Bucket Sort -------------------------
vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> cnt;
  vector<vector<int>> buckets(nums.size() + 1);

  for (int num : nums) {
    cnt[num]++;
  }

  for (auto &[num, freq] : cnt) {
    buckets[freq].push_back(num);
  }

  vector<int> res;
  for (int j = buckets.size() - 1; j >= 0 && res.size() < k; --j) {
    for (int num : buckets[j]) {
      res.push_back(num);
      if (res.size() >= k) {
        break;
      }
    }
  }
  return res;
}

int main() {
  vector<int> nums = {1, 2, 2, 3, 3, 3};
  int k = 2;

  for (auto &it : topKFrequent(nums, k)) {
    cout << it << ' ';
  }
}
