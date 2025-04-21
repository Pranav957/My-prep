/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void replaceX(char s[])
{
    if(s[0]=='\0')
      return ;
      
    if(s[0]!='X')
         replaceX(s+1);
     
    else
    {
      for(int i=0;s[i]!='\0';i++)
      s[i]=s[i+1];
      
      replaceX(s);
       
    }
}

int length( char s[])
{
    if(s[0]=='\0')
      return 0;
    
    return 1+length(s+1);  
}

void replaceCharacter(char input[], char c1, char c2) {
    
     if(input[0]=='\0')
       return;

       if(input[0]==c1)
          input[0]=c2;

          replaceCharacter(input+1,c1,c2);
}

void removeConsecutiveDuplicates(char *input) {
	
   if(input[0]=='\0')
    return;
  
   removeConsecutiveDuplicates(input+1);
   	if(input[0]==input[1])
    {
		for(int i=0; input[i]!='\0';i++)
		  input[i]=input[i+1];
		
	} 
}


int main()
{

  char arr[]="hellow";
     
  cout<<length(arr)<<endl;
  
  char input[]="aXbXd";
  
  replaceX(input);
  
  cout<<input;


    return 0;
}
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>""Problems"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

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


bool checkAB(char input[]) {
	// Write your code here
    static int a=1;
    int k=a;
    if(input[0]=='\0')
        return true;
    ++a;
    int x=checkAB(input+1);
    
    if(x==false)
        return false;
    else
    {
        if(input[0]=='a')
        {
            if(input[1]==' '||input[1]=='a'||input[1]=='\0' || input[1]=='b'&& input[2]=='b')
                return true;
        }
       
        else if(input[0]=='b' && k!=1)
        {
            if(input[1]=='a'||input[1]==' '||input[1]=='\0')
                return true;
            else if(input[1]=='b' && input[2]=='a'||input[2]==' '|| input[2]=='\0')
                return true;
        }
       return false;  
    }

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
