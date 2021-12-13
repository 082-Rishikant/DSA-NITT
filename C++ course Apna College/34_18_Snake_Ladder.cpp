#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
 
int main()
{
    int l;cin>>l;
    map<int, int> ladder;
    for (int i = 0; i < l; i++)
    {
        int u, v;cin>>u>>v;
        ladder[u]=v;
    }
    int s;cin>>s;
    map<int, int> snake;
    for (int i = 0; i < s; i++)
    {
        int u, v;cin>>u>>v;
        snake[u]=v;
    }
    int moves=0;
    vector<bool> vis(101, false);
    queue<int> q;
    q.push(1);
    vis[1]=true;
    bool found=false;
    while(!q.empty() && !found)
    {
        int n=q.size();
        while(n--)
        {
            int temp=q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                if(temp+die==100)
                {
                    found=true;
                    break;
                }
                else if(temp+die<100 && ladder[temp+die] && !vis[ladder[temp+die]])
                {
                    vis[ladder[temp+die]]=true;
                    if(ladder[temp+die]==100)
                    {
                        found=true;
                        break;
                    }
                    q.push(ladder[temp+die]);
                }
                else if(temp+die<100 && snake[temp+die] && !vis[snake[temp+die]])
                {
                    vis[snake[temp+die]]=true;
                    // if(snake[temp+die]==100)
                    // {
                    //     found=true;
                    //     break;
                    // }
                    q.push(snake[temp+die]);
                }
                else 
                {
                    vis[temp+die]==true;
                    q.push(temp+die);
                }     
            } 
        }
        moves++;
    }
    cout<<moves;
    return 0;
}