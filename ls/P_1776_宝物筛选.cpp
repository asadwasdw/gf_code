#include<bits/stdc++.h>
using namespace std;
int n,W,ans,cnt=0; // 从0开始， 先++就变成了1
int dp[1000005];
int w[1000005],v[1000005];
int main(){
    int vi,wi,m;
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&vi,&wi,&m);
        for(int j=1;j<=m;j<<=1){
            ++cnt; // 加一次就够了
            v[cnt]=j*vi,w[cnt]=j*wi;

            m-=j;
        }
        if(m) v[++cnt]=vi*m,w[cnt]=wi*m; // 这里只加一次的对的， 所以上面为什么加了两次
    }


    for(int i=1;i<=cnt;i++){
                for(int j=W;j>=w[i];j--){ // 最大载重是W, 不是m, 你的变量定义不一样
                        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
                }
        }
    printf("%d",dp[W]); // 同上
    return 0;
}