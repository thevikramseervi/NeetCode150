#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/

Approaches:
1. Sorting
    TC = O(n log n)
    SC = O(1)

2. Hash Map
    TC = O(n)
    SC = O(1)

3. Hash Table using Array
    TC = O(n)
    SC = O(1)

===========================================================
*/

// --------------------- Sorting --------------------------
bool sorting(string &s, string &t) {
  if (s.length() != t.length()) {
    return false;
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

// -------------------- Hash Map --------------------------
bool hash_map(string &s, string &t) {
  if (s.length() != t.length()) {
    return false;
  }

  unordered_map<char, int> scnt;
  unordered_map<char, int> tcnt;
  for (char ch : s) {
    scnt[ch]++;
  }
  for (char ch : t) {
    tcnt[ch]++;
  }
  return scnt == tcnt;
}

// --------------- Hash Table using Array -----------------
bool array_map(string &s, string &t) {
  vector<int> cnt(26);
  for (char ch : s) {
    cnt[ch - 'a']++;
  }
  for (char ch : t) {
    cnt[ch - 'a']--;
  }

  for (int val : cnt) {
    if (val != 0)
      return false;
  }
  return true;
}

int main() {
  int slen, tlen;
  cin >> slen >> tlen;

  string s, t;
  cin >> s >> t;

  cout << sorting(s, t) << endl;
  cout << hash_map(s, t) << endl;
  cout << array_map(s, t) << endl;
}
