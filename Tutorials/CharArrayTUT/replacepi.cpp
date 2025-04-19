int getLength(char input [])
{
	if(input[0]=='\0')
	  return 0;

	  return 1+getLength(input+1);
}
void replacePi(char input[]) {
	// Write your code here
	if(input[0]=='\0')
	  return ;

	  replacePi(input+1);
	  if(input[0]=='p' && input[1]=='i')
	   {
		  for(int i=getLength(input);i>=0;i--)
		  {
			  input[i+2]=input[i];
		  }
		  input[0]='3';
		  input[1]='.';
		  input[2]='1';
		  input[3]='4';
	   }

}
void removeX(char input[]) {
    // Write your code here
   if(input[0]=='\0')
     return ;

     removeX(input+1);
     if(input[0]=='x')
     {
       for(int i =0;input[i]!='\0';i++)
         input[i]=input[i+1];
     } 
}
