#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char a[15];

bool check(string pw) {
	int vowel = 0;
	int consonant = 0;
	int length = pw.length();
	for (int i = 0; i < length; i++) {
		char c = pw[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}

		if (vowel > 0 && consonant > 1) {
			return true;
		}
	}
	return false;
}

void solve(int idx, string pw) {
	if ((int)pw.length() == L) {
		if (check(pw)) {
			cout << pw << endl;
			return;
		}
	}
	if (idx >= C) {
		return;
	}
	solve(idx + 1, pw + a[idx]);  //알파벳사용
	solve(idx + 1, pw);           //안할때
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> a[i];
	}
	sort(a, a + C);
	solve(0, "");
	return 0;
}