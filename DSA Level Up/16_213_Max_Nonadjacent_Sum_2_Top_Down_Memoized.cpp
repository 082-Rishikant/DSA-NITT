// #include<iostream>
// #include<vector>
// #include <algorithm>
// #include<string.h>
// #include<map>
// #include<set>
// #include<unordered_map>
// #include<unordered_set>
// #include<climits>

// const int N=1e9+7;
// using namespace std;
// int *t;

// int maxNonadjacentSum(vector<int> arr, int n, int curr){
//   if(curr==(n-1))
//     return arr[curr];
//   if(curr>=n)
//     return 0;
//   if(t[curr]!=-1)
//     return t[curr];
  
//   int temp;
//   if((curr+2)<n){
//     if(t[curr+2]==-1)
//       t[curr+2]=maxNonadjacentSum(arr, n, curr+2);
//     if(t[curr+1]==-1)
//       t[curr+1]=maxNonadjacentSum(arr, n, curr+1);
    
//     temp=max(t[curr+2]+arr[curr], t[curr+1]);
//   }else{
//     if(t[curr+1]==-1)
//       t[curr+1]=maxNonadjacentSum(arr, n, curr+1);
    
//     temp=t[curr+1];
//   }

//   return t[curr]=temp;
// }

// int main()
// {


//   vector<int> arr={6,10,12,7,9,14};
//   int n=arr.size();

//   t=new int[n];
//   for(int i=0;i<n;i++){
//     t[i]=-1;
//   }

//   cout<<maxNonadjacentSum(arr, n, 0);

//   return 0;
// }