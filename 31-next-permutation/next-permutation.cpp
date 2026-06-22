class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        int n = nums.size();
        int pivotIndex = -1;
        for(int i= n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                pivotIndex = i;
                break;
            }
        }
        //edge case when nothing got then array is already sorted so next element
        if(pivotIndex == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int nextGreaterNo = nums[pivotIndex];
        for(int i= n-1;i>pivotIndex;i--){
            if(nums[i]>nextGreaterNo){
                nextGreaterNo = nums[i];
                nums[i]=nums[pivotIndex];
                nums[pivotIndex]=nextGreaterNo;
                break;
            }
        }
        reverse(nums.begin() + pivotIndex + 1, nums.end());
    }
};