#include<iostream>
using namespace std;
void func(int m,int n)
{
    int j;
    for (int i = m; i <= n; i++)
    {
        int count=0;
        for (j = 2; j <= i/2; j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            cout<<i<<endl;
        }
        
    }
    return;
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    func(m,n);
    return 0;

}