#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        void func()
        {
            cout<<"No argument\n";
        }
        void func(int a)
        {
            cout<<"with integer arguments:    "<<a<<"\n";
        }
        void func(double a)
        {
            cout<<"with float arguments:    "<<a<<"\n";
        }
};

class Complex{
    private:
        int real, imag;
    public:
        // Complex()
        // {

        // }
        Complex(int r=0, int i=0){
            real=r;
            imag=i;
        }
        Complex operator + (Complex const &obj)
        {
            Complex res;
            res.imag=imag+obj.imag;
            res.real=real+obj.real;
            return res;
        }
        void display()
        {
            cout<<real<<"+i"<<imag<<endl;
        }
        
};

class Base{
    public:
        virtual void print()  // Here we have used Virtual function
        {
            cout<<"Print Base\n";
        }
        void display()
        {
            cout<<"Display Base\n";
        }    
};
class derived: public Base{
    public:
        void print()
        {
            cout<<"Print derived\n";
        }
        void display()
        {
            cout<<"Display derived\n";
        }   
};

int main()
{

    // A obj;
    // obj.func();
    // obj.func(2);
    // obj.func(3.5);

    // Complex c1(3,4), c2(5,7);
    // Complex c3=c1+c2;
    // c3.display();

    Base *basepointer;
    derived d;
    basepointer=&d;
    basepointer->print();
    basepointer->display();

    // derived d;
    // d.print();
    // d.display();
    return 0;
}