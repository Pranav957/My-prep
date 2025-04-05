int len(char input[])
{
    int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    } 
    return count;
}
int stringToNumber(char input[],int last )
{
    if(last==0)
  {
      int a=input[last]-'0';
      return a;
  }
   int ans=stringToNumber(input,last-1);
     int a=input[last]-'0';
    ans=ans*10+a;
    return ans;
}
int stringToNumber(char input[] )
{
    int length=len(input);
    return stringToNumber(input,length-1);
}
/*int stringToNumber(char input[]) {
    // Write your code here
  /*if(len(input)==1)
  {
      int a=input[0]-'0';
      return a;
  }*/
    //if(len(input)==0)
      //  return 0;
   /* if(input[0]=='\0')
        return 0;
    int x=1;
    
    for(int i=0;i<len(input)-1;i++)
    {
        x=x*10;
    }
    int ans=stringToNumber(input+1);
    
     int a=input[0]-'0';
    ans=a*x+ans;
    return ans;
}*/


