class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) {
                odd=i;
                break;
            }
        }
        for(int i=odd;i<nums.size();i++){
            if(nums[i]%2==1) continue;
            else if(nums[i]%2==0){
                swap(nums[i],nums[odd]);
                odd++;
            }
        }
        return nums;
    }
};