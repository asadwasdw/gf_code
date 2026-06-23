#include <bits/stdc++.h>
using namespace std;
int n,m,q,x,y,x2,y2;
long long a[1005][1005],s[1005][1005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
//            if(j==1){
//                s[i][j]=s[i-1][j]+a[i][j];
//                continue;
//            }
             s[i][j] = s[i - 1][j] + s[i][j-1] - s[i - 1][j - 1] +a[i][j];
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y>>x2>>y2;
        cout<<s[x2][y2]-s[x-1][y2]-s[x2][y-1]+s[x-1][y-1]<<endl;
    }
    return 0;
}