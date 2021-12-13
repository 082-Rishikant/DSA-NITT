#include<bits/stdc++.h>
using namespace std;

class student{ //  creating a class name as student
        string name; // this is private data member
    public:
        // Data members of class student
        int age;
        bool gender;  // 1 for male.     0 for female.

        void setName(string s)  // Function to access name(data member) outside of the class 
        {
            name=s;
        }

        void printName()  // Function to print the name outside of the class
        {
            cout<<"\nName is: "<<name;
        }

        void print()
        {
            printName();
            cout<<"\nAge is: "<<age;
            cout<<"\nGender is: "<<gender;
        }
};

int main()
{
    // how to access the data members of student*****
    student a;  // making an object of student class
    string s="Rishi";
    a.setName(s);
    a.age=22;
    a.gender=1;
    
    // 1st method to print
    a.printName();
    cout<<"\nAge is: "<<a.age;
    cout<<"\nGender is: "<<a.gender;
    
    // 2nd method to print
    a.print(); // to print the values of data members

    // this is the another way of accessing the class a nd data members. 
    // and here we can give values to data members by using array.
    student arr[2];
    for(int i=0;i<2;i++)
    {
        cout<<"\nName:";
        string name;
        cin>>name;
        arr[i].setName(name);
        cout<<"age:";
        cin>>arr[i].age;
        cout<<"gender:";
        cin>>arr[i].gender;
    }
    for(int i=0;i<2;i++)
    {
        arr[i].print(); // to print the data members of class student
    }

    return 0;
}