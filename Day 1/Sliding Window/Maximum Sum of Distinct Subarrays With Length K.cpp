class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            unordered_set<int> set;
            long long sum = 0, res = 0;
            int l = 0;
            for(int r = 0; r < nums.size(); r++){
                sum += nums[r];
                while(r - l + 1 > k || set.find(nums[r]) != set.end()){
                    sum -= nums[l];
                    set.erase(nums[l]);
                    l++;
                }
                set.insert(nums[r]);
                if(r - l + 1 == k && set.size() == k){
                    res = max(res, sum);
                }
            }
            return res;
        }
    };