/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.40%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 22.9K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 示例 1:
 * 
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2:
 * 
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        if (s.size() < t.size())
            return 0;
        int time;
        IterCount(s, 0, t, 0, time);
        return time;
    }
    void IterCount(std::string s, int first, std::string t, int second, int &time)
    {
        if (first > s.size())
        {
            time++;
            return;
        }
        if (second > t.size())
            return;
        if (s[first] == t[second])
        {
            IterCount(s, first + 1, t, second + 1, time);
            IterCount(s, first, t, second + 1, time);
        }
        else
        {
            IterCount(s, first, t, second + 1, time);
            //IterCount(s, first + 1, t, second, time);
        }
    }
};
*/
class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        if (s.size() < t.size())
            return 0;
        std::vector<std::vector<int>> vecList(t.size() + 1, std::vector<int>(s.size() + 1, 0));
        for (int i = 0; i < s.size() + 1; i++)
            vecList[0][i] = 1;
        for (int i = 1; i < t.size() + 1; i++)
            vecList[i][0] = 0;
        /*
        for (int i = 0; i < vecList.size(); i++)
        {
            for (int j = 0; j < vecList[0].size(); j++)
                std::cout << vecList[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */
        for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (t[i] == s[j])
                    vecList[i + 1][j + 1] = vecList[i][j] + vecList[i + 1][j];
                else
                    vecList[i + 1][j + 1] = vecList[i + 1][j];
            }
        }
        /*
        for (int i = 0; i < vecList.size(); i++)
        {
            for (int j = 0; j < vecList[0].size(); j++)
                std::cout << vecList[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */
        return vecList[t.size()][s.size()];
    }
};
/*
int main()
{
    std::string first("rabbbit"), second("rabbit");
    std::cout << Solution().numDistinct(first, second) << std::endl;
    return 0;
}
*/
// @lc code=end
