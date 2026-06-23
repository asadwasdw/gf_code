#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int f[N],num[N];
int find(int x){
    if(x!=f[x])return f[x] = find(f[x]);
    return f[x];
}

ll A[N],B[N];
vector<ll>lsh;

int fd(int x){
    return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin();
}

void solve()
{
    int n;cin>>n;
    for(int i=0;i<=2*n+1;i++){
        f[i]=i;
        num[i]=1;
    }
    lsh.clear();
    lsh.push_back(-1);
    lsh.push_back(INFll);

    for(int i=1;i<=n;i++) {
        ll a,b;
        cin>>a>>b;

        lsh.push_back(a);
        lsh.push_back(b);

        A[i]=a;
        B[i]=b;
    }

    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    for(int i=1;i<=n;i++){

        int a = fd(A[i]);
        int b = fd(B[i]);
        // cout<<a<<" "<<b<<endl;

        if(find(a)==find(b))continue;
        num[find(b)]+=num[find(a)];
        f[find(a)]=find(b);

    }

    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans,num[find(i)]);
    }
    cout<<ans<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}