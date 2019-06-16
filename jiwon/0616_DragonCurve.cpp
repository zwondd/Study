// 19.06.16
// 백준 #15685 : 드래곤커브

#include <iostream>
#include <queue>
using namespace std;

int N;
typedef struct _Dragon {
    int x,y,d,g;
}Dragon;
queue<Dragon> dragonQ;
int dx[] = {1,0,-1,0};

void inputData() {
    cin>>N;
    for(int i=0; i<N; i++) {
        Dragon dragon;
        cin>>dragon.x>>dragon.y>>dragon.d>>dragon.g;
        dragonQ.push(dragon);
    }
}

void makeDragonCurve() {

}

void countSquare() {

}

int main() {
    inputData();
    

    return 0;
}