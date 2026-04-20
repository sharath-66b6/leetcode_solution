class Solution {
    public String reverseWords(String s) {
        String[] ss = s.split(" ");
        String res = "";
        for(int i=ss.length-1; i>=0; i--){
            if(ss[i] != "")
                res += ss[i] + " ";
        }
        return res.substring(0,res.length()-1);
    }
}