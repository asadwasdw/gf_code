#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[205][205],s[205][205];
int get(int x1, int y1, int x2, int y2) {
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]-(s[x2-1][y2-1]-s[x1][y2-1]-s[x2-1][y1]+s[x1][y1]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='X') a[i][j]=1;
            else a[i][j]=0;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    int ans=0;
    for(int u=1;u<=n;u++){
        for(int d=u+1;d<=n;d++){
            int l=m + 1; 
            for(int i=1;i<=m;i++){
                if(a[u][i]==1||a[d][i]==1){
                    l=m + 1;
                }else{
                    sum=get(u,i,d,i);
                    if(sum==0){
                        l=min(l,i);
                        ans=max((d-u+1)*(i-l+1),ans);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}