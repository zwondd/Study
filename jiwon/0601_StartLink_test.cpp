// 19.06.01
// 제한시간 : 1시간
// 백준 #5014 : 스타트링크
// BFS 방식
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000009]={0,};

int bfs()
{
    int cnt=0;
    int cur;

    queue<int> q;
    q.push(S);
    q.push(cnt);

    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        cnt=q.front();
        q.pop();
        // visited[cur]=1;
        // cout<<cur<<" "<<cnt<<endl;

        if(cur==G)
        {
            cout<<cnt<<endl;
            break;
        }

        if(cur+U>=1 && cur+U<=F && !visited[cur+U])
        {
            // cout<<cur+U<<"  ***"<<endl;
            q.push(cur+U);
            q.push(cnt+1);
            visited[cur+U]=1;
            // if(cur+U==G)
            // {
            //     cur+=U;
            //     cnt+=1;
            //     break;
            // }
        }

        if(cur-D>=1 && cur-D<=F && !visited[cur-D])
        {
            // cout<<cur-D<<"  ***"<<endl;
            q.push(cur-D);
            q.push(cnt+1);
            visited[cur-D]=1;

            // if(cur-D==G)
            // {
            //     cur-=D;
            //     cnt+=1;
            //     break;
            // }
        }
    }
    
    // if(cur==G)
    //     return cnt;
    // else
    //     return -1;
    if(cur!=G)
        cout<<"use the stairs"<<endl;
}

int main(void)
{
    int res;
    cin>>F>>S>>G>>U>>D;
    res=bfs();
    // if(res==-1)
    //     cout<<"use the stairs";
    // else
    //     cout<<res;

    return 0;
}
