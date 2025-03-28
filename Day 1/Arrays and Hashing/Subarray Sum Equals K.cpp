class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            mp[0] = 1;
            int sum = 0;
            int res = 0;
            for(int x: nums){
                sum += x;
                int diff = sum - k;
                res += mp[diff];
                mp[sum]++;
            }
            return  res;
        }
    };