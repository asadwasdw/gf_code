#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];

void solve()
{
    int n,k;
    cin >> n >> k;

    if(k == 1) {
        for(int i = 1;i <=n;i++)cout<<i<<" ";cout << endl;
        cout << n << endl;
        for(int i = 1;i <=n;i++)cout<<i<<" ";cout << endl;
        return;
    }


    int ans = (n + (k - 1))/(k);
    int sum = k;
    {
        int l = 1, r = sum ;
        for(int i = 1; i <= ans ;i ++) {
            r = min(n,r);

            int L = l, R = r;
            int sum2 = (R - L + 1);
            if(sum2%2) {
                a[(L+R)>>1] = r; 
            }
            int L1 = l + sum2/2 - 1;
            int R1 = l + sum2/2 ;

            while(L < R) {
                a[L] = L1;
                a[R] = R1;
                L1--;
                R1++;
                L++;
                R--;
            }

            l += sum;
            r += sum;
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout <<"\n"<< ans << endl;

    {
        int l = 1, r = sum ;
        for(int i = 1; i <= ans ;i ++) {
            r = min(n,r);
            for(int j = r;j >=l; j --) cout << i <<" ";
            // cout << l << " " << r <<endl;
            l += sum;
            r += sum;
        }
    }
    
    cout << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}