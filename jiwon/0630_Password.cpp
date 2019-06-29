// 19.06.30
// 백준 #1759 : 암호 만들기

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int L, C;
char arr[20];
char visit[20];
char password[20];
int vowel, consonant;

void solve(int cur, int depth) {
    if ( depth == L ) {
        if ( vowel>=1 && consonant>=2 ) {
            cout<<password<<endl;
        } 
    } else {
        for(int i=cur; i<C; i++) {
            if ( !visit[i] ) {
                password[depth] = arr[i];
                visit[i] = 1;

                if ( arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i] =='o' || arr[i]=='u') 
                    vowel++;
                else 
                    consonant++;

                solve(i+1, depth+1);

                if ( arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i] =='o' || arr[i]=='u') 
                    vowel--;
                else 
                    consonant--;
                visit[i] = 0;
            } 
        }
    }
}


int main() {
    cin>>L>>C;
    for(int i=0; i<C; i++) {
        cin>>arr[i];
    }

    sort(arr, arr+C);

    solve(0,0);

    return 0;
}
