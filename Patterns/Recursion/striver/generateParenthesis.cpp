class Solution {
public:
    void generateParenthesis(int n,int open,string curr, vector<string>& v)
    {
       if(curr.length()==2*n)
       {
        v.push_back(curr);
        return;
       }

       if(open<n) generateParenthesis(n,open+1,curr+'(',v);
       if(curr.length()-open<open)
        generateParenthesis(n,open,curr+')',v);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
         generateParenthesis(n,0,"",v);
         return v;
    }
};
