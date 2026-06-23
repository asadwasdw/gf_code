#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[105][105];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y){
	for(int k=0;k<4;k++){
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(nx<1 || nx>n || ny<1 || ny>m) continue;
		if(a[nx][ny]=='0') continue;
		a[nx][ny]='0';
		dfs(nx,ny);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='0') continue;
			a[i][j]='0';
			ans++;
			dfs(i,j);
		}
	}
	cout<<ans;
	return 0;
}