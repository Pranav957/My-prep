#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
/*int findsize(int num)
{
    if(num==0)
        return 0;
    return 1+findsize(num/10);  
}
void printKeypad(int num,string output)
{
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
        cout<<output<<endl;
        return;
    } 
    int k=findsize(num);
    int sum=1;
    for(int i=1;i<k;i++)
    {
       sum=sum*10; 
    }
    int a=num/sum;
    printKeypad(num%sum,output+v[a][0]);
    printKeypad(num%sum,output+v[a][1]);
    printKeypad(num%sum,output+v[a][2]);
    
}
void printKeypad(int num){
    
    //Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    
    string output=" ";
    printKeypad(num,output);
}*/
/*void swap(string &output)
{
    int i=0,j=output.size()-1;
    while(i<j)
    {
        int temp=output[i];
        output[i]=output[j];
        output[j]=temp;
        i++;
        j--;
    }
    
}*/
void printKeypad(int num,string output)
{
    unordered_map<int,string> v;
    v[0]="";
v[1]="";
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
        //swap(output);
        cout<<output<<endl;
        return;
    } 
    int a=num%10;
  /*  output[0]=v[a][0];
    printKeypad(num/10,output);
    output[]=v[a][1];
    printKeypad(num/10,output);
    output[1]=v[a][2];*/
    printKeypad(num/10,output);
    printKeypad(num/10,output+v[a][0]);
    printKeypad(num/10,output+v[a][1]);
    printKeypad(num/10,output+v[a][2]);
    for(int i=0;i<v[a].size();i++)
    {
       printKeypad(num/10,v[a][i]+output); 
    } 
    return;
}

void printKeypad(int num){
    
    //Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    
    string output="";
    printKeypad(num,output);
}
/*#include <iostream>
#include <string>
using namespace std;
void combinations(int num,string keys[],string value)
{
    if(num==0)
    {
        cout<<value<<endl;
        return;
    }
    int key=num%10,i=0;
    while(i<keys[key].size())
    {
        value=keys[key][i]+value;
        combinations(num/10,keys,value);
        value=value.substr(1);
        i++;
    }
    return;
}
void printKeypad(int num){
 string keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
 combinations(num,keys,"");
 return;
}*/