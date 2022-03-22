#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include<sstream>

const int N = 1e9 + 7;
using namespace std;

int main()
{
  // // 1. Using stringstream(buffer object, string to store token, delimeter) method
  // string s;
  // getline(cin, s);
  // stringstream ss(s); // creating object using constructor and it will work like read/write buffer
  // string token;
  // while (getline(ss, token, ' '))
  // {
  //   cout<<(token)<<", ";
  // }
  // cout<<endl;

  // // this is using the >> operator to read buffer one by one
  // while (ss>>token)
  // {
  //   cout<<(token)<<", ";
  // }
  // cout<<endl;

  // 2. Using strtok(original string, delimeter) method
  char str[100]; cin.getline(str, 100);
  char *token=strtok(str, " ");
  while (token!=NULL)
  {
    cout<<token<<", ";
    token=strtok(NULL, " ");
  }
  cout<<endl;
  
  return 0;
}