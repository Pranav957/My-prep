int countDigits(int n){
    int cnt = 0;
    while(n > 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}
int revNum(int n)  // use this to find pendrome or two pointers
{
  int revNum = 0;
	while(n > 0){

		int ld = n % 10;
		revNum = (revNum * 10) + ld;
		n = n / 10;
  }
	cout << revNum;
}
***************************************************ARMSTRONGNUM*************************************
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum=0;
        int dup=n;
        while(n>0)
        {
            int x=n%10;
            
            sum+=(x*x*x);
            
            n=n/10;
        }
        if(dup==sum)return true;
        return false;
    }
};
*************************************************************************************************************
vector<int> findDivisors(int n) {
    vector<int> divisors; 
    int sqrtN = sqrt(n); 

    for (int i = 1; i <= sqrtN; ++i) { // i*i<n
        if (n % i == 0) { 
            divisors.push_back(i); 
            if (i != n / i) {
                divisors.push_back(n / i); 
            }
        }
    }
  
    return divisors; 
}
*********************************************************************************************************
bool checkPrime(int n){ 
    int cnt = 0;
    for(int i = 1; i<=n; i++){ 
        if(n%i ==0){ 
            cnt = cnt+1;
        }
    }
    if(cnt==2){
    return true;
    }
    else{ 
        return false; 
    }
}
******************************************************************************************************************
bool checkPrime(int n){ 
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){ 
        if(n % i == 0){ 
            cnt = cnt + 1;
            if(n / i != i){
                cnt = cnt + 1;
            }
        }
    }
    if(cnt == 2){
        return true;
    }
    else{ 
        return false; 
    }
}
****************************************************************************************************
int findGcd(int n1, int n2) {
    
    for(int i = min(n1, n2); i > 0; i--) {
        if(n1 % i == 0 && n2 % i == 0) {
            return i;
        }
    }
    return 1;
}

int findGcd(int a, int b) {     //euclidied-> GCD(n1, n2)= GCD(n1-n2,n2) where n1>n2
    while(a > 0 && b > 0) {      // (20, 15)->(5,0)=5 till one of the number becomes 0;
        if(a > b) {             // GCD(a,b)= GCD(a%b,b) where a>b
            a = a % b;
        }
        else {
            b = b % a; 
        }
    }
    if(a == 0) {
        return b;
    }
    return a;
}
***********************************************************************************************


