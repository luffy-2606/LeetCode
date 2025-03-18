class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int x = 0, y = 0, z = 0;

        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                for (int k=j+1; k<nums.size(); k++)
                {
                    if ((target - sum) > (target - (nums[i]+nums[j]+nums[k])))
                        sum = nums[i]+nums[j]+nums[k];
                }
            }

        }
        return sum;
    }
};