// 19.06.01
// 백준 #1697 : 숨바꼭질
// BFS 방식

#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>

using namespace std;

int N;
int K;
int visited[100010];
int MAX=100000;

int pos[3]={-1,1,2};

int solve()
{
    queue<pair<int,int>> q;
    pair<int,int> p=make_pair(N,0);
    q.push(p);
    visited[N]=1;

    while(!q.empty())
    {
        int cur=q.front().first;
        int time=q.front().second;
        q.pop();
        // cout<<cur<<" "<<time<<endl;

        if(cur==K)
        {
            return time;
        }

        for(int i=0; i<3; i++)
        {
            int next;
            if(i==2)
                next=cur*pos[i];
            else
                next=cur+pos[i];

            if(next==K)
            {
                return time+1;
            }

            if(next>=0 && next<=MAX && !visited[next])
            {
                visited[next]=1;
                q.push(pair<int,int>(next,time+1));
            }    
        }
    }
}

int main(void)
{
    cin>>N>>K;
    cout<<solve()<<endl;
    return 0;
}