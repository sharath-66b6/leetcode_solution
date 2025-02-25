class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while(i<j){
            int x = target - numbers[i];
            if(x < numbers[j])
                j--;
            else if(x > numbers[j])
                i++;
            else
                break;
        }
        return {i+1,j+1};
    }
};