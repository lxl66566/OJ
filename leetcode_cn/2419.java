import java.util.Arrays;
class Solution {
    public int longestSubarray(int[] nums) {
        int max = Arrays.stream(nums).max().getAsInt();
        var longest = 0;
        var current = -1;
        for (int i = 0; i < nums.length; i++) {
            if ((nums[i] & max) == max)
            {
                if (current == -1) current = i;
            }
            else {
                if (current != -1) {
                    longest = Math.max(longest, i - current);
                    current = -1;
                }
            }
        }
        return Math.max(longest, current != -1 ? nums.length - current : 0);
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestSubarray(new int[]{1,1,2,3,3,2,1,2}));
    }
}