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

int e[N], l[N], r[N], idx;

void  init() {
	l[1] = 0;
	r[0] = 1;
    l[0]=0;
    r[1]=1;
    e[0]=0;
    e[1]=1e18+1;
	idx = 2;
}
void add(int k,int x){//在K后面插入一个数
	e[idx] = x;
	r[idx] = r[k];
	l[r[k]] = idx;
	l[idx] = k;
	r[k] = idx;
	idx++;
}

set<int>s;
unordered_map<int,int>L,R;

void solve()
{
    init();
    s.insert(0);
    L[0]=0;
    R[0]=0;
    R[(int)(1e18+1)]=1;
    L[(int)(1e18+1)]=1;
    s.insert(1e18+1);
    int m;
    cin>>m;
    while(m--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int x;cin>>x;
            auto t =*(prev(s.upper_bound(x)));
            if(t==x){
                add(R[x],x);
                R[x]=idx-1;
            }
            else 
            {
                add(R[t],x);
                L[x]=R[x]=idx-1;
            }

            s.insert(x);
        }
        else if(op==2)
        {
            int x,k;
            cin>>x>>k;
            auto t =*(prev(s.upper_bound(x)));
            //cout<<t<<endl;
            
            int wz = R[t];
            //cout<<wz<<endl;
            k--;
            while(k--)
            {
                wz=l[wz];
            }
            if(wz<=1)cout<<"-1";
            else cout<<e[wz];
            cout<<endl;
        }
        else 
        {
            int x,k;
            cin>>x>>k;
            auto t =*(s.lower_bound(x));
            int wz = L[t];
            k--;
            while(k--)
            {
                wz=r[wz];
            }
            if(wz<=1)cout<<"-1";
            else cout<<e[wz];
            cout<<endl;
        }
    }

    // cout<<e[2]<<" "<<e[3]<<" "<<e[4]<<" "<<e[5]<<endl;
    // cout<<L[10]<<" "<<R[10]<<endl;
    // cout<<L[20]<<" "<<R[20]<<endl;
    // cout<<L[30]<<" "<<R[30]<<endl;
    
    // cout<<r[2]<<endl;
    // cout<<r[3]<<endl;
    // cout<<r[4]<<endl;
    // cout<<r[5]<<endl;

    // while(t!=1)
    // {
    //     cout<<e[t]<<" "<<r[t];
    //     t=r[t];
    // }





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