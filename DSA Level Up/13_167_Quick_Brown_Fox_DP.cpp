#include<bits/stdc++.h>
using namespace std;

int min_Bar(string s, unordered_set<string> st, int idx, int t[])
{
  if(s[idx]=='\0')
    return 0;
  
  if(t[idx]!=-1)
    return t[idx];
  
  int ans=INT_MAX;
  string curr="";
  for(int i=idx;s[i]!='\0';i++)
  {
    curr=curr+s[i];
    if(st.find(curr)!=st.end())
    {
      int temp=min_Bar(s, st, i+1, t);
      if(temp==-1)
        continue;
      ans=min(ans, temp+1);
    }
  }
  if(ans==INT_MAX)
    return -1;
  return t[idx]=ans;
}

int min_bars(string s, string words[], int n){
    unordered_set<string> st;
    for(int i=0;i<n;i++)
        st.insert(words[i]);
    
    int t[s.size()];
    memset(t, -1, sizeof(t));
    return min_Bar(s, st, 0, t)-1;
}

int main(){
  string s="thequickbrownfox";
  string words[]={"the", "quickbrown", "fox", "quick", "brown"};


  cout<<min_bars(s, words, sizeof(words)/sizeof(words[0]))<<endl;
}