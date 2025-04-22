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

