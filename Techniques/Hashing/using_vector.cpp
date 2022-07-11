
//https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string s, string t) {
        vector<pair<char,int>> st, tr;
      
        for(int i =0; i<s.size(); i++){
            if(s[i] != '_'){
                st.push_back({s[i], i});
            }
        }
      
        for(int i =0; i<t.size(); i++){
            if(t[i] != '_'){
                tr.push_back({t[i], i});
            }
        }
      
        if(tr.size() != st.size()) return false;
        for(int i =0; i<st.size(); i++){
            if(st[i].first != tr[i].first) return false;
        }
        
        for(int i=0; i<st.size(); i++){
            if(st[i].first =='L' and tr[i].first == 'L'){
                if(st[i].second < tr[i].second) return false;
            }
            else if(st[i].first =='R' and tr[i].first == 'R'){

                if(st[i].second > tr[i].second) {return false;}
            }
        }
        return true;
        
    }
};
