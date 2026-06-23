#include<bits/stdc++.h>
using namespace std;
int n,kk,ans;
int xx[25];
bool isp(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i ++) {
        if(x % i == 0) return false;
    }
    return true;
}
void dfs(int sum,int id,int k){
       if(k==kk){
        if(isp(sum)){
            ans++;
        }
        return ;
    }
    if(id>n){
        return ;
    }
 
    dfs(sum+xx[id],id+1,k+1);
    dfs(sum,id+1,k);
    return ;
}
int main(){
    cin>>n>>kk;
    for(int i=1;i<=n;i++){
        cin>>xx[i];
    }
    dfs(0,1,0);
    cout<<ans;
    return 0;
}
