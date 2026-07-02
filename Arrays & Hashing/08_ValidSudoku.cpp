#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Valid Sudoku
Link: https://leetcode.com/problems/valid-sudoku/

Approaches:
1. Brute Force
    TC = O(n^2)
    SC = O(n)

2. Hash Set(One Pass)
    TC = O(n^2)
    SC = O(n^2)

3. BitMask
    TC = O(n^2)
    SC = O(n)
===========================================================
*/

// -------------------- Brute Force -----------------------

class Solution1 {
public:
  bool is_valid_row(vector<vector<char>> &board, int r) {
    unordered_set<char> set;
    for (int j = 0; j < board.size(); ++j) {
      if (board[r][j] == '.')
        continue;
      if (set.count(board[r][j]))
        return false;
      set.insert(board[r][j]);
    }
    return true;
  }

  bool is_valid_col(vector<vector<char>> &board, int c) {
    unordered_set<char> set;
    for (int i = 0; i < board.size(); ++i) {
      if (board[i][c] == '.')
        continue;
      if (set.count(board[i][c]))
        return false;
      set.insert(board[i][c]);
    }
    return true;
  }

  bool is_valid_box(vector<vector<char>> &board, int x, int y) {
    unordered_set<char> set;
    for (int i = x; i < x + 3; ++i) {
      for (int j = y; j < y + 3; ++j) {
        if (board[i][j] == '.')
          continue;
        if (set.count(board[i][j]))
          return false;
        set.insert(board[i][j]);
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      if (!is_valid_row(board, i))
        return false;
      if (!is_valid_col(board, i))
        return false;
    }

    // (0,0) (0,3) (0,6)
    // (3,0) (3,3) (3,6)
    // (6,0) (6,3) (6,6)

    for (int i = 0; i < board.size(); i += 3) {
      for (int j = 0; j < board.size(); j += 3) {
        if (!is_valid_box(board, i, j))
          return false;
      }
    }

    return true;
  }
};

// ------------------ Hash Set(One Pass) ------------------
class Solution2 {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<unordered_set<char>> row(board.size());
    vector<unordered_set<char>> col(board.size());
    vector<unordered_set<char>> box(board.size());

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board.size(); ++j) {
        char x = board[i][j];
        if (x == '.')
          continue;

        if (row[i].count(x))
          return false;
        row[i].insert(x);

        if (col[j].count(x))
          return false;
        col[j].insert(x);

        int st_r = i - i % 3;

        if (box[j / 3 + st_r].count(x))
          return false;
        box[j / 3 + st_r].insert(x);
      }
    }
    return true;
  }
};

// -------------------- Bitmask ---------------------------
class Solution3 {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows[9] = {0};
    int cols[9] = {0};
    int squares[9] = {0};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          continue;
        }

        int val = board[i][j] - '1';

        if ((rows[i] & (1 << val)) || (cols[j] & (1 << val)) ||
            (squares[(i / 3) * 3 + (j / 3)] & (1 << val))) {
          return false;
        }

        rows[i] |= (1 << val);
        cols[j] |= (1 << val);
        squares[(i / 3) * 3 + (j / 3)] |= (1 << val);
      }
    }
    return true;
  }
};

int main() {}
