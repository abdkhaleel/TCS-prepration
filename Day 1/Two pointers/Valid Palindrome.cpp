
class Solution {
    public:
        void format(string &s){
            string filtered = "";
            for(char c: s) if(isalnum(c)) filtered += tolower(c);
            s = filtered;
        }
        bool isPalindrome(string s) {
            format(s);
            cout<<s<<endl;
            int i = 0, j = s.size()-1;
            while(i < j){
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        }
    };