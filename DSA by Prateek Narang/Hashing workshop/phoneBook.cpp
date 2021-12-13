#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    map<string, vector<string>> contacts;
    contacts["Aman"]={"453453535", "2323453452"};
    contacts["Mahit"]={"454353453", "45252", "45252525223"};
    contacts["Lalit"]={"+534545345", "8888888", "22222"};
    contacts["lato"]={"666666", "444444444"};
    contacts["pam"].push_back("44444444444");
    contacts["pam"].push_back("44444444444");
    contacts["pam"].push_back("44444444444");
    contacts.erase("pam");

    if(contacts.count("pam"))
    {
        cout<<"Lato Is there prize: ";
        for(string item:contacts["pam"])
        {
            cout<<item<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Not there\n";
    }

    for(pair<string, vector<string>> item:contacts)
    {
        cout<<item.first<<"=";
        for(string number:item.second)
        {
            cout<<number<<" ";
        }
        cout<<endl;
    }

    return 0;
}