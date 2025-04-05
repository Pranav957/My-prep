Problem statement
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false

bool checkAB(char input[]) {
	// Write your code here
    static int a=1;
    int k=a;
    if(input[0]=='\0')
        return true;
    ++a;
    int x=checkAB(input+1);
    
    if(x==false)
        return false;
    else
    {
        if(input[0]=='a')
        {
            if(input[1]==' '||input[1]=='a'||input[1]=='\0' || input[1]=='b'&& input[2]=='b')
                return true;
        }
       
        else if(input[0]=='b' && k!=1)
        {
            if(input[1]=='a'||input[1]==' '||input[1]=='\0')
                return true;
            else if(input[1]=='b' && input[2]=='a'||input[2]==' '|| input[2]=='\0')
                return true;
        }
       return false;  
    }

}
