class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, max = INT_MIN;
        for(auto it: nums){
            currentSum+=it;
            if(currentSum>max){
               max = currentSum;
            }
            if(currentSum<0){
                currentSum=0;
            }
        }
        return max;
    }
};
