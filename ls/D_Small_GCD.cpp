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

int pri[N];
bool st[N];
int phi[N];
int cnt;
void ss()
{
    int n = N - 1;
    phi[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            pri[cnt++]=i;
            phi[i]=i-1;
        }
        
        for(int j=0;pri[j]*i<=n;j++)
        {
            st[pri[j]*i]=true;
            
            if(i%pri[j]==0){
                
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
}

int a[N];

void solve()
{
    int n ; cin >> n;
    int mx = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    vector<int>num(mx+10,0);
    for(int i = 1;i <= n; i++) {

        for(int j = 1;j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                ans += phi[j] * num[j] * (n - i);
                num[j] ++ ;

                if(j * j != a[i]) {
                    ans += phi[a[i]/j] * num[a[i]/j] * (n - i);
                    num[a[i]/j] ++ ;
                }
            }
        }
    }

    cout << ans << endl;







}


signed main()
{  ss();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}