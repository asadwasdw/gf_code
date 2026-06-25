#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
// int a[N], b[N];
struct pre
{
	int a, b;
}p[N];

bool cmp(pre x, pre y) {
    if (x.a != y.a) return x.a < y.a;  // 按考试分数升序
    return x.b < y.b;                  // 分数相同按才艺分升序
}
int main() {
	int n, k, s;
	cin >> n >> k >> s;
	for(int i = 1; i <= n; i ++) {
		cin >> p[i].a >> p[i].b;
	}
	sort(p + 1, p + n + 1, cmp);
	map<int,int> m;
	int cnt = 0;
	while(k --) {
		int last = 0; //上一个人的分数
		for(int i = 1; i <= n; i ++) {
			if(p[i].a < 175) continue;
			if(m[i]) continue;
			if(p[i].a == last && p[i].b >= s) {
				cnt++;
				m[i] = 1;
				// cout << p[i].a << " " << p[i].b << endl;
			} else if(p[i].a > last) {
				last = p[i].a;
				cnt ++;
				m[i] = 1;
				// cout << p[i].a << " " << p[i].b << endl;
			}
		}
	}
	cout << cnt << endl;


	return 0;
}