/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int subSequences(char input[], char output[][50]) {
	// Write your code here
	if(input[0]=='\0')
	{
		output[0][0]='\0';
		return 1;
	}

	int k=subSequences(input+1,output);

	for(int i=0;i<k;i++)
	{
		output[i+k][0]=input[0];
		for(int j=0;j<output[i][j]!='\0';j++)
		{
			output[i+k][j+1]=output[i][j];
		}
		
	}
   return 2*k;

}

int subs(string input, string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    
    int smallOp=subs(input.substr(1),output);
    for(int i=0;i<smallOp;i++)
    {
        output[smallOp+i]=input[0]+output[i];
    }
    return 2* smallOp;
}

void printsubs(string input,string output)
{
    if(input.empty())
     {
         cout<<output<<"";
         return;
     }
     
     printsubs(input.substr(1),output);
     printsubs(input.substr(1),output+input[0]);
     return;
}

// we dont need 2d array of 2^n to print all subsequences

int keypad(int num, string output[]){

    unordered_map<int,string> mp;

    mp[0]="";
    mp[1]="";
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";

    if(num==0)
    {
        output[0]="";
        return 1;
    }

    int smallopsize=keypad(num/10,output);
    int k=smallopsize;
    int digit=num%10;

  for(int i=1;i<mp[digit].size();i++)
  {
      for(int j=0;j<smallopsize;j++)
      {
          output[j+smallopsize]= output[j]+mp[digit][i];
      }
      smallopsize+=k;
  }

  for(int i=0;i<k;i++)
   output[i]=output[i]+mp[digit][0];

  return smallopsize;
}

void printKeypad(int num,string output)
{
    
    unordered_map<int,string> mp;

    mp[0]="";
    mp[1]="";
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";
    
    if(num==0)
    {
         cout<<output<<" ";
         return;
    }
    
    int digit=num%10;
    // printKeypad(num/10,output+mp[digit][0]);
    // printKeypad(num/10,output+mp[digit][1]);
    // printKeypad(num/10,output+mp[digit][2]);
    
    for(int i=0;i<mp[digit].size();i++)
      printKeypad(num/10,output+mp[digit][i]);
}


int main()
{
    string str;
    cin >> str;
    
    string* output= new string[100];
     
    int count=subs(str,output);
    
    for(int i=0;i<count;i++)
      cout<<output[i]<<endl;
      
      printsubs("abc"," ");
      cout<<endl;

printKeypad(23,"");


    return 0;
}
