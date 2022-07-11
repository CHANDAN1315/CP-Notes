// problem link : https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

// Brute solution.
class Solution {
public:
    int fillCups(vector<int>& amt) {
        int ans =0;
        int n = amt.size();
        sort(amt.begin(), amt.end(), greater<int>());

        while(amt[0] != 0){
            // cout <<amt[0]<<" ";
            if(amt[0] != 0 ){
                amt[0]--;
                if(amt[1] > 0) amt[1]--;
                ans++;
            }
            sort(amt.begin(), amt.end(), greater<int>());
        }
        return ans;
        
        
    }
};

// Optimal sol:
class Solution {
public:
    int fillCups(vector<int>& amt) {
        int ans =0;
        int n = amt.size();
        priority_queue<int> pq;
        for(auto i : amt) {if(i) pq.push(i);}
        
        while(!pq.empty()){
            int f = pq.top(); pq.pop();
            if(!pq.empty()){
                int s = pq.top(); pq.pop();
                s--;
                f--;
                if(s) pq.push(s);
                if(f)pq.push(f);
                ans++;
            }
            else ans += f;
        }
        return ans;
           
    }
};
