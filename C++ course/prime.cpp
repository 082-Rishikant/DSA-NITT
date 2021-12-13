#include <iostream>
using namespace std;
int main()
{
    int n,count=0;
    cout<<"Please enter the number:\n";
    cin>>n;
    for(int i=2;i<=(n/2);i++)
    {
        if(n%i==0)
        
        {
            cout<<"the number is not the prime number.\n";
            count++;
            break;
        }
        
    }
    if(count==0)
    {
        cout<<"the number is a prime number.\n ";
    }   
    
    int a,b,j;
    cout<<"Enter the two numbers :\n";
    cin>>a>>b;
    for (int i = a; i <= b; i++)
    {
        for (j = 2; j <i; j++)
        {
            if(i%j==0)
            {

                break;
            }
        
        }
        if(j==i)
        {
            cout<<i<<endl;
        }
        
    }
    
    
    return 0;
}