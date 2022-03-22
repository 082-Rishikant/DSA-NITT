#include<iostream>
#include<climits>
#include<unordered_set>
using namespace std;

int min_Bar(string s, unordered_set<string> st, int idx)
{
  if(s[idx]=='\0')
    return 0;
  
  int ans=INT_MAX;
  string curr="";
  for(int i=idx;s[i]!='\0';i++)
  {
    curr=curr+s[i];
    if(st.find(curr)!=st.end())
    {
      int temp=min_Bar(s, st, i+1);
      if(temp==-1)
        continue;
      ans=min(ans, temp+1);
    }
  }
  if(ans==INT_MAX)
    return -1;
  return ans;
}

int solve(string s, string words[], int n)
{
  unordered_set<string> st;
  for(int i=0;i<n;i++)
    st.insert(words[i]);
  
  return min_Bar(s, st, 0)-1;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif  
  string s="thequickbrownfox";
  string words[]={"the", "quickbrown", "fox", "quick", "brown"};

  // string s="thequickbrownfoxjumpsoverthehighbridge";
  // string words[]={"the","fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge", "the", "over", "bridge", "high", "tall", "quick", "brown"};

  cout<<solve(s, words, sizeof(words)/sizeof(words[0]));
  return 0;
}