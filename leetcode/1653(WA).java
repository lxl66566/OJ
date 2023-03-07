class Solution {
    public int minimumDeletions(String s) {
        int i,j;
        for(i = 0;i < s.length();++i)
        {
            if (s.charAt(i) == 'b') break;
        }
        for(j = s.length()-1;j >= 0;--j)
        {
            if (s.charAt(j) == 'a') break;
        }
        int a = 0;
        int b = 0;
        for (int k = i;k <= j;++k)
        {
            if (s.charAt(k) == 'a')
            {
                a++;
            }
            else if (s.charAt(k) == 'b')
            {
                b++;
            }
        }
        System.err.println(a);
        System.err.println(b);
        return Math.min(a,b);
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.minimumDeletions("ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa"));
    }
}