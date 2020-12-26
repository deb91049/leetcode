# 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
#
# 示例 1：
#
# 输入: s1 = "abc", s2 = "bca"
# 输出: true
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/check-permutation-lcci
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        from functools import reduce
        return not bool(reduce(lambda a, b: a ^ b, map(ord, s1 + s2)))