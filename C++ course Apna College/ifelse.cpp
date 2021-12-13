#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Please enter the three  number:\n";
    cin>>a>>b>>c;
    if (a>b)
    {
        if (a>c)
        {
            cout<<a<<" is the gteatest value";
        }
        else
        {
            cout<<c<<" is the greatest value";
        }
        
        
    }
    else
    {
        if (b>c)
        {
            cout<<b<<" is the greatest value";
        }
        else
        {
            cout<<c<<" is the greatest value";
        }
        
        
    }
    
    return 0;
}