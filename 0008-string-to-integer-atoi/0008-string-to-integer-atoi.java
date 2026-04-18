class Solution {
    static int mx = 2147483647, mn = -2147483648;
    static int helper(String s, int i, long res, int sign){
        if(i >= s.length() || !Character.isDigit(s.charAt(i)))
            return (int)(sign*res);
        res = res*10 + (s.charAt(i) - '0');

        if(sign*res >= mx) return mx;
        if(sign*res <= mn) return mn;

        return helper(s, i+1, res, sign);
    }
    public int myAtoi(String s) {
        int i=0;
        while(i < s.length() && (s.charAt(i) == ' ')) i++;
        
        int sign = 1;
        if(i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')){
            sign = (s.charAt(i) == '+')? 1:-1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
}