# 你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
#
# 为了使收益最大化，矿工需要按以下规则来开采黄金：
#
# 每当矿工进入一个单元，就会收集该单元格中的所有黄金。
# 矿工每次可以从当前位置向上下左右四个方向走。
# 每个单元格只能被开采（进入）一次。
# 不得开采（进入）黄金数目为 0 的单元格。
# 矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
#  
#
# 示例 1：
#
# 输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
# 输出：24
# 解释：
# [[0,6,0],
#  [5,8,7],
#  [0,9,0]]
# 一种收集最多黄金的路线是：9 -> 8 -> 7。
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/path-with-maximum-gold
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution:
    def __init__(self):
        self.max_value=[]
        self.log=[]
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        a,b=len(grid)-1,len(grid[0])-1
        def DFS(i,j,v,a,b):
            if [i,j] in self.log:
                return
            if i<0 or j<0 or i>a or j>b or grid[i][j]==0:
                self.max_value.append(v)
                return
            self.log.append([i,j])
            DFS(i-1,j,v+grid[i][j],a,b)
            DFS(i,j-1,v+grid[i][j],a,b)
            DFS(i+1,j,v+grid[i][j],a,b)
            DFS(i,j+1,v+grid[i][j],a,b)
            self.log.remove([i,j])
        for i in range(a+1):
            for j in range(b+1):
                DFS(i,j,0,a,b)
        return max(self.max_value)