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
