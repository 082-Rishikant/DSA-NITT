#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string formMaxStr(string s)
{
    int n=s.size();
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=s[i]-'0'; // '0' = 48
    }
    sort(arr, arr+n);
    for(int i=0;i<n;i++)
    {
        s[i]=arr[n-1-i]+'0';
    }
    return s;
}

vector<char> charMaxFreq(string s)
{
    int n=s.size();
    int arr[26]={0};
    for(int i=0;i<n;i++)
    {
        arr[s[i]-'a']++;
    }
    int maxf=0; char ch;
    for(int i=0; i<26;i++)
    {
        if(arr[i]>maxf)
        {
            maxf=arr[i];
            ch=i+'a';
        }
    }
    vector<char> vec;
    vec.push_back(maxf+'0'); // '0' = 48 in decimal
    vec.push_back(ch);
    return vec;
}

int main()
{
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    // for(int i=0;i<s.size();i++)
    // {
    //     if(s[i]>='A' && s[i]<='Z') // 'A' = 65 | 'Z' = 90
    //     {
    //         s[i]=s[i]+32;
    //     }
    // }
    // transform(s.begin(), s.end(), s.begin(), ::toupper);
    // cout<<s<<endl;

    // for(int i=0;i<s.size();i++)
    // {
    //     if(s[i]>='a' && s[i]<='z') // 'a' = 97 | 'z' = 112
    //     {
    //         s[i]=s[i]-32;
    //     }
    // }
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout<<s;

    // cout<<formMaxStr(s)<<endl;
    // char c='B'+32;
    // cout<<endl<<c; // It will print b

    // sort(s.begin(), s.end(), greater<int>());
    // cout<<s;

    vector<char> vec=charMaxFreq(s);
    for(auto it:vec)
    {
        cout<<it<<" ";
    }
    return 0;
}