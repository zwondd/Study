// 19.06.09
// 제한시간 : 1시간
// 백준 #17144 : 미세먼지 안녕!

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
int map[MAX+1][MAX+1];
int map_new[MAX+1][MAX+1];
int R, C, T;
int total=0;

int air_up[2];

void diffusion()
{
    cout<<"diffusion"<<endl;
    queue<int> q;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if( map[i][j] != 0 && map[i][j] != -1 )
            {
                int tmp = map[i][j]/5;
                q.push(i);
                q.push(j);
                q.push(tmp);
            }

            if( map[i][j]==-1 && map[i+1][j]==-1)
            {
                air_up[0]=i;
                air_up[1]=j;
            } 
        }
    }

    while(!q.empty())
    {
        int x,y,amount;
        int cnt=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        amount=q.front();
        q.pop();

    

        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<R && ny>=0 && ny<C && map[nx][ny]!=-1)
            {
                map_new[nx][ny]+=amount;
                cnt++;
            }
        }

        map_new[x][y]=map_new[x][y]-(amount*cnt);
    }


    // cout<<" map_new "<<endl;
    // for(int i=0; i<R; i++)
    // {
    //     for(int j=0; j<C; j++)
    //     {
    //         cout<<map_new[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

   
}

void airCleaning()
{
    // ---------------------------
    cout<<"air cleaning"<<endl;
    int flag=0;
    int nx,ny;
    int dx[]={0,-1,0,1};
    int dy[]={1,0,-1,0};

    int x=air_up[0]+dx[flag];
    int y=air_up[1]+dy[flag];
    int tmp=map_new[x][y];

    // upper air cleaning
    while (map_new[x][y]!=-1)
    {
        nx=x+dx[flag];
        ny=y+dy[flag];
        cout<<"nx : "<<nx<<" ny: "<<ny<<endl;

        if( nx>=0 && nx<R && ny>=0 && ny<C && map_new[nx][ny]!=-1 )
        {
            tmp=map_new[nx][ny];
            map_new[nx][ny]=map_new[x][y];



            map_new[nx][ny]=map[x][y];
            tmp=map_new[x][y];
            x=nx;
            y=ny;
        }
        else
        {
            flag=(flag+1)%4;
        }
    }

    // bottom air cleaning
    x=air_up[0]-1;
    y=air_up[1];
    flag=3;

    while (map_new[x][y]!=-1)
    {
        nx=x+dx[flag];
        ny=y+dy[flag];
        cout<<"nx : "<<nx<<" ny: "<<ny<<endl;


        if( nx>=0 && nx<R && ny>=0 && ny<C && map_new[nx][ny]!=-1 )
        {
            tmp=map_new[nx][ny];
            map_new[nx][ny]=map[x][y];
        }
        else
        {
            flag=(flag+1)%4;
        }
    }
}

int getTotal()
{
    cout<<"get total"<<endl;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(map_new[i][j]!=-1)
                total+=map_new[i][j];
            else if(map_new[i+1][j]==-1)
                total-=map_new[i-1][j];
            else
                total-=map_new[i+1][j];
        }
    }
}

int main(void)
{
    cin>>R>>C>>T;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>map[i][j];
            map_new[i][j] = map[i][j];
        }
    }

    

    for(int i=0; i<T; i++)
    {
        diffusion();
        airCleaning();
    }
    getTotal();
    cout<<total<<endl;

    return 0;
}