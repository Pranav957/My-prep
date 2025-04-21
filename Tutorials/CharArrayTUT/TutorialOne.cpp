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



int main()
{
  
     char arr[]="hello";
     reverseString(arr);
  cin.getline(stringName,len,delimeter);
     cout<<arr<<" ";// prints string not address
    
    return 0;
}
