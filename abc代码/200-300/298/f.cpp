#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N=2e5+10;

unordered_map<int,int>lsha;
unordered_map<int,int>lshb;
int cnta,cntb;

PII suma[N],sumb[N];



PII d[N];

unordered_map<ll,ll>st;

ll ans;




bool cmp(PII a,PII b)
{
    return a.first>b.first;
}



int main()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);

        if(!lsha[a]) lsha[a]=++cnta;
        a=lsha[a];
        
        if(!lshb[b]) lshb[b]=++cntb;
        b=lshb[b];

        st[a*N+b]=c;

        suma[a].first+=c;
        sumb[b].first+=c;

        suma[a].second=a;
        sumb[b].second=b;

        d[i]={a,b};

    }



    for(int i=1;i<=n;i++)
    {
        ans=max(ans,suma[d[i].first].first+sumb[d[i].second].first-st[d[i].first*N+d[i].second]);
        // cout<<d[i].first<<" "<<d[i].second<<" "<<ans<<endl;
    }

    sort(suma+1,suma+cnta+1,cmp);
    sort(sumb+1,sumb+cntb+1,cmp);



    // 	for(int i = 1; i <= cnta; i ++ ) {         // 枚举不重复的每一行 
	// 	for(int j = 1; j <= cntb; j ++ ) {     // 枚举排序之后的列，当然也是不重复的 
	// 		if(st[suma[i].second*N+sumb[j].second]==0) {            // 此时枚举到的 (r, c) 不存在，且是按照 v1 大小排序的，所以对于 r 来说已经最优了，退出 
	// 			ans=max(ans,suma[i].first+sumb[j].first);
	// 			break;
	// 		}
	// 	}
	// }

    

    for(int i=1;i<=cnta;i++)
    {
        int j=1;
        while(j<=cntb&&st[suma[i].second*N+sumb[j].second])
        {
            j++;
        }
        ans=max(ans,suma[i].first+sumb[j].first);
    }

    cout<<ans<<endl;


    return 0;
}