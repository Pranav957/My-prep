#include <string.h>
#include<bits/stdc++.h>
using namespace std;

void printAllPossibleCodes(string input,string output) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    int x=input[0]-'0';
    char ch='a'+x-1;
    printAllPossibleCodes( input.substr(1),output+ch);
    if(input[1]!='\0')
    {
        int x2=input[1]-'0';
        x2=10*x+x2;
        if(x2>=10 && x2<=26)
        {
        char ch2='a'+x2-1;
        printAllPossibleCodes( input.substr(2),output+ch2);
        }
    } 
}
void printAllPossibleCodes(string input)
{
    string output="";
  printAllPossibleCodes( input,output);
}
