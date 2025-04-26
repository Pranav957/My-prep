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

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	string output="";
   printPermutations( input,output);	
}
