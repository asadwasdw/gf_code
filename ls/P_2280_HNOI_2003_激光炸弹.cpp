#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,m,x,y,v;
int a[N][N],s[N][N],ans=0; 
int main(){
        int x2=0,y2=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
                cin>>x>>y>>v;
                x++,y++;
                a[x][y]+=v;
                x2=max(x2,x);
                y2=max(y2,y);
        }
        x2 = 5001, y2 = 5001;
        for(int i=1;i<=x2;i++){
                for(int j=1;j<=y2;j++){
                        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
                }
        }
        // for(int i = 1; i <= 2; i ++) {
        //     for(int j = 1; j <= 2; j ++) {
        //         // cout << s[i][j] << " \n"[j == 2];
        //     }
        // }
        for(int i=1;i<=x2;i++){
                for(int j=1;j<=y2;j++){
                        if(i+m-1>x2 || j+m-1>y2) continue;
                        else ans=max(ans,s[i+m-1][j+m-1]+s[i-1][j-1]-s[i-1][j+m-1]-s[i+m-1][j-1]);
                }
        }
        cout<<ans;
        return 0;
}