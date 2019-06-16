// 19.06.09
// 제한시간 : 1시간
// 백준 #9466 : 텀 프로젝트

#include <iostream>
#include <string.h>

using namespace std;

int T;
const int MAX=100000;
int num[MAX+1]={0,};
int check[MAX+1]={0,};

int res[100000]={0,};

bool dfs(int start, int next) {
    cout<<"start : "<<start<<" next : "<<next<<endl;
    // check[start] = 1;
    check[next] = 1;

    if ( start!=next && next==num[next] ) {
        check[next]=2;
        return false;
    } else if ( start==num[next] ) {
        check[next]=2;
        return true;
    } else if ( start==num[start] ) {
        check[start]=2;
        return true;
    }

    if( check[num[next]]==0 ) {
        if( dfs(next,num[next]) ) {
            check[start]=2;
            check[next]=2;
            return true;
        } else {
            return false;
        }
    }
}

int solve(int n) {
    int start=1;
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if ( i==num[i] ) {
            check[i] = 2;
            continue;
        }

        if( check[i]==0 ) {
            check[i]=1;
            dfs(i,num[i]);
        } 
    }

    for(int i=1; i<=n; i++) {
        cout<<"check : "<<check[i]<<" ";
        if( check[i]!=2 ) {
            cnt++;
        }
    }
    // cout<<endl;
    return cnt;
}

int main(void) {
    int student_num=0;
    cin>>T;

    for(int i=1; i<=T; i++) {
        cin>>student_num;
        for(int j=1; j<=student_num; j++) {
            cin>>num[j];
        }
        res[i]=solve(student_num);
        memset(check,0,sizeof(check));
    }

    for(int i=1; i<=T; i++)
        cout<<res[i]<<endl;


    return 0;
}