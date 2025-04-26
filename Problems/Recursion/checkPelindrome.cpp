//here problem is brocken into recursive parts & if the part we check
#include<iostream>
bool helper(char input[],int start,int end)
{
    if(start==end||end<start)
        return true;
    if(input[start]!=input[end])
        return false;
    return helper(input,start+1,end-1);
}
bool checkPalindrome(char input[]) {
    // Write your code here
    int len=0;
  for(int i=0;input[i]!='\0';i++)
  {
      len++;
  }
   
    if(len==0||len==1)
        return true;
    bool ans= helper(input,0,len-1);
    if(ans==1)
        return true;
    else
        return false;
}


