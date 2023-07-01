/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (37.03%)
 * Likes:    6029
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 *
 * 你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
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
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {

        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 排序
        // 找出a + b + c = 0: a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] > 0)
            { // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
                break;
            }

            // 先去重复 a ；如果和前一个数一样，那么可能重复
            // [0,1,1,2,3] 两个 1 重复
            if (i > 0 && (nums[i] == nums[i - 1]))
            {
                continue;
            }

            int pl = i + 1;
            int pr = nums.size() - 1;
            while (pl < pr)
            {
                if (nums[i] + nums[pl] + nums[pr] > 0) // 如果 和大于0 需要右边缩小
                {
                    pr--;
                }
                else if (nums[i] + nums[pl] + nums[pr] < 0)
                {
                    pl++;
                }
                else // 等于 0 去重复
                {
                    result.push_back(vector<int>{nums[i], nums[pl], nums[pr]});


                    // 去重复

                    // 移动左指针后，保证当前的，和左边一个不重复
                    pl++;
                    while (pl < pr && nums[pl] == nums[pl - 1])
                    {
                        pl++;
                    }

                    pr--;
                    while (pl < pr && nums[pr] == nums[pr + 1])
                    {
                        pr--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
