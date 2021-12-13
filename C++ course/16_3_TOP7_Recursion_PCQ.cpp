#include<bits/stdc++.h>
using namespace std;

void reverseS(string s)
{
    /*
    // my WAY
    if(i==s.length())
    {
        return;
    }
    reverseS(s,i+1);
    printf("%c",s[i]);
    */

    //    Official WAY
    if(s.length()==0)
    {
        return;
    }
    string ss=s.substr(1);
    reverseS(ss);
    printf("%c",s[0]);
}

void replacePI(string s)
{
    if(s.length()==1)
    {
        cout<<s[0];
        return;
    }
    if(s[0]=='p' && s[1]=='i')
    {
        printf("%.2f",3.14);
        replacePI(s.substr(2));
    }
    else
    {
        cout<<s[0];
        replacePI(s.substr(1));
    }
    
}

void towerOfHanoi(int n, char source, char dest, char helper)
{
    if(n==0)  //Base case
    {
        return;  
    }
    towerOfHanoi(n-1, source, helper, dest);
    cout<<"Move from "<<source<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, source);
}

string removeDup(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(s[0]==s[1])
    {
        return ans;
    }
    else
    {
        return ch+ans;
    }
    

}

string moveXtoEnd(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    string ans=moveXtoEnd(s.substr(1));
    if(s[0]=='x')
    {
        return ans+s[0];
    }
    else
    {
        return s[0]+ans;
    }
}

void subString(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string ros = s.substr(1);
    subString(ros, ans+ch);
    subString(ros, ans);
}

void subStringASCII(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros = s.substr(1);
    subStringASCII(ros, ans+ch);
    subStringASCII(ros, ans+to_string(code));
    subStringASCII(ros, ans);
}

string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqr","stu","vwx","yz"};
void keyPad(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;        
        return;
    }
    char ch=s[0];
    string code=keypadArr[ch-'0'];
    string ros=s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keyPad(ros,ans+code[i]);
    }
    
}

int main()
{
    string s="piixxsssxxmmxxdoPi";
    // reverseS(s);

    // replacePI(s);

    // towerOfHanoi(3,'A','C', 'B');

    // cout<<removeDup(s)<<"\n";

    // cout<<moveXtoEnd(s);

    // subString("abc","");

    // subStringASCII("ab","");

    keyPad("23","");
    return 0;
}