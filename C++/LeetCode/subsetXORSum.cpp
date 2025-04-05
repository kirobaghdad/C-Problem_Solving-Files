class Solution {
    public:
        int ans = 0;
    
        void solve(vector<int>& nums, int i = 0, int sum = 0)
        {
            if(i == nums.size())
                return;

            solve(nums, i + 1, sum);
            
            sum = sum ^ nums[i];
            ans += sum;

            solve(nums, i + 1, sum);
        }
    
        int subsetXORSum(vector<int> nums) 
        {
            solve(nums);
    
            return ans;
        }
    };
