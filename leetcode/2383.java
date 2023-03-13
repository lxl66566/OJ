import java.util.stream.IntStream;
class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int energySum = IntStream.of(energy).sum();
        var ans = 0;
        if (energySum >= initialEnergy)
            ans += energySum - initialEnergy + 1;
        for (var i : experience)
        {
            if (initialExperience <= i){
                ans += i - initialExperience + 1;
                initialExperience = i + 1;
            }
            initialExperience += i;
        }
        return ans;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.minNumberOfHours(5,3,new int[] {1,4,3,2},new int[] {2,6,3,1}));
    }
}