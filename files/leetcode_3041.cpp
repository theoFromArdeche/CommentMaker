class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int maxi=nums[0], mini=nums[0];
        for (int x:nums) {
            maxi=max(maxi, x);
            mini=min(mini, x);
        }
        vector<int> occ(maxi+2, 0);
        for (int i=0; i<nums.size(); i++) {
            occ[nums[i]]++;
        }
        
        int cur_count=0, can_increase=0;
        bool flag_augmented=false;
        int answer=0;
        for (int i=mini; i<=maxi; i++) {
            if (occ[i]==0) {
                answer=max(answer, cur_count);
                cur_count=can_increase;
                can_increase=0;
            } else if (occ[i]>1) {
                occ[i+1]++;
                cur_count++;
                can_increase++;
                flag_augmented=true;
            } else { // occ[i]==1
                if (flag_augmented) {
                    cur_count++;
                    flag_augmented=false;
                    if (occ[i+1]>1) {
                        can_increase++;
                    } else can_increase=0;
                } else { // we have a choice
                    cur_count++;
                    can_increase++;
                }
            }
        }
        if (occ[maxi+1]!=0) cur_count++;
        answer=max(answer, cur_count);
        return answer;
    }
};