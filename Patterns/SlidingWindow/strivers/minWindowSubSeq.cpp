string minWindow(string s, string T)
{
	// Write your Code here
	int n=s.length(),m=T.length();
	string ans="";
    int minLength=INT_MAX;

	for(int i=0;i<n;i++)
	{
		string str="";
		int x=0;
		for(int j=i;j<n;j++)
		{
          str+=s[j];
		  if(s[j]==T[x])
		   x++;

		   if(x==m)
		    break;

		}
		if(x==m && str.length()<minLength)
		{
			minLength=str.length();
			ans=str;
		}
	}
	return ans;
}
