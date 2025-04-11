#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'crosswordPuzzle' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY crossword
 *  2. STRING words
 */
 bool isValidVertical(vector<string>& crossword,int row,int col,string word)
 {
    if(row+word.length()>crossword.size())
      return false;
      
    for(int i=0;i<word.length();i++)
    {
    if(crossword[row+i][col]!='-' && crossword[row+i][col]!=word[i])
    return false;
    }
    return true;
      
 }
 
 bool isValidHorrizontal(vector<string>& crossword,int row,int col,string word)
 {
    if(col+word.length()>crossword[row].length())
      return false;
      
    for(int i=0;i<word.length();i++)
    {
    if(crossword[row][col+i]!='-' && crossword[row][col+i]!=word[i])
    return false;
    }
    return true;
      
 }
 
 void setVertical(vector<string>& crossword,bool* helper,int row,int col,string word)
 {
    for(int i=0;i<word.length();i++)
    {
        if(crossword[row+i][col]!=word[i])
        {
            crossword[row+i][col]=word[i];
            helper[i]=true;
        }
        else {
          helper[i]=false;
        }
    }
 }
 
 void setHorrizontal(vector<string> &crossword,bool* helper,int row,int col,string word)
 {
    for(int i=0;i<word.length();i++)
    {
        if(crossword[row][col+i]!=word[i])
        {
            crossword[row][col+i]=word[i];
            helper[i]=true;
        }
        else{
            helper[i]=false;
        }
    }
 }
 
 void resetVertical(vector<string>& crossword, bool* helper, int row, int col, string word)
 {
     for(int i=0;i<word.length();i++)
     {
         if(helper[i])
         {
            crossword[row+i][col]='-';
         }
     }
 }
 void resetHorrizontal(vector<string>& crossword, bool* helper, int row, int col, string word)
 {
    for(int i=0;i<word.length();i++)
     {
         if(helper[i])
         {
            crossword[row][col+i]='-';
         }
     }
 }
bool crosswordPuzzle(vector<string> & crossword, vector<string> words,int index) {
    if(index==words.size())
    {
        return true;
    }
    for(int i=0;i<crossword.size();i++)
    {
        for(int j=0;j<crossword[i].length();j++)
        {
            if(crossword[i][j]=='-' || crossword[i][j]==words[index][0])
            {
                if(isValidVertical(crossword,i,j,words[index]))
                {
                    bool *helper=new bool[words[index].length()];
                    setVertical(crossword,helper,i,j,words[index]);
                    bool res=crosswordPuzzle(crossword, words,index+1);
                    if(res) return true;
                    resetVertical(crossword,helper,i,j,words[index]);
                }
                if(isValidHorrizontal(crossword,i,j,words[index]))
                {
                    bool *helper =new bool[words[index].length()];
                    setHorrizontal(crossword,helper,i,j,words[index]);
                    bool res=crosswordPuzzle(crossword,words,index+1);
                    if(res) return true;
                    resetHorrizontal(crossword,helper,i,j,words[index]);
                }
            }
        }
    }
    return false;
}
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
     vector<string> v;
     string str="";
     int i=0;
     while(words[i]!='\0')
     {
        if(words[i]==';')
        {
            v.push_back(str);
            str="";
            i++;
        }
        str+=words[i];
        i++;
     }
     v.push_back(str);
     crosswordPuzzle(crossword,v,0);
     return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
