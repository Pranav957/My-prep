#include<cstring>
void reverse_string(char* arr , int i,int j)
{
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[]) {
    // Write your code here
    int len=strlen(input);
     reverse_string(input,0,len-1);
     int k=0,i;
     for( i=0;i<len;i++)
     {
         if(input[i]==' ')
          {
            reverse_string(input,k,i-1);
            k=i+1;   
          } 
     }
       reverse_string(input,k,i-1);
}
