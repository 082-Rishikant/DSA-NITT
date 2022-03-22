#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>

const int N = 1e9 + 7;
using namespace std;

char* own_tokenizer(char s[], char deli)
{
  static char* str_pointer=NULL;
  if(s!=NULL)
  {
    str_pointer=s;
  }
  if(str_pointer==NULL)
    return NULL;
  
  char * token=new char[strlen(str_pointer)+1];

  int i=0;
  while(str_pointer[i]!='\0')
  {
    if(str_pointer[i]!=deli)
    {
      token[i]=str_pointer[i];
      i++;
    }
    else{
      token[i]='\0';
      str_pointer+=(i+1);
      return token;
    }
  }
  token[i]='\0';
  str_pointer=NULL;
  return token;
}

int main()
{
  char s[1000];cin.getline(s, 1000);
  char * token = own_tokenizer(s, ' ');
  while (token != NULL)
  {
    cout << token << ", ";
    token = own_tokenizer(NULL, ' ');
  }
  return 0;
}