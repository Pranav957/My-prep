#include<string>
#include<unordered_set>
string uniqueChar(string str) {
  // Write your code here
  string output = "";
  unordered_set<char> mp;
  int j = 0;
  for (int i = 0; i < str.length(); i++) {
    if (mp.find(str[i]) != mp.end())
      continue;
    output += str[i];
    mp.insert(str[i]);
  }
  return output;
}
/*string uniqueChar(string str) {
	// Write your code here
	string output="";
	unordered_map<char,bool> mp;
	int j=0;
	for(int i=0;i<str.length();i++)
	{
		if(mp.find(str[i])!=mp.end())
		   continue;
		output+=str[i]; 
		mp[str[i]]=true;
		
	}
  return output;
}*/