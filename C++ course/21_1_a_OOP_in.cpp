#include<bits/stdc++.h>
using namespace std;

class student{ //  creating a class name as student
    public:
        // Data members of class student
        string name;
        int age;
        bool gender;  // 1 for male.     0 for female.

        void print()
        {
            cout<<"\n\nName is: "<<name;
            cout<<"\nAge is: "<<age;
            cout<<"\nGender is: "<<gender;
        }
};

int main()
{
    // how to access the data members of student*****
    student a;  // making an object of student class
    a.name="Rishi";
    a.age=22;
    a.gender=1;
    
    // 1st method to print
    cout<<a.name<<endl;
    cout<<a.age<<endl;
    cout<<a.gender<<endl;
    
    // 2nd method to print
    a.print(); // to print the values of data members

    // this is the another way of accessing the class a nd data members. 
    // and here we can give values to data members by using array.
    student arr[2];
    for(int i=0;i<2;i++)
    {
        cout<<"\nName:";
        cin>>arr[i].name;
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