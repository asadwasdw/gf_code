#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];

int main() {
	int n;
	cin >> n;
	map<int,int> m;
	a[1] = 1;
	m[a[1]] ++;
	for(int i = 2; i <= n; i ++) {
		if(a[i - 1] - i >= 1 &&  m[a[i - 1] - i] == 0) {
			a[i] = a[i - 1] - i; 
		} else {
			a[i] = a[i - 1] + i;
		}
		m[a[i]] ++;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}