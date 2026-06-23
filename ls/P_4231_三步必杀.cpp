#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,l,r,e,s;
ll a[N],b[N],c[N];
ll maxn=-INF,ans;
int main(){
        scanf("%d%d",&n,&m); 
        for(int i=1;i<=m;i++){
                scanf("%d%d%d%d",&l,&r,&s,&e);
                int d=(e-s)/(r-l);
                c[l]+=s;
                c[l+1]-=s-d;
                c[r+1]-=d+e;
                c[r+2]+=e;
        }
        for(int i=1;i<=n;i++){
                b[i]=b[i-1]+c[i];
        }
        for(int i=1;i<=n;i++){
                a[i]=a[i-1]+b[i];
                maxn=max(a[i],maxn);
                ans^=a[i];
        }
        printf("%lld %lld",ans,maxn);
        return 0;
}