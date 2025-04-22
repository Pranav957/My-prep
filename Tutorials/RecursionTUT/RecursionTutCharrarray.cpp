int getLength(char input [])
{
	if(input[0]=='\0')
	  return 0;

	  return 1+getLength(input+1);
}
void replacePi(char input[]) {
	// Write your code here
	if(input[0]=='\0')
	  return ;

	  replacePi(input+1);
	  if(input[0]=='p' && input[1]=='i')
	   {
		  for(int i=getLength(input);i>=0;i--)
		  {
			  input[i+2]=input[i];
		  }
		  input[0]='3';
		  input[1]='.';
		  input[2]='1';
		  input[3]='4';
	   }

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  // Change in the given string itself. So no need to return or print anything
void removeX(char input[]) {
    // Write your code here
   if(input[0]=='\0')
     return ;

     removeX(input+1);
     if(input[0]=='x')
     {
       for(int i =0;input[i]!='\0';i++)
         input[i]=input[i+1];
     } 
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  using namespace std;
int len(char input[])
{
    int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    } 
    return count;
}
int stringToNumber(char input[],int length)
{
    if(length==1)
    {
        int a=input[0]-'0';
        return a;
    }
    int b=stringToNumber(input+1, length-1);
    int a=input[0]-'0';
    int x=1;
    for(int i=0;i<length-1;i++)
    {
        x=x*10;
    }
    return a*x+b;

}
int stringToNumber(char input[]) {
    // Write your code here
    stringToNumber(input,len(input));

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Change in the given string itself. So no need to return or print the changed string.
int getLength(char input[])
{
    if(input[0]=='\0')
      return 0;

      return 1+getLength(input+1);
}
void pairStar(char input[]) {
    // Write your code here
    if(input[1]=='\0')
      return ;

      pairStar(input+1);
    if(input[0]==input[1])
     {
        int length=getLength(input);
        for(int i=length;i>=1;i--)
          input[i+1]=input[i];
           input[1]='*';
     }
    return;

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n==0)
     return;

     towerOfHanoi(n-1,source,destination,auxiliary);
     cout<<source<<" "<<destination<<endl;
     towerOfHanoi(n-1,auxiliary,source,destination);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	bool helperCheckAB(char input[],int index)
{
	if(input[index]=='\0')
	 return true;

     if(input[index]!='a')
	   return false;

	   if(input[index+1]!='\0' && input[index+2]!='\0')
	    {
			if(input[index+1]=='b' && input[index+2]=='b')
			  return helperCheckAB(input,index+3);
		}
		return helperCheckAB(input,index+1);
}
bool checkAB(char input[],int index=0) {
	// Write your code here

	if(input[0]!='a')
	  return false;

	  return helperCheckAB(input,0);

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void replaceCharacter(char input[], char c1, char c2) {
    
     if(input[0]=='\0')
       return;

       if(input[0]==c1)
          input[0]=c2;

          replaceCharacter(input+1,c1,c2);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void removeConsecutiveDuplicates(char *input) {
   if(input[0]=='\0')
     return ;
  removeConsecutiveDuplicates(input+1);
  if(input[0]==input[1])
  {
	  int i;
	  for( i=1;input[i]!='\0';i++)
	  {
		  input[i-1]=input[i];
	  }
	  input[i-1]=input[i];
  }
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
