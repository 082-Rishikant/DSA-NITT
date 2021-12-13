#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"enter\n";
    cin>>n;
    vector<string> vec;
    int i=1;
    while(i<=n)
    {
        if(i%15==0)
        {
            vec.push_back("FizzBuzz");
        }
        else if(i%5==0)
        {
            vec.push_back("Buzz");
        }
        else if(i%3==0)
        {
            vec.push_back("Fizz");
        }
        else
        {
            vec.push_back(to_string(i));
        }
        i++;
    }

    for(string ele:vec)
    {
        cout<<ele<<" ";
    }
}