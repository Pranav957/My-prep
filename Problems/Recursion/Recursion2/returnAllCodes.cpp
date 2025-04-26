#include <string.h>
using namespace std;
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don?t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input[0]=='\0')
    {
        output[0]="";
        return 1;
    }
    int x=input[0]-'0';
    char ch='a'+x-1;
    int a=getCodes(input.substr(1),output);
    for(int i=0;i<a;i++)
    {
        output[i]=ch+output[i];
    }
    int mul=10,x2=0;
    for(int i=0;i<2;i++)
    {
        x2=x2+(input[i]-'0')*mul;
        mul/=10;
    }
    string output2[1000];
    int b=0;
    if(x2>=10 && x2<=26)
    {
        char ch2='a'+x2-1;
         b=getCodes(input.substr(2),output2);
        for(int i=0;i<b;i++)
        {
            output[a+i]=ch2+output2[i];
        }  
    } 
    return a+b;
}


/*int getCodes(string input, string output[10000]) {
    
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don???t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    
    int x=input[0]-'0';
    char ch='a'+x-1;
    
    int a=getCodes(input.substr(1),output);
    for(int i=0;i<a;i++)
    {
        output[i]=ch+output[i];
    }
    
    int b=0;
    if(input[1] != '\0') {
        int x2=input[1]-'0';
        int num=10*x+x2;
        // for(int i=0;i<2;i++)
        // {
        //     x2=x2+(input[i]-'0')*mul;
        //     mul/=10;
        // }
        string output2[1000];
        if(num>=10 && num<=26)
        {
            char ch2='a'+num-1;
             b=getCodes(input.substr(2),output2);
            for(int i=0;i<b;i++)
            {
                output[a+i]=ch2+output2[i];
            }  
        } 
    }
    return a+b;
}
*/
