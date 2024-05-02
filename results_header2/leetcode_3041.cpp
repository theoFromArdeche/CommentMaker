

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) { // Returns the maximum number of elements that can be selected from a set of integers.
        int maxi = nums[0], mini = nums[0];  // Initialize minimum and maximum values in the input array.
        for (int x : nums) {  // Iterate through the input array to find the minimum and maximum values.
            maxi = max(maxi, x);
            mini = min(mini, x);
        }
        
        vector<int> occ(maxi + 2, 0);  // Create a frequency array of size 'maxi+2' initialized with zeros.
        for (int i = 0; i < nums.size(); i++) {  // Count the occurrences of each number in the input array.
            occ[nums[i]]++;
        }
        
        int cur_count = 0, can_increase = 0;
        bool flag_augmented = false;
        int answer = 0;
        for (int i = mini; i <= maxi; i++) {  // Iterate through the frequency array.
            if (occ[i] == 0) {  // If a number is not present in the input array, update the maximum count.
                answer = max(answer, cur_count);
                cur_count = can_increase;
                can_increase = 0;
            } else if (occ[i] > 1) {  // If a number appears more than once, increment the counts and flags for augmentation.
                occ[i + 1]++;
                cur_count++;
                can_increase++;
                flag_augmented = true;
            } else {  // If a number appears only once, update the count and flag accordingly.
                if (flag_augmented) {
                    cur_count++;
                    flag_augmented = false;
                    if (occ[i + 1] > 1) {
                        can_increase++;
                    } else can_increase = 0;
                } else {  // We have a choice to select this number or not.
                    cur_count++;
                    can_increase++;
                }
            }
        }
        
        if (occ[maxi + 1] != 0) cur_count++;  // If the maximum value appears in the input array, increment the count.
        answer = max(answer, cur_count);
        return answer;
    }
};