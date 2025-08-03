// User function Template for C++

class Solution {
  public:
   void generateBinaryStrings(int num,string s,int i,vector<string>& v)
   {
       if(s.length()==num)
        {
            v.push_back(s);
            return;
        } 
        
        if(i>=1 && s[i-1]=='1')
          generateBinaryStrings(num,s+'0',i+1,v);
        else
        {
             generateBinaryStrings(num,s+'0',i+1,v);
            generateBinaryStrings(num,s+'1',i+1,v);
        }
         
        
   }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string> v;
        generateBinaryStrings(num,"",0,v);
        return v;
    }
};
