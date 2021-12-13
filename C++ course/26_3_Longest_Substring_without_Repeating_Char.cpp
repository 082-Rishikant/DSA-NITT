#include<iostream>
#include<string>
#include<vector>
using namespace std;

int optimizedApproach(string s)
{
    int ans=0; int l=0;
    vector<int> a(26,-1);
    int j=0, i=0;
    while(i<s.length() && j<s.length())
    {
        if(a[s[i]-'a']!=-1)
        {
            i=a[s[i]-'a']+1;
            ans=max(ans, l);
            l=0;
            for(auto it=a.begin();it!=a.end();it++)
            {
                *it=-1;
            }
        }
        a[s[i]-'a']=i;
        l++;
        i++;
    }
    return ans;
}

int moreOptimizedApproach(string s)
{
    int ans=0;
    vector<int> a(26,-1);
    int start=0;
    int i=0;
    while(i<s.length())
    {
        if(a[s[i]-'a']>start)
        {
            start=a[s[i]-'a'];
        }
        a[s[i]-'a']=i;
        ans=max(ans, i-start);
        i++;
    }
    return ans;
}

int main()
{
    cout<<optimizedApproach("pwwkewtuiwuwedghjksd")<<endl;;
    cout<<moreOptimizedApproach("pwwkewtuiwuwedghjksd");
    return 0;
}