#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    unordered_map<string, int> menue;
    menue["pizza"]=120;
    menue["burger"]=40;
    menue["lato"]=400;
    menue.emplace("pam", 100);
    menue.erase("lato");

    if(menue.count("lato"))
    {
        cout<<"Lato Is there prize: "<<menue["lato"]<<"\n";
    }
    else
    {
        cout<<"Not there\n";
    }

    for(pair<string, int> item:menue)
    {
        cout<<item.first<<" "<<item.second<<endl;
    }

    return 0;
}