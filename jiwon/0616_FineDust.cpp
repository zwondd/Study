// 19.06.15
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

void printMap() {
    cout<<" map_new "<<endl;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout<<map_new[i][j]<<" ";
        }
        cout<<endl;
    }
}

void diffusion() {
    // cout<<"diffusion"<<endl;
    queue<int> q;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if( map[i][j] != 0 && map[i][j] != -1 ) {
                int tmp = map[i][j]/5;
                q.push(i);
                q.push(j);
                q.push(tmp);
            }
            if( map[i][j]==-1 && map[i+1][j]==-1 ) {
                air_up[0]=i;
                air_up[1]=j;
            } 
        }
    }

    while(!q.empty()) {
        int x, y, amount;
        int cnt=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        amount=q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<R && ny>=0 && ny<C && map[nx][ny]!=-1) {
                map_new[nx][ny]+=amount;
                cnt++;
            }
        }

        map_new[x][y]=map_new[x][y]-(amount*cnt);
    }
}

void airCleaning() {
    // cout<<"air cleaning"<<endl;
    int flag=0;
    int x, y, nx, ny;
    int tmp_cur, tmp_next;

    int dx[]={0,-1,0,1};
    int dy[]={1,0,-1,0};

    x=air_up[0]+dx[flag];
    y=air_up[1]+dy[flag];
    tmp_cur=map_new[x][y];
    map_new[x][y]=0;

    // upper air cleaning
    while ( true ) {
        nx=x+dx[flag];
        ny=y+dy[flag];
        // cout<<"up nx : "<<nx<<" ny: "<<ny<<endl;

        if ( nx==air_up[0] && ny==air_up[1] ) {
            break;
        }

        tmp_next=map_new[nx][ny];

        if( nx>=0 && nx<R && ny>=0 && ny<C && map_new[nx][ny]!=-1 ) {
            map_new[nx][ny]=tmp_cur;
            tmp_cur=tmp_next;
            x=nx;
            y=ny;
        } else {
            flag=(flag+1)%4;
        }
    }

    // bottom air cleaning
    flag=0;
    x=air_up[0] + 1 + dx[flag];
    y=air_up[1] + dy[flag];
    tmp_cur=map_new[x][y];
    map_new[x][y]=0;

    while ( true ) {
        nx=x+dx[flag];
        ny=y+dy[flag];
        // cout<<"bottom nx : "<<nx<<" ny: "<<ny<<endl;

        if ( nx==air_up[0]+1 && ny==air_up[1] ) {
            break;
        }

        tmp_next=map_new[nx][ny];

        if( nx>=0 && nx<R && ny>=0 && ny<C && map_new[nx][ny]!=-1 ) {
            map_new[nx][ny]=tmp_cur;
            tmp_cur=tmp_next;
            x=nx;
            y=ny;
        } else {
            flag=(flag+3)%4;
        }
    }
}

int getTotal()
{
    // cout<<"get total"<<endl;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j]!=-1)
                total+=map[i][j];
        }
    }
}

int main(void)
{
    cin>>R>>C>>T;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>map[i][j];
            map_new[i][j] = map[i][j];
        }
    }

    for(int i=0; i<T; i++) {
        diffusion();
        airCleaning();
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                map[i][j]=map_new[i][j];
            }
        }
    }
    getTotal();
    cout<<total<<endl;

    return 0;
}