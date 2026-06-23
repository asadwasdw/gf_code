#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int a[N], b[N], s[N];
int n;
void debug() {
	for(int i = 1; i <= n; i ++) 
		cout << b[i] << " \n"[i == n];

	// 复原
	for(int i = 1; i <= n; i ++) {
		a[i] = a[i - 1] + b[i];
		cout << a[i] << " \n"[i == n];
	}
		
	
}

int main() {

    cin >> n;

	差分, 用于o1对区间进行修改操作（+, -）
    for(int i = 1; i <= n; i ++) {
		b[i] = a[i] - a[i - 1];
    }

	区间[x, y] 都加上k
	b[x] += k;
	b[y + 1] -= k;

	最后对b做前缀和进行复原





    return 0;
}