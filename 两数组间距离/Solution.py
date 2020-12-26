# 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
#
# 「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。
#
#  
#
# 示例 1：
#
# 输入：arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
# 输出：2
# 解释：
# 对于 arr1[0]=4 我们有：
# |4-10|=6 > d=2
# |4-9|=5 > d=2
# |4-1|=3 > d=2
# |4-8|=4 > d=2
# 所以 arr1[0]=4 符合距离要求
#
# 对于 arr1[1]=5 我们有：
# |5-10|=5 > d=2
# |5-9|=4 > d=2
# |5-1|=4 > d=2
# |5-8|=3 > d=2
# 所以 arr1[1]=5 也符合距离要求
#
# 对于 arr1[2]=8 我们有：
# |8-10|=2 <= d=2
# |8-9|=1 <= d=2
# |8-1|=7 > d=2
# |8-8|=0 <= d=2
# 存在距离小于等于 2 的情况，不符合距离要求
#
# 故而只有 arr1[0]=4 和 arr1[1]=5 两个符合距离要求，距离值为 2
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/find-the-distance-value-between-two-arrays
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        cnt = 0
        for x in arr1:
            if all(abs(x - y) > d for y in arr2):
                cnt += 1
        return cnt
