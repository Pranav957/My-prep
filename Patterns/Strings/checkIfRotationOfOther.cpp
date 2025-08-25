class Solution {
public:
    bool rotateString(string s, string goal) {
        // for(int i=0;i<s.length();i++)
        // {
        //     rotate(s.begin(),s.begin()+1,s.end());
        //     if(s==goal)return true;
        // }
        //  return false;
        if(s.length()!=goal.length())return false;
        if((s+s).find(goal)!= string:: npos)
         return true;
        return false; 
    }
   
};
