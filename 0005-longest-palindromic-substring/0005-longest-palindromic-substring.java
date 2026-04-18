class Solution {
    private int expandFromCenter(String s, int l, int r){
        while(l >= 0 && r < s.length() && (s.charAt(l) == s.charAt(r))){
            l--;
            r++;
        }
        return r-l-1;
    }
    public String longestPalindrome(String s) {
        if(s == null || s.isEmpty()) return "";

        int start = 0;
        int end = 0;
        for(int i=0;i<s.length();i++){
            int odd = expandFromCenter(s,i,i);
            int even = expandFromCenter(s,i,i+1);
            int mx = Math.max(odd, even);

            if(mx > end-start){
                start = i - (mx-1)/2;
                end = i + (mx)/2;
            }
        }
        return s.substring(start, end+1);
    }
}