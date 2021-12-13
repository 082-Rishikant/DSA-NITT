#include <iostream>
using namespace std;
int main()
{
    int n,r=0;
    cout<<"please enter the number:\n";
    cin>>n;
    while(n>0)
    {
        r=n%10;
        cout<<r;
        n=n/10;
    }
    cout<<"\n";
    return 0;

}