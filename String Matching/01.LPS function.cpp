   
// LPS function for string matiching in O(N)

// input : AABAACAADAABAABA

vector<int> LPS(string str){
        int n = str.size();
        vector<int> lps(n);
        
        int len =0, i =1;
        while(i<n){
            if(str[i] == str[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len != 0) len = lps[len-1];
                else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
    }
