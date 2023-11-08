class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        var max = nums[nums.length - 1];
        int [] bucket = new int[max + 1];
        for(var i : nums)
            bucket[i] = 1;
        var ans = 0;
        for(var i : nums)
        {
            if(i + diff + diff <= max  && bucket[i + diff + diff] != 0 && bucket[i + diff] != 0)
                ans ++;
        }
        return ans;
    }
    public static void main(String[] args) {
        
    }
}