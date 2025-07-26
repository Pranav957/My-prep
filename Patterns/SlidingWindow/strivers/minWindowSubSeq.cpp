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
******************************************************************************
string minWindow(string s, string T)
{
	// Write your Code here
	int n=s.length(),m=T.length();
	string ans="";
    int minLength=INT_MAX;
	int startIndex=-1;

   int left=0,x=0;
   for(int r=0;r<n;r++)
   {
	   if(s[r]==T[x])
	   {
		   if(x==0)
		     left=r;
		     x++;

		  if(x==m)
		  {
			//   startIndex=left;
			//   minLength=min(minLength,r-left+1);
			  if(r-left+1<minLength)
			  {
				  minLength=r-left+1;
				  startIndex=left;
			  }

			  left++;
			  while(s[left]!=T[1])
			   {
				   if(s[left]==T[0])
				   {
					   minLength=min(minLength,r-left+1);
					   startIndex=left;
				   } 
			       left++;		
			   }
			   x=0;
		  } 	 
	   }
   }
	
	return (startIndex==-1)? "":s.substr(startIndex,minLength);
}
