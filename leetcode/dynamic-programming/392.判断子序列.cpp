/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (52.42%)
 * Likes:    929
 * Dislikes: 0
 * Total Accepted:    331.5K
 * Total Submissions: 632.4K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 *
 *
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 *
 * 进阶：
 *
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 *
 * 致谢：
 *
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * 0
 * 两个字符串都只由小写字符组成。
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
/**
 * 双指针最简单
 *
 * dp 也可以，为编辑距离做基础
 */
class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        {
            /**
             * 双指针 简单
             */
            uint16_t i = 0;
            for (uint16_t j = 0; j < t.size(); j++)
            {
                if (t[j] == s[i])
                {
                    i++;
                    if (i >= s.size())
                        break;
                }
            }
            return i == s.size() ? true : false;
        }

        {
            /**
             * dp 没必要，但是只是为了给编辑距离最铺垫
             */
            vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

            for (int i = 1; i < s.size() + 1; i++)
            {
                for (int j = 1; j < t.size() + 1; j++)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
            return dp[s.size()][t.size()] == s.size() ? true : false;
        }
    }
};
// @lc code=end
