#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Approaches:
1. BruteForce
TC = O(n^2)
SC = O(1)

2. Sorting
TC = O(n log n)
SC = O(1)

3. HashSet or HashMap (actually hash set is better in this case as frequency of elements not required)
TC = O(n)
SC = O(n)
===========================================================
*/

// ------------------- Brute Force ------------------------
bool brute_force(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

// --------------------- Sorting --------------------------
bool sorting(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; ++i)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

// -------------------- Hash Set --------------------------
bool hash_set(vector<int> &nums)
{
    return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << brute_force(nums) << "\n";
    cout << sorting(nums) << "\n";
    cout << hash_set(nums) << "\n";
}
