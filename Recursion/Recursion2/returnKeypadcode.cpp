#include <string>
#include <bits/stdc++.h>
using namespace std;
int keypad(int num, string output[]){
    // Insert all the possible combinations of the integer number into the output string array. You do not need to
    //print anything, just return the number of strings inserted into the array.
    
    unordered_map<int,string> v;
v[1]=" ";
v[2]="abc";
v[3]="def";
v[4]="ghi";
v[5]="jkl";
v[6]="mno";
v[7]="pqrs";
v[8]="tuv";
v[9]="wxyz";
    if(num==0)
    {
        output[0]="";
        return 1 ;
    } 
    int smallopsize=keypad(num/10,output);
    int a=num%10;
    int k=smallopsize;
    int p=v[a].size();
    for(int j=1;j<p;j++)
    {
        for(int i=0;i<k;i++)
        {
            output[i+smallopsize]=output[i]+v[a][j];
        }
        smallopsize+=k;
    }
    for(int i=0;i<k;i++)
    {
        output[i]=output[i]+v[a][0];
    }
    return smallopsize;
}
/*int keypad(int num, string output[]){
    // Insert all the possible combinations of the integer number into the output string array. You do not need to
    //print anything, just return the number of strings inserted into the array.
    
    unordered_map<int,string> v;
v[1]=" ";
v[2]="abc";
v[3]="def";
v[4]="ghi";
v[5]="jkl";
v[6]="mno";
v[7]="pqrs";
v[8]="tuv";
v[9]="wxyz";
    if(num==0)
    {
        output[0]=" ";
        return 1 ;
    } 
    int smallopsize=keypad(num/10,output);
    int a=num%10;
    int k=smallopsize;
    int p=v[a].size();
    
        /or(int j=0;j<p-1;j++)
        {
            for(int i=0;i<k;i++)
            {
                output[smallopsize]=output[i];
                smallopsize+=1;
            }   
        }
    int b=0;
    for(int i=0;i<p;i++)
    {
       for(int j=0;j<k;j++)
       {
          output[b]=output[b]+v[a][i]; 
           //cout<<ouput[j]<<" -";
           b++;
       }  
    } 
    return smallopsize;
}
*/