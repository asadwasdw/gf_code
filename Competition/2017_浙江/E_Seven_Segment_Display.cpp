#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int w[20]={6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4,78};

int qmi(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int js(int x , int len)
{
    if(len <= -1)return 0;
    int ans = 0;
    int qmi16 = qmi(16, len);
    int t = x / qmi16;
    int T = x % qmi16;

    ans += w[t] * (T + 1);

    for(int j = t - 1; j >= 0; j--){
        ans += w[j] * qmi16 + (w[16] * qmi16 * (len) / 16);
    }
    //cout<< t << " " << x <<" "<< len << " " <<ans << endl;
    ans +=  js(T , len - 1);
    return ans;
}


void solve()
{
    int maxn = qmi(16,8) - 1;

    int n,s;
   scanf("%lld %llX",&n,&s);
    int e  = s + n - 1;
  //  cout<<maxn<<endl;
    if(e>maxn){
        e=e-(maxn+1);
       printf("%lld\n",js(e,7)-js(s-1,7)+js(maxn,7));
    }
    else {
       cout<<js(e,7) - js(s-1,7)<<endl;
    }

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}