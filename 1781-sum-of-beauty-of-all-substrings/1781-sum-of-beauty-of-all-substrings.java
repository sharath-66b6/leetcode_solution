class Solution {
    private int findBeauty(String s){
        Map<Character, Integer> m = new HashMap<>();
        int mx = Integer.MIN_VALUE,  mn = Integer.MAX_VALUE;
        for(int i=0;i<s.length(); i++){
            char c = s.charAt(i);
            m.put(c, m.getOrDefault(c, 0)+1);
        }

        for(int i=0;i<s.length(); i++){
            char c = s.charAt(i);
            mx = Math.max(mx, m.get(c));
            mn = Math.min(mn, m.get(c));
        }
        return mx-mn;
    }
    public int beautySum(String s) {
        int sum = 0;
        for(int i=0; i<s.length(); i++){
            int freq[] = new int[26];
            for(int j=i; j<s.length(); j++){
                char c = s.charAt(j);
                freq[c-'a']++;
                int mx = Integer.MIN_VALUE,  mn = Integer.MAX_VALUE;
                for(int k=0; k<26; k++){
                    if(freq[k] > 0){
                        mx = Math.max(mx, freq[k]);
                        mn = Math.min(mn, freq[k]);
                    }
                }
                sum += (mx - mn);
            }
        }
        return sum;
    }
}