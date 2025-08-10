class Solution {
private:
    string conv(int a){
        string s = to_string(a);
        sort(s.begin(), s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = conv(n);

        for(int p=0; p<=29; p++){
            if(s == conv(1<<p)) return true;
        }
        return false;
    }
};