#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int a[1000];
int b[1000];
int n;

struct node{
	int v = 0;
	int lson = 0;
	int rson = 0;
}tr[1000];

unordered_map<int,int>num,num2;

int dfs(int l,int r) {
	if(l>r)return 0;
	// cout << l << r << endl;
	int root = b[l];
	for(int i = l; i <= r; i ++) {
		if(num[root] < num[b[i]]) {
			root = b[i];
		}
	}

	root = num2[root];

	tr[root].lson = dfs(l,root - 1);
	tr[root].rson = dfs(root + 1, r);
	return root;
}

int main(){

	cin >> n;
	for(int i = 1; i <=n ;i ++) {
		cin >> a[i];
		num[a[i]] = i;
	}
    
	for(int i = 1; i <=n ;i ++) {
		cin >> b[i];
		num2[b[i]] = i;
	}

	int root = dfs(1,n);
	// cout << 'x' << endl;

	queue<int>q;
	q.push(root);
    vector<int>ans;
	while(q.size()) {
		int t = q.front();q.pop();
		ans.push_back(b[t]);
		if(tr[t].lson) q.push(tr[t].lson);
		if(tr[t].rson) q.push(tr[t].rson);
	}
    for(int i = 0; i < ans.size();i ++) cout << ans[i] <<" \n"[i == ans.size()-1];

}
