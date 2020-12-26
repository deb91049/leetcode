# 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
#
#  
#
# 示例 1：
#
# 输入：timePoints = ["23:59","00:00"]
# 输出：1
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/minimum-time-difference
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        d = set()
        for c in timePoints:
            k = int(c[: 2]) * 60 + int(c[3: ])
            if k in d:
                return 0
            d.add(k)
        d = sorted(d)
        d.append(d[0] + 1440)
        return min(d[i] - d[i - 1] for i in range(1, len(d)))