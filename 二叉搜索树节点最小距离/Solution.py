# 给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
#
#  
#
# 示例：
#
# 输入: root = [4,2,6,1,3,null,null]
# 输出: 1
# 解释:
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution(object):
    def minDiffInBST(self, root):
        vals = []
        def dfs(node):
            if node:
                vals.append(node.val)
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        vals.sort()
        return min(vals[i+1] - vals[i]
                   for i in range(len(vals) - 1))
