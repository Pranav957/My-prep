#include<iostream>
int sum(int input[], int n) {
 static int sumarr=0;
    if( n==0)
      return sumarr;//return 0
    return input[0]+sum(input+1,n-1);
}
