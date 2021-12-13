#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> st={1, 3, 6,7 ,54,5};

    st.erase(3);

    if(st.find(6)!=st.end())
    {
        cout<<"Find at : "<<*st.find(6)<<"\n";
    }
    else{
        cout<<"not Find";
    }

    for(int item:st)
    {
        cout<<item<<" ";
    }
    return 0;
}