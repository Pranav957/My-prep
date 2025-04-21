#include <bits/stdc++.h>
using namespace std;

//Built in functions for char array
strcpy(dest,source);
strlen(string);
strcmp(s1,s2);
strncpy(dest,source,numChar);

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

void printSubstrings(char input[]) {
    // Write your code here
    for(int k=0;input[k]!='\0';k++)
    {
       for(int i=k;input[i]!='\0';i++)
    {
        for(int j=k;j<=i;j++)
        {
            cout<<input[j];
        }
        cout<<endl;
    }
    
    }
}
void printSubstrings(char input[]) {
    // Write your code here
    for(int k=0;input[k]!='\0';k++)
    {
        string str="";
       for(int i=k;input[i]!='\0';i++)
    {
        str+=input[i];
        cout<<str<<endl;
    }
    
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

#include<cstring>
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    int a=strlen(input1);
    int b=strlen(input2);

    int arr[256]={0};

    if(a!=b)
      return false;

    for(int i=0;i<a;i++)
    {
        arr[input1[i]]++;
    }
    for(int i=0;i<b;i++)
    {
        arr[input2[i]]--;
    }
    for(int i=0;i<256;i++)
    {
        if(arr[i]!=0)
          return false;
    }
    return true;

}

int main()
{
  
     char arr[]="hello";
     reverseString(arr);
  cin.getline(stringName,len,delimeter);
     cout<<arr<<" ";// prints string not address
    
    return 0;
}
