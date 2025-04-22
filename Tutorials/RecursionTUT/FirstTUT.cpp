int power(int x, int n) {
 
  if(n==0)
    return 1;

    return x*power(x, n-1);

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void printNumbers(int x,int n)
{
    if(x==n+1)
    {
       return;
    }
    cout<<x<<" ";
     printNumbers(x+1,  n);
}
void print(int n){
    printNumbers(1,n);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int countDigits(int n){
if(n==0)
	  return 0;
	  return 1+countDigits(n/10);

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int sum(int input[], int n) {

  if(n==0)
    return 0;

    return input[n-1]+sum(input,n-1);

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool checkNumber(int input[], int size, int x) {
 
  if(size==0)
    return false;

    if(input[size-1]==x)
     return true;

     return checkNumber(input,size-1,x);
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int firstIndex(int input[], int size, int x,int i=0) {

  if(size==0)
    return -1;

   int a=firstIndex(input,size-1,x,i+1);

     if(input[i]==x)
       return i;

       return a;
}

	int firstIndex(int input[], int size, int x) {
 
  static int i=0;
  if(size==0)
    return -1;
   if(input[i]==x)
     return i;
     i++;
    return firstIndex(input, size-1,  x);
   
}
  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int lastIndex(int input[], int size, int x) {
 
if(size==0)
  return -1;

  if(input[size-1]==x)
    return size-1;
   return lastIndex(input,size-1, x)  ;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int allIndexes(int input[], int size, int x, int output[],int count=0,int i=0) {
  if(size==i)
    return count;

    if(input[i]==x)
    {
       output[count]=i;
       count++;
    } 
      int ans=allIndexes(input,size,x,output,count,i+1);
   
      return ans;

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int multiplyNumbers(int m, int n) {
    if(n==0)
       return 0;

       return m+multiplyNumbers(m,n-1);    
}
	
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int countZeros(int n,int sum=0) {
    // Write your code here
    if(n==0)
     return 1;
    if(n>=1 && n<10)
      return 0;

      if(n%10==0)
        return 1+countZeros(n/10,sum);
     return countZeros(n/10,sum);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

double geometricSum(int k,int i=1,double sum=0) { //1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
    // Write your code here
    if(k<0)
     return sum;
     
     sum+=1.0/i;
     return geometricSum(k-1,i*2,sum);

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool isPalindrome(string& str,int i,int j) {
    // Write your code here.
    if(i>=j)
     return true;

     if(str[i]!=str[j])
      return false;
    
      return isPalindrome(str,++i,--j);
}
bool isPalindrome(string& str)
{
    return isPalindrome(str,0,str.length()-1);
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	int sumOfDigits(int n) {
    // Write your code here
    if(n==0)
      return 0;

      return n%10+sumOfDigits(n/10);

}


