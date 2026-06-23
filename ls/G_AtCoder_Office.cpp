#include <bits/stdc++.h>
using namespace std;
const int N = 25 * 2501 + 1;
char s[N];
char ans[N];

void work() {
	int nn;
	int cnt = 0;
	cin >> nn;
    string ss; cin >> ss;

    nn = ss.size(); // 案例有问题，自己计算nn
    ss = " " + ss; 

	for (int i = 1; i <= nn; i ++) {
		s[i] = ss[i];
	}
	for (int i = 1; i <= nn; i ++) {
		if (s[i] != 'H' && s[i] != 'h' && s[i] != 'U' && s[i] != 'u' && s[i] != 'A' && s[i] != 'a' && s[i] != 's' && s[i] != 'S') {
			cout << "No" << endl;
			return;
		}
	}

	for (int i = 1; i <= nn; i ++) {
		if (s[i] == s[i - 1] || (abs(s[i] - s[i - 1]) == 'a' - 'A'))
			continue;
		cnt ++;
		ans[cnt] = s[i];
	} // 忽视大小写的离散化

	if (cnt != 4) {  // cnt < 4 说明个数少了 比如 hua   // cnt > 5 说明个数多了 比如 huash
        cout << "No" << endl;
        return;
	}

	if (ans[1] != 'H' && ans[1] != 'h') {
		cout << "No" << endl;
		return;
	}
	if (ans[2] != 'U' && ans[2] != 'u') {
		cout << "No" << endl;
		return;
	}
	if (ans[3] != 'A' && ans[3] != 'a') {
		cout << "No" << endl;
		return;
	}
	if (ans[4] != 'S' && ans[4] != 's') {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
}



int main() {
	int n;
	cin >> n;
	while (n --) {
		work();
	}
	return 0;
}