# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
#
#  
#
# 示例 1：
#
#
#
# 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
# 输出：6
# 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
# 示例 2：
#
# 输入：height = [4,2,0,3,2,5]
# 输出：9
#  
#
# 提示：
#
# n == height.length
# 0 <= n <= 3 * 104
# 0 <= height[i] <= 105
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/trapping-rain-water
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        if len(height) <= 1:
            return 0

        max_height = 0
        max_height_index = 0

        # 找到最高点
        for i in range(len(height)):
            h = height[i]
            if h > max_height:
                max_height = h
                max_height_index = i

        area = 0

        # 从左边往最高点遍历
        tmp = height[0]
        for i in range(max_height_index):
            if height[i] > tmp:
                tmp = height[i]
            else:
                area = area + (tmp - height[i])

        # 从右边往最高点遍历
        tmp = height[-1]
        for i in reversed(range(max_height_index + 1, len(height))):
            if height[i] > tmp:
                tmp = height[i]
            else:
                area = area + (tmp - height[i])

        return area
    print(trap("",[0,1,0,2,1,0,1,3,2,1,2,1]))