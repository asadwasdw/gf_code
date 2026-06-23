#include<bits/stdc++.h>
using namespace std;
int n,a[105][105],ans=1e9;
bool vis[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
typedef pair<int,int> pii;
vector<pii> l,ansl;
int tx,ty,nx,ny,sx,sy;
void dfs(int x,int y,int len){
	if(x==tx && y==ty){
		if(ans>len){
			ansl=l;
			ans=len;
		}
		return;
	}
	for(int k=0;k<4;k++){
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(nx<1 || nx>n || ny<1 || ny>n) continue;
		if(a[x][y]) continue;
		if(vis[nx][ny]) continue;
		vis[nx][ny]=true;
		l.push_back({nx,ny});
		dfs(nx,ny,len+1);
		l.pop_back();
		vis[nx][ny]=false;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin>>sx>>sy>>tx>>ty;
	vis[sx][sy]=true;
	dfs(sx,sy,1);
	cout<<"("<<sx<<","<<sy<<")";
	for(int i=0;i<ansl.size();i++){
		cout<<"->("<<ansl[i].first<<","<<ansl[i].second<<")";
	}
	return 0;
}