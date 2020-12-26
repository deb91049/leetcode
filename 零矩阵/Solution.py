# 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
#
#  
#
# 示例 1：
#
# 输入：
# [
#   [1,1,1],
#   [1,0,1],
#   [1,1,1]
# ]
# 输出：
# [
#   [1,0,1],
#   [0,0,0],
#   [1,0,1]
# ]
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/zero-matrix-lcci
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution:
    def setZeroes(self, matrix):
        row, column = len(matrix) * [0], len(matrix[0]) * [0]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    row[i] = 1
                    column[j] = 1
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if row[i] == 1 or column[j] == 1:
                    matrix[i][j] = 0