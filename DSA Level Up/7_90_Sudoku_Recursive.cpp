#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e9 + 7;
using namespace std;

bool caniPutHere(vector<vector<int>> ans, int el, int row, int col, int n)
{
  for(int i=0;i<n;i++)
  {
    if(ans[row][i]==el)
      return false;
  }
  for(int i=0;i<n;i++)
  {
    if(ans[i][col]==el)
      return false;
  }
  int r=row/3;
  int c=col/3;
  for(int i=(3*r);i<(3*r+3);i++)
  {
    for(int j=(3*c);j<(3*c+3);j++)
    {
      if(ans[i][j]==el)
        return false;
    }
  }
  return true;
}

bool sudoku1(vector<vector<int>> &ans, int n, int row, int col)
{
  if (row == n)
  {
    return true;
  }
  // if prefilled position
  if (ans[row][col] != 0)
  {
    if (row < n && col < (n - 1))
      return sudoku1(ans, n, row, col + 1);
    else if (row < n && col >= (n - 1))
      return sudoku1(ans, n, row + 1, 0);
  }
  //all possible columns
  for (int el = 1; el <= n; el++)
  {
    if (caniPutHere(ans, el, row, col, n))
    {
      ans[row][col] = el;
      if (row < n && col < (n - 1))
      {
        if (sudoku1(ans, n, row, col + 1))
          return true;
        else
          ans[row][col] = 0;
      }
      else if (row < n && col >= (n - 1))
      {
        if (sudoku1(ans, n, row + 1, 0))
          return true;
        else
          ans[row][col] = 0;
      }
    }
  }
  return false;
}

int main()
{
  vector<vector<int>> ans;
  ans = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0},
      {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0},
      {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1},
      {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0},
      {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}
      };
  int n = 9;
  int row = 0;
  int col = 0;
  cout << sudoku1(ans, n, row, col)<<endl;
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