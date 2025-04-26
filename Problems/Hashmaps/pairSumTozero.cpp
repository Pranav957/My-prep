#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int,int> v;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int x=0-arr[i];
		if(v.find(x)!=v.end())
		{
			sum+=v[x];
		}
      v[arr[i]]++;
	}
	return sum;
}
// */#include<unordered_map>
// int pairSum(int *arr, int n) {
// 	// Write your code here
// 	unordered_map<int,int> Freq;
// 	int sum=0,ch=0;
// 	for(int i=0;i<n;i++)
// 	{
//        ++Freq[arr[i]];
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		int x=0-arr[i];
// 		if(ch<1)
// 		{
// 			if(x==0)
// 		{
// 			ch++;
// 			if(Freq.count(x)>0)
// 			{
// 				int p=Freq[x]-1;
// 			sum+=p*(p+1)/2;
// 			Freq.erase(arr[i]);
// 			}
// 		}
// 		}
// 		/*if(x==0)
// 		  {
			  
// 			  int p=0;
			
// 			 for(int i=0;i<Freq[x];i++)
// 			 {
//                 sum+=p;
// 				p++;
// 			 }
// 			  Freq.erase(arr[i]);
// 		  } */ 
		
// 		if(Freq.find(x)!=Freq.end())
// 		{
// 			sum+=Freq[arr[i]]*Freq[x];
// 		   Freq[arr[i]]=0;
// 		  Freq[x]=0;
// 		}
//         }
// 	return sum;
// }