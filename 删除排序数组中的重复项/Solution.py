# 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
#
# 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
#
#  
#
# 示例 1:
#
# 给定数组 nums = [1,1,2],
#
# 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
#
# 你不需要考虑数组中超出新长度后面的元素。
#
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
# 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # 双指针做法
        # 若p和q位置元素相等，则q向后移动一位
        # 若p和q位置元素不等，则p+1位置元素替换为q位置元素，且p，q均向后移动一位
        # 循环之后q=数组长度
        # 返回前p+1个位置元素
        p, q = 0, 1
        while(q<len(nums)):
            if nums[p] == nums[q]:
                q = q + 1
            else:
                nums[p+1] = nums[q]
                p = p + 1
                q = q + 1
        return len(nums[0:p+1])
