#include<iostream>
#include<unordered_map>
using namespace std;

string makeStr(int arr[])
{
  string ans="";
  for(int i=0;i<26;i++)
  {
    if(arr[i]>0)
    {
      char temp=('a'+i);
      ans=ans+temp+to_string(arr[i]);
    }
  }
  return ans;
}

void solve(string s, int &ans)
{
  int n=s.size();
  unordered_map<string, int> mp; // (string, counter)
  for(int i=0;i<n;i++)
  {
    int arr[26]={0};
    for(int j=i;j<n;j++)
    {
      arr[s[j]-'a']++;
      string temp=makeStr(arr);
      //check whether this string is already there?
      if(mp.find(temp)==mp.end())
        mp[temp]=1;
      else
        mp[temp]++;
    }
  }

  // Now count the # anagram pairs
  for(auto it:mp)
  {
    if(it.second>1)
    {
      ans=ans+(it.second*(it.second-1))/2;
    }
  }
  return;
}

int main()
{
  string s="abba";
  int ans=0;
  solve(s, ans);
  cout<<ans;
  return 0;
}