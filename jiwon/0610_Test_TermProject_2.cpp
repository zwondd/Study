// 19.06.09
// 제한시간 : 1시간
// 백준 #9466 : 텀 프로젝트

#include <iostream>
#include <string.h>

using namespace std;

int T;
const int MAX=100000;
int student_num=0;

int student[MAX+1]={0,};
int team[MAX+1]={0,};
int visited[MAX+1]={0,};

int cnt=0;

int res[100000]={0,};

void dfs(int k) {
    visited[k] = 1;
    // cout<<" dfs k : "<<k<<endl;

    if( !visited[student[k]] ) {
        dfs(student[k]);
    } else {
        // cout<<"visited[team[k]]  " <<k<<endl;

        if( !team[student[k]] ) {
            for(int j=student[k] ; j!=k; j=student[j] ) {
                cnt++;
                team[j]=1;
            }
            cnt++;
        } 
    } 
    team[k]=1;
}

int solve() {
    memset(visited, 0, sizeof(visited));
    memset(team, 0, sizeof(team));
    cnt=0;

    for(int i=1; i<=student_num; i++) {
        if( !visited[i] ) {
            dfs(i);
        }
    }
    return (student_num-cnt);
}

int main(void) {
    cin>>T;

    for(int i=1; i<=T; i++) {
        cin>>student_num;
        for(int j=1; j<=student_num; j++) {
            cin>>student[j];
        }
        res[i]=solve();
    }

    for(int i=1; i<=T; i++) {
        cout<<res[i]<<endl;
    }

    return 0;
}