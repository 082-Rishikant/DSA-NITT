#include <iostream>
// #include<stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

int max(int a,int b,int c)
{
    if(a>b)
    {
        if(a>c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b>c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

void isPythogon()
{
    int a, b, c;
    cout << "Enter three numbers" << endl;
    cin >> a >> b >> c;
    int x = max(a, b, c);
    int n2, n3;
    if (x == a)
    {
        // n1=a;
        n2 = b;
        n3 = c;
    }
    else if (x == b)
    {
        // n1=b;
        n2 = a;
        n3 = c;
    }
    else
    {
        // n1=a;
        n2 = b;
        n3 = a;
    }
    cout << x << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    if (pow(x, 2) == (pow(n2, 2) + pow(n3, 2)))
    {
        cout << "Yes";
        return;
    }
    cout << "No";
}

void binaryToDecimal()
{
    int a;
    cout<<"Enter binary number(0/1 Only) to convert into decimal form"<<endl;
    cin>>a;
    int ans=0,i=0;
    while (a>0)
    {
        ans=ans+(a%10)*pow(2,i);
        a=a/10;
        i++;
    }
    cout<<ans<<endl;
}

void octalToDecimal()
{
    int a;
    cout<<"Enter octal number(0-7 Only) to convert into decimal form"<<endl;
    cin>>a;
    int ans=0,i=0;
    while (a>0)
    {
        ans=ans+(a%10)*pow(8,i);
        a=a/10;
        i++;
    }
    cout<<ans<<endl;
}

void hexadecimalToDecimal()
{
    string s;
    cout<<"Enter hexadecimal number(0-9,A-F Only) to convert into decimal form"<<endl;
    cin>>s;
    int ans=0,p=0;
    for (int i = s.length()-1; i >= 0;  i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans=ans+(s[i]-'0')*pow(16,p);
        }
        else if(s[i]>='A' && s[i]<='F')
        {
            ans=ans+(s[i]-'A'+10)*pow(16,p);
        }
        else
        {
            cout<<"Entered number is not valid"<<endl;
            return;
        }
        
        p++;
    }
    cout<<ans<<endl;
}

void decimalToBinary()
{
    int a;
    cout<<"Enter decimal number(0-9 Only) to convert into Binary form"<<endl;
    cin>>a;
    int ans=0,i=0;
    while (a>0)
    {
        ans=ans+(a%2)*pow(10,i);
        a=a/2;
        i++;
    }
    cout<<ans<<endl;
}

void decimalToOctal()
{
    int a;
    cout<<"Enter decimal number(0-9 Only) to convert into Octal form"<<endl;
    cin>>a;
    int ans=0,i=0;
    while (a>0)
    {
        ans=ans+(a%8)*pow(10,i);
        a=a/8;
        i++;
    }
    cout<<ans<<endl;
}

void decimalToHexadecimal()
{
    int a;
    cout<<"Enter decimal number(0-9 Only) to convert into hexadecimal form"<<endl;
    cin>>a;
    string ans="";
    // int i=0;
    while (a>0)
    {
        if((a%16)>=0 && (a%16)<=9)
        {
            // char c=(char)a;
            ans=to_string(a%16)+ans;
            // cout<<c;
        }
        if((a%16)>=10 && (a%16)<=15)
        {
            char c=(a%16)-10+'A';
            // cout<<c;
            ans=c+ans;
            // ans.push_back(c);
        }
        a=a/16;
    }
    cout<<ans<<endl;
}


void addTwoBinary()
{
    int n1, n2;
    cout<<"Enter the numbers\n";
    cin>>n1;
    cin>>n2;
    int carry=0;int ans=0;int p=0;
    while(n1>0 && n2>0)
    {
        if(n1%10==0 && n2%10==0)
        {
            ans=ans+(carry*pow(10,p));
            carry=0;
        }
        else if(n1%10==1 && n2%10==1)
        {
            ans=ans+(carry*pow(10,p));
            carry=1;
        }
        else if(n1%10==0 && n2%10==1)
        {
            ans=ans+(((carry+1)%2)*pow(10,p));
            carry=carry;
        }
        else if(n1%10==1 && n2%10==0)
        {
            ans=ans+(((carry+1)%2)*pow(10,p));
            carry=carry;
        }
        else
        {
            cout<<"Entered wrong numbers\n";
            return;
        }
        p++; 
        n1=n1/10; 
        n2=n2/10;
    }

    while (n1>0)
    {
        if(n1%10==0)
        {
            ans=ans+(carry*pow(10,p));
            carry=0;
        }
        else if(n1%10==1)
        {
            ans=ans+(((carry+1)%2)*pow(10,p));
            carry=carry;
        }
        else
        {
            cout<<"Entered wrong numbers\n";
            return;
        }
        p++; 
        n1=n1/10;
    }

    while (n2>0)
    {
        if(n2%10==0)
        {
            ans=ans+(carry*pow(10,p));
            carry=0;
        }
        else if(n2%10==1)
        {
            ans=ans+(((carry+1)%2)*pow(10,p));
            carry=carry;
        }
        else
        {
            cout<<"Entered wrong numbers\n";
            return;
        }
        p++; 
        n2=n2/10;
    }

    ans=ans+(carry*pow(10,p));

    cout<<ans<<endl;
}

int main()
{
    // isPythogon();
    // binaryToDecimal(); 
    // octalToDecimal(); 
    // hexadecimalToDecimal(); 
    // decimalToBinary(); 
    // decimalToOctal(); 
    // decimalToHexadecimal(); 
    addTwoBinary();
    return 0;
}
