#include<iostream>
using namespace std;
 
// void genBalPar(int ip, string op, int count)
// {
//     if(count<0)
//         return;
//     if(ip==0)
//     {
//         if(count==0)
//         {
//             cout<<op<<" ";
//         }
//         return;
//     }
//     genBalPar(ip-1, op+'(', count+1);
//     genBalPar(ip-1, op+')', count-1);
//     return;
// }

void genBalPar2(int o, int c, string op)
{
    if(o==0 && c==0)
    {
        cout<<op<<" ";
        return;
    }
    else if(c==o)
    {
        genBalPar2(o-1, c, op+'(');
    }
    else if(o==0)
    {
        genBalPar2(o, c-1, op+')');
    }
    else{
        genBalPar2(o-1, c, op+'(');
        genBalPar2(o, c-1, op+')');
    }
    return;
}

int main()
{
    int n=3;
    // genBalPar(n*2, "", 0);
    genBalPar2(n, n, "");
    return 0;
}