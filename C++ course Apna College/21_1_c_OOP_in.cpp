#include<bits/stdc++.h>
using namespace std;

class student{ //  creating a class name as student
    public:
        // Data members of class student
        string name;
        int age;
        bool gender;  // 1 for male.     0 for female.
        
        student() // Default CONSTRUCTOR
        {
            cout<<"\n\nDefault CONSTRUCTOR";
        }

        student(string s, int a, int g) // Parameterised CONSTRUCTOR
        {
            cout<<"\nParameterised CONSTRUCTOR";
            name=s;
            age=a;
            gender=g;
        }


        student(student &a) // Copy CONSTRUCTOR
        {
            cout<<"\n\nCopy CONSTRUCTOR";
            name=a.name;
            age=a.age;
            gender=a.gender;
        }

        ~student() // DESTRUCTOR
        {
            cout<<"\n\nDESTRUCTOR called"; // It will be called when the MAIN function will end
            // and it will be called #time= #object or constructor created
        }

        bool operator == (student &a){
            if(name==a.name && age==a.age && gender==a.gender)
            {
                return true;
            }
            return false;
        }

        void print()
        {
            cout<<"\nName is: "<<name;
            cout<<"\nAge is: "<<age;
            cout<<"\nGender is: "<<gender;
        }
        
};

int main()
{
    // calling of CONSTRUCTOR
    student a("Rishi", 22, 1);
    a.print();
    
    // Default CONSTRUCTOR
    student b;  

    //  Copy CONSTRUCTOR
    // student c(a);
        // or
    student c=a;
    c.print();

    // Operator OVERLOADING
    if(a==c)
    {
        cout<<"\n\nSame";
    }
    else
    {
        cout<<"\n\nNot Same";
    }

    return 0;
}