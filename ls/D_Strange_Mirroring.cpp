#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int l = s.size();
	int q; cin >> q;
	while(q--) {
		long long y; cin >> y; y--;
		int x = 63;
        int cnt = 0;
		for(int i=x; i>=0; i--) {
            __int128_t t = l*(((__int128)1<<i));

			if(y>=t) y -= t, cnt ++;
		}

        if(cnt % 2 == 0)
            cout << s[y];
        else {
            if('a'<=s[y] && s[y]<='z') cout << (char)(s[y] - 'a' + 'A');
            else cout << (char)(s[y] - 'A' + 'a');
        }
        cout << " ";
	}
	return 0;
}
