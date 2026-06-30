#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/

Approaches:
1. Sorting
    TC = O(m * n log n)
    SC = O(m * n)

2. Hash Table
    TC = O(m * n)
    SC = O(m) auxiliary space, excluding the returned output
         O(m ∗ n) total space if the output groups are counted
===========================================================
*/

// --------------------- Sorting --------------------------
vector<vector<string>> group_anagrams(vector<string> &strs) {
  map<string, vector<string>> map;
  for (string &s : strs) {
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    map[sorted_s].push_back(s);
  }

  vector<vector<string>> ans;
  for (auto &[x, y] : map) {
    ans.push_back(y);
  }
  return ans;
}

// ---------------- Hash Table ----------------------------
vector<vector<string>> hash_map(vector<string> &strs) {
  unordered_map<string, vector<string>> map;
  for (const string &s : strs) {
    vector<int> count(26);
    for (char ch : s) {
      count[ch - 'a']++;
    }

    string key = to_string(count[0]);
    for (int i = 1; i < 26; ++i) {
      key += ',' + to_string(count[i]);
    }
    map[key].push_back(s);
  }

  vector<vector<string>> ans;
  for (auto &[x, y] : map) {
    ans.push_back(y);
  }
  return ans;
}

// --------------------------------------------------------
int main() {
  int n;
  cin >> n;

  vector<string> strs(n);
  for (string &s : strs) {
    cin >> s;
  }

  group_anagrams(strs);
}
