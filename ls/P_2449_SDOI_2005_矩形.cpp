#include<bits/stdc++.h>
using namespace std;
int n,fa[7005],x[7005],xx[7005],y[7005],yy[7005];
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void hb(int x,int y){
	int nx=find(x),ny=find(y);
	if(nx!=ny){
		fa[nx]=ny;
	}
}
bool cmp(int i,int j){
	// if(xx[i]<x[j]||x[i]>xx[j]||yy[i]<y[j]||y[i]>yy[j]){
	// 	return true;
	// }
	// return false;

    int tx = min(xx[i], xx[j]) - max(x[i], x[j]);
    int ty = min(yy[i], yy[j]) - max(y[i], y[j]);
    if (tx < 0 || ty < 0) return true;   // 完全分离
    if (tx == 0 && ty == 0) return true; // 仅角接触
    return false;                
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		cin>>x[i]>>y[i]>>xx[i]>>yy[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!cmp(i,j)){
				hb(i,j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			ans++;
		}
	}
	cout<<ans; 
	return 0;
}