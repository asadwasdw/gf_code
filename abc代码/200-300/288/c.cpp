#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
struct node{
	int to,next;	
}e[maxn];	
int cnt;	
int nums = 0;
int vis[maxn],pre[maxn];

map<int,vector<int>>d;
void dfs(int x,int fa){		
	vis[x] = 1;
       for(auto y:d[x]){
		if(y==fa)	continue;
		if(vis[y]==0){			
			pre[y] = x;
			dfs(y,x);			
		}else if(vis[y]==1){
			int temp = x;		
			int count = 1;
			while (temp!=y)		
			{

				count++;
				temp = pre[temp];
			}

			nums++;	
		}
	}
	vis[x] = 2;
}
int main()
{
	int n,m;int u,v;		
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> u >> v;
		d[u].push_back(v);
        d[v].push_back(u);
	}

	for(int i = 1;i <= n;i++){	
		if(vis[i]==0)				
			dfs(i,-1);
	}
	cout << nums << endl;		
	return 0;
}
