#include <bits/stdc++.h>
using namespace std;



void reverseString(char input[])
{
    int i=0;
    int j=strlen(input)-1;
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;j--;
    }
}

void trimSpaces(char input[]) {
    // Write your code here
    int i=0, j=0;
    for(int i=0; input[i]!='\0';i++)
    {
        if(input[i]!=' ')
        {
            input[j]=input[i];
            j++;
        }
    }
    input[j]='\0';
}

void replaceCharacter(char input[], char c1, char c2) {
    // Write your code here
     int i=0;
     while(input[i]!='\0')
     {
         if(input[i]==c1)
            input[i]=c2;
            i++;
     }
}


int main()
{
  
     char arr[]="hello";
     reverseString(arr);
  cin.getline(stringName,len,delimeter);
     cout<<arr<<" ";// prints string not address
    
    return 0;
}
