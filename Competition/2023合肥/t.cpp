#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    // freopen("data.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d",&n);
    int ans=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        if (x>=60) ans++;
    }
    printf("%d",ans);
}         