
class Solution {
public:
    // Finds the first missing positive integer in a given array.
    int firstMissingPositive(vector<int>& nums) { 
        int n = nums.size();
        for (int i=0; i<n; i++) { 
            while (1<=nums[i] && nums[i]<=n && nums[i]-1!=i) { 
                // Rearranges the array to place each element at its correct index.
                if (nums[i]==nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<n; i++) { 
            // Returns the first missing positive integer or the size of the array + 1 if all integers are present.
            if (nums[i]<1||nums[i]>n||nums[i]-1!=i) return i+1;
        }
        return n+1;
    }
}; 