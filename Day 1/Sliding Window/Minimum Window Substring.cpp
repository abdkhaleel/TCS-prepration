class Solution {
    public:
        string minWindow(string s, string t) {
            int hash[256] = {0};
            int l = 0, r = 0, mini = 1e9, Sidx = -1, count = 0;
            for(int x: t) hash[x]++;
            int n = s.size(), m = t.size();
            while(r < n){
                if(hash[s[r]] > 0) count++;
                hash[s[r]]--;
                while(count == m){
                    if(mini > r - l + 1){
                        mini = r - l + 1;
                        Sidx = l;
                    }
                    hash[s[l]]++;
                    if(hash[s[l]] > 0) count--;
                    l++;
                }
                r++;
            }
            return Sidx == -1? "": s.substr(Sidx, mini);
        }
    };