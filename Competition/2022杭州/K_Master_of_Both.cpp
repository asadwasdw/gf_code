// #pragma GCC optimize(3)
// #pragma GCC target("avx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC optimize(2)


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
// #define int long long
//vector<vector<int>>edg(N);


int idx=0;
int cnt[N][30];
int cnt2[N][30];
int son[N][30];
ll ans = 0;
int num[30][30];
unordered_map<string,int>gs;

inline void cr(string s)
{
    int p = 0;
    for(int i=0;i<s.size();i++) {
        int u = s[i]-'a';
        if(son[p][u]==0){
            son[p][u] = ++idx;
        }

        if(i==s.size()-1) {
            ans+=cnt[p][u];
            ans-=cnt2[p][u];
            cnt2[p][u]++;
        }
        
        cnt[p][u]++;

        for(int j=0;j<26;j++){
            if(u==j)continue;
            num[u][j]+=cnt[p][j];
        }
        p=son[p][u];
    }
}

unordered_map<int,int>id;
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        cr(s);
    }

    while(q--){
        string s;cin>>s;
        for(int i=0;i<26;i++) {
            id[s[i]-'a']=i;
        }

        ll res = 0;

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++){
                if(id[i]>id[j])continue;
                if(i==j)continue;
                res+=num[i][j];
            }
        }
        cout<<res+ans<<"\n";
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}