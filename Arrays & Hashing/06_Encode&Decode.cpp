#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
===========================================================
Problem: Encode and Decode Strings
Link   : https://leetcode.com/problems/encode-and-decode-strings/


Approaches:
1. Encoding & Decoding
    TC = O(m + n);
    SC = O(m + n);

2. Optimal
    TC = O(m + n)
    SC = O(m + n)
===========================================================
*/

// ----------- Storing all sizes at start of string -------------------
string encode(vector<string> &strs) {
  int n = strs.size();
  vector<int> sizes;
  string res;

  for (string &str : strs) {
    sizes.push_back(str.size());
  }

  for (int sz : sizes) {
    res.append(to_string(sz));
    res.push_back(',');
  }
  res.push_back('#');

  for (string &str : strs) {
    res.append(str);
  }
  return res;
}

vector<string> decode(string s) {
  vector<int> sizes;

  int sz = 0;
  for (char ch : s) {
    if (ch == '#')
      break;
    if (ch == ',') {
      sizes.push_back(sz);
      sz = 0;
    } else {
      sz = sz * 10 + (ch - '0');
    }
  }

  int start = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '#') {
      start = i + 1;
      break;
    }
  }

  vector<string> res;
  for (int sz : sizes) {
    res.push_back(s.substr(start, sz));
    start += sz;
  }
  return res;
}

// ------- Storing size at the start of each string -------
string encode_optimal(vector<string> &strs) {
  string s = "";
  for (string &s : strs) {
    s += to_string(s.size());
    s += '#';
  }
  return s;
}

vector<string> decode_optimal(string s) {
  string size = "";
  vector<string> res;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '#') {
      int sz = stoi(size);
      string str = s.substr(i + 1, sz);
      res.push_back(str);
      size = "";
      i += sz;
    } else {
      size += s[i];
    }
  }
  return res;
}

int main() {
  int n;
  //   cin >> n;
  vector<string> strs = {"Hello", "World"};

  string encoded_strs = encode(strs);
  vector<string> decoded_strs = decode(encoded_strs);

  cout << endl;
  return 0;
}
