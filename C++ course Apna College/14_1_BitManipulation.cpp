#include<iostream>
using namespace std;

int getBit(int n,int pos)
{
    /*
    if((n & (1<<pos))!=0)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    */

   // other short code 
   return ((n&(1<<pos))!=0);
}

int setBit(int n,int pos)
{
    return (n|(1<<pos));
}

int clearBit(int n,int pos)
{
    int mask=~(1<<pos);
    return (n&mask);
}

int updateBit(int n,int pos,int value)
{
    int mask=~(1<<pos);
    n=n&mask;
    return (n|(value<<pos));
}


int main()
{
    int n;
    int pos;
    /*
    cout<<"Enter boolean number and position to find the bit"<<endl;
    cin>>n>>pos;
    cout<<getBit(n,pos)<<endl;
    */

    /*  
    cout<<"Enter boolean number and position to set the bit"<<endl;
    cin>>n>>pos;
    cout<<setBit(n,pos)<<endl;
    */
    /*
    cout<<"Enter boolean number and position to clear the bit"<<endl;
    cin>>n>>pos; 
    cout<<clearBit(n,pos)<<endl;
    */

    int value;
    cout<<"Enter boolean number, position and value to update the bit"<<endl;
    cin>>n>>pos>>value; 
    cout<<updateBit(n,pos,value)<<endl;
    return 0;
}