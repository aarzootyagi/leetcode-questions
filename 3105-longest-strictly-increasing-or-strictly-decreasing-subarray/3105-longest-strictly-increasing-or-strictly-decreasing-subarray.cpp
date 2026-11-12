class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int a=1,b=1,ans=1;
        for(int i=1;i<nums.size();i++){
            a=nums[i]>nums[i-1]?a+1:1;
            b=nums[i]<nums[i-1]?b+1:1;
            ans=max(ans,max(a,b));
        }
        return ans;
    }
};