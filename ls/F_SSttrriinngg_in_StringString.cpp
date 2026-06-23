#include<bits/stdc++.h>
#define __int128 long long
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n;
string s,t;
__int128 ns,nt;
__int128 a[26][N];

void init(){
    for(int i=1;i<=ns;i++){
        for(int j=0;j<26;j++){
            a[j][i] = a[j][i-1];
        }
        a[s[i]-'a'][i]++;
    }
}


bool check(int k) {
    __int128 ans = 0;
    __int128 j = 1;
    for(int i=1;i<=nt && ans  <= n + 1; i++){
       
        int T = t[i]-'a';
         if(a[T][ns] == 0) return false; 
        __int128 num = k;
        num += a[T][j - 1];
        int t2 = (num/a[T][ns]);
       
        num %= a[T][ns];

        
        if(num == 0) {
            j = (lower_bound(a[T]+1,a[T]+ns+1,a[T][ns]) - a[T]) + 1;
            t2 --;
        }
        else {
            j = (lower_bound(a[T]+1,a[T]+ns+1,num) - a[T]) + 1;
        }

        if(j == ns + 1){
            j = 1;
            ans ++;
        }
        if(t2>0)ans += t2;
        // cout << j << " " << num <<" "<<ans << endl;
    }
    
    if(j==1)ans--,j=nt;
    // cout << j << " " << ans << endl;
    return ans < n;
}

void solve()
{
    cin >> n >> s >> t;
    ns = s.size();nt=t.size();
    s = " " + s; t = " " + t;

    init();
    check(3);

    int l = 0, r =INFll;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}