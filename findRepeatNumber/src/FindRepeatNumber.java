import java.util.Scanner;

/**
 * 剑指 Offer 03. 数组中重复的数字
 * 找出数组中重复的数字。
 *
 *
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 *
 * 示例 1：
 *
 * 输入：
 * [2, 3, 1, 0, 2, 5, 3]
 * 输出：2 或 3
 *
 *
 * 限制：
 *
 * 2 <= n <= 100000
 *
 * 通过次数157,552提交次数233,909*/

public class FindRepeatNumber {
    public static void main(String[] args) {
       int[] nums= {2, 3, 1, 0, 2, 5, 3};
       FindRepeatNumber find=new FindRepeatNumber();
        System.out.println( find.findRepeatNumber(nums));

    }

    public int findRepeatNumber(int[] nums) {
        int temp=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }else {
                    temp=nums[i];
                    nums[i]=nums[temp];
                    nums[temp]=temp;
                }
            }
        }
        return -1;
    }
}
/**
 * 原地置换
 * num[i]的位置如果不是i,那么num[i]与num[num[i]]交换，
 * 且交换时发现num[i]==num[num[i]]
 * 则说明num[i]是重复的
 * */