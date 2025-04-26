#include<bits/stdc++.h>
using namespace std;
#define N 10
void reset_Horrizontal(char grid[N][N],int row,int col,bool helper[],string word)
{
    
    for(int i=0;i<word.length();i++)
    {
        if(helper[i]==true)
           grid[row][col+i]='-';
    }
}
void SetHorrizontal(char grid[N][N],int row,int col,string word,bool Helper[])
{
    for(int i=0;i<word.length();i++)
    {
        if(grid[row][col+i]=='-')
        {
            grid[row][col+i]=word[i];
            Helper[i]=true;
        }
        else if(grid[row][col+i]==word[i])
            Helper[i]=false;
    }
}
bool isvalid_Horrizontal(char grid[N][N],int row,int col,string word)
{
     if(col+word.length()>N)
      return false;   //word can not set in col
    for(int i=0;i<word.length();i++)
    {
        if(grid[row][col+i]!='-' && grid[row][col+i]!=word[i])
          return false;
    }
    return true; 
}
bool isvalid_Vertical(char grid[N][N],int row,int col,string word)
{
    if(row+word.length()>N)
      return false;   //word can not set in col
    for(int i=0;i<word.length();i++)
    {
        if(grid[row+i][col]!='-' && grid[row+i][col]!=word[i])
          return false;
    }
    return true;  
}
void Setvertical(char grid[N][N],int row,int col,string word,bool Helper[])
{
    for(int i=0;i<word.length();i++)
    {
        if(grid[row+i][col]=='-')
        {
            grid[row+i][col]=word[i];
            Helper[i]=true;
        }
        else if(grid[row+i][col]==word[i])
            Helper[i]=false;
    }
}
void reset_Vertical(char grid[N][N],int row,int col,bool helper[],string word)
{
    for(int i=0;i<word.length();i++)
    {
        if(helper[i]==true)
           grid[row+i][col]='-';
    }
}
bool Solvepuzzle(char grid[N][N],vector<string> v,int index)
{
    if(index==v.size())
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
              cout<<grid[i][j];
           cout<<endl;   
        }
        return true;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]=='-' || grid[i][j]==v[index][0])
            {
                if(isvalid_Vertical(grid,i,j,v[index]))
                {
                    int size=v[index].length();
                    bool Helper[size];
                    Setvertical(grid,i,j,v[index],Helper);
                    bool result=Solvepuzzle(grid,v,index+1);
                    if(result)
                     return true;
                   reset_Vertical(grid,i,j,Helper,v[index]);  
                }
                else if(isvalid_Horrizontal(grid,i,j,v[index]))
                {
                   // cout<<i<<" "<<j<<" ";
                    int size=v[index].length();
                    bool Helper[size];
                    SetHorrizontal(grid,i,j,v[index],Helper);
                    bool result=Solvepuzzle(grid,v,index+1);
                    if(result)
                       return true;
                    reset_Horrizontal(grid,i,j,Helper,v[index]);   
                }
            }
        }
    }
    return false;
}
bool myCmp(string s1, string s2) {

  if (s1.size() == s2.size()) {
    return s1 > s2;
  } else {
    return s1.size() > s2.size();
  }
}
int main(){
    
    // write your code here
    char grid[N][N];
    for(int i=0;i<N;i++)
    {
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++)
        {
            grid[i][j]=str[j];
        }
    }
    string s;
    cin >> s;
    vector<string> v;
    int i = 0;
    string str = "";
    while (s[i] != '\0') {
      if (s[i] == ';') {
        v.push_back(str);
        str = "";
        i++;
      }
      str += s[i];
      i++;
    }
    v.push_back(str);
    //sort(v.begin(), v.end(), myCmp);
      bool result=Solvepuzzle(grid, v,0);
      /*if(result)
   {
        for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        cout<<grid[i][j];
       cout<<endl;
   }
   }  */ 
    return 0;
}