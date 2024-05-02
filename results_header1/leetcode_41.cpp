

class Solution {
public:
    // This function determines the first missing positive integer in a given array of integers
    int firstMissingPositive(vector<int>& nums) { 
        int n = nums.size(); 
        for (int i=0; i<n; i++) { 
            while (1<=nums[i] && nums[i]<=n && nums[i]-1!=i) { 
                if (nums[i]==nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]); 
             }
         } 
        for (int i=0; i<n; i++) { 
            if (nums[i]<1||nums[i]>n||nums[i]-1!=i) return i+1; 
         } 
        return n+1; 
    } 
}; 

