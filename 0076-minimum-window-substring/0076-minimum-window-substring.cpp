class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char e:t){
            m[e]++;
        }
        int n = s.size();
        int i = 0;
        int j = 0;
        int len = 1e8;
        int f = -1;
        int d = m.size();
            while(i<n){
                m[s[i]]--;
                if(m[s[i]]==0) d--;
                while(d==0){
                    if(len>i-j+1){
                        len = i-j+1;
                        f = j;
                    }
                    m[s[j]]++;
                    if(m[s[j]]==1) d++;
                    j++;
                }
                i++;
            }

            if(f == -1)
                return "";
            return s.substr(f,len);
    }
};