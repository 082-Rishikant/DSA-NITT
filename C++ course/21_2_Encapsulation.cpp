#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int a;
        void publicfunc(){
            cout<<"public Function\n";
        }
    
    private:
        int b;
        void privatefunc(){
            cout<<"Private Function\n";
        }

    protected:
        int c;
        void protectedfunc(){
            cout<<"Protected Function\n";
        }
};

int main()
{
    // public 
    A obj;
    obj.publicfunc();
    obj.a=10;
    cout<<obj.a<<endl;
    
    // private
    // obj.privatefunc();  // This Error is due to the access modifiers

    // protected
    // obj.protectedfunc();  // This Error is due to the access modifiers

    return 0;
}