#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;
const int N = 1e9 + 7;
int c = 0;

bool canPutHere(vector<vector<int>> &ans, int i, int j, int n)
{
  int row=i;int col=j;
  for(int k=0;k<n;k++)
  {
    if(ans[row][k]!=0)
      return false;
  }
  for(int k=0;k<n;k++)
  {
    if(ans[k][col]!=0)
      return false;
  }
  while(row>=0 && col>=0)
  {
    if(ans[row][col]!=0)
      return false;
    row--;col--;
  }
  row=i;col=j;
  while(row<n && col<n)
  {
    if(ans[row][col]!=0)
      return false;
    row++;col++;
  }
  row=i;col=j;
  while(row>=0 && col<=(n-1))
  {
    if(ans[row][col]!=0)
      return 0;
    row--;col++;
  }
  row=i;col=j;
  while(row<n && col>=0)
  {
    if(ans[row][col]!=0)
      return false;
    row++;col--;
  }
  return true;
}

bool nQueen(vector<vector<int>> &ans, int n, int i)
{
  if (i == n)
  {
    if (c == n)
      return true;
    return false;
  }
  bool flag = false;
  for (int k = 0; k < n; k++)
  {
    // can we place a Queen here or not means is Queen safe here 
    if (canPutHere(ans, i, k, n))
    {
      ans[i][k] = 1;
      flag = true;
      c++;
      if(nQueen(ans, n, i+1))
        return true; // Success
      // Backtracking from here
      else  
      {
        ans[i][k]=0;
        flag=false;
        c--;
      }
    }
  }
  // not able put a queen in current row return false
  if(flag==false)
    return false;
}

int main()
{
  int n = 4;
  vector<vector<int>> ans(n, vector<int>(n, 0));
  cout<<nQueen(ans, n, 0)<<endl;
  for (auto vec : ans)
  {
    for (auto it : vec)
    {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}