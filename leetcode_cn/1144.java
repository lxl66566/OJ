import java.util.ArrayList;
import java.util.Collections;
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int ans1 = one_side(nums, 0);
        int ans2 = one_side(nums, 1);
        System.out.println(ans1 + " " + ans2);
        return Math.min(ans1,ans2);
    }
    int one_side(int[] nums,int start){
        int ans = 0;
        for(int i = start;i<nums.length;i += 2){
            ArrayList<Integer> list = new ArrayList<>();
            if(i > 0 && nums[i - 1] <= nums[i]){
                list.add(nums[i] - nums[i - 1] + 1);
            }
            if(i < nums.length - 1 && nums[i + 1] <= nums[i]){
                list.add(nums[i] - nums[i + 1] + 1);
            }
            if(!list.isEmpty()) ans += Collections.max(list);
        }
        return ans;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2,7,10,9,8,9};
        System.out.println(solution.movesToMakeZigzag(nums));
    }
}