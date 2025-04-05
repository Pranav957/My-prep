int knapsack(int *weights, int *values, int n, int maxWeight) {
    // write your code here
    if (n == 0 || maxWeight == 0)
      return 0;
  
    if (weights[0] > maxWeight)
      return knapsack(weights + 1, values + 1, n - 1, maxWeight);
  
    int x = values[0] +
            knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(x, y);
  }
  
  int knapsack_helper(int *weights, int *values, int n, int maxwt,int** arr) {
    // write your code here
    if (n == 0 || maxwt == 0)
      return 0;
   if(arr[n][maxwt]!=-1)
      return arr[n][maxwt];
      int ans;
    if (weights[0] > maxwt)
      ans= knapsack_helper(weights + 1, values + 1, n - 1, maxwt,arr);
  else
   {
    int x = values[0] + knapsack_helper(weights + 1, values + 1, n - 1, maxwt - weights[0],arr);
    int y = knapsack_helper(weights + 1, values + 1, n - 1, maxwt,arr);
    ans= max(x, y);
   }
   arr[n][maxwt]=ans;
   return ans;
  }
  
  int knapsackS(int* weight, int* value, int n, int maxWeight) {
      // Write your code here
      int ** arr=new int*[n+1];
  for(int i=0;i<=n;i++)
  {
    arr[i]=new int[maxWeight+1];
    for(int j=0;j<=maxWeight;j++)
      arr[i][j]=-1;
  }
      return knapsack_helper(weight,value,n,maxWeight,arr);
      
  }
  /*int knapsackS(int *weight, int *value, int n, int maxWeight)
  {
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
      arr[i] = new int[maxWeight + 1];
          }
    for(int i=0;i<n+1;i++)
       arr[i][0]=0;
     for(int j=1;j<=maxWeight;j++)
        arr[0][j]=0;
        for(int i=1;i<=n;i++)
        {
          for(int j=1;j<=maxWeight;j++)
          {
             if(weight[i-1]>j)
                 arr[i][j]=arr[i-1][j];
             else {
               int x=value[i-1]+arr[i - 1][j-weight[i-1]] ;
             int y = arr[i - 1][j];
             arr[i][j]=max(x,y);
             }    
                  
          }
        }  
        return arr[n][maxWeight];
  }*/
  int knapsackSe(int *weight, int *value, int n, int maxWeight) {
    // Write your code here
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
      arr[i] = new int[maxWeight + 1];
      for (int j = 0; j <= maxWeight; j++)
        arr[i][j] = -1;
    }
    return knapsack_helper(weight, value, n, maxWeight, arr);
  }
  int knapsack(int *weight, int *value, int n, int maxWeight) {
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
      arr[i] = new int[maxWeight + 1];
    }
    for (int i = 0; i < n + 1; i++)
      arr[i][0] = 0;
    for (int j = 1; j <= maxWeight; j++)
      arr[0][j] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= maxWeight; j++) {
        if (weight[n-i] > j)
          arr[i][j] = arr[i - 1][j];
        else {
          int x = value[n-i] + arr[i - 1][j - weight[n-i]];
          int y = arr[i - 1][j];
          arr[i][j] = max(x, y);
        }
      }
    }
    return arr[n][maxWeight];
  }