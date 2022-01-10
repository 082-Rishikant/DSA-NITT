#include<iostream>
#include<vector>
#include <algorithm>
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

const int N=1e9+7;
using namespace std;

class first{
  public:
    first()
    {
      cout<<"first\n";
    }
};
class second{
  public:
    second()
    {
      cout<<"second\n";
    }
};
class third{
  public:
    third()
    {
      cout<<"third\n";
    }
};
class fourth:public third, public first, public second{
  public:
    fourth()
    {
      cout<<"fourth\n";
    }
};

int main()
{
  fourth d;
  return 0;
}