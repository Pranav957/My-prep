#include<bits/stdc++.h>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    int k=0;
    for(int i=0;i<input.length();i++)
    {
        
        string str=input.substr(0,i)+input.substr(i+1);
        string out[10000];
         int count=returnPermutations(str,out);
        for(int j=0;j<count;j++)
        {
          output[k]=input[i]+out[j];
            k++;
        } 
       
        
    }
    
    return k;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRINT PERMUTATIONS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	#include <iostream>
#include <string>
using namespace std;
void printPermutations(string input,string output)
{
	if(input.length()==0)
	{
		cout<<output<<endl;
		return;
	}
     for(int i=0;i<input.length();i++)
    {
		
		string str=input.substr(0,i)+input.substr(i+1);
		
		printPermutations(str,output+input[i]);
	}
	return;
}
void printPermutations(string input){

	string output="";
   printPermutations( input,output);	
}
