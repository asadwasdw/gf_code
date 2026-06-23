// #pragma GCC optimize("Ofast", "inline", "-ffast-math")
// #pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
// #define int long long
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int N = 1e6 + 50, LOGN = 30;
const ll mod = 1e9 + 7, inf = 1e9;

typedef pair<int,int> PII;

map<PII,bool>st;
map<PII,int>sg;

int p = 0;

int js(int l,int r)
{
	if(st[{l,r}])return sg[{l,r}];
	st[{l,r}] = true;


	if(l > r){
		sg[{l,r}] = 0; 
		return 0;
	}

	set<int>s;

	for(int i = l;i<= r;i++)
	{
		if(i*p<r)continue;
		s.insert(js(l,i - 1));
	}

	int t = 0;
	while(s.count(t))t++;
	sg[{l,r}] = t;
	return t;
}

int js2(int l,int r)
{
    if(l*p>=r)return max(0, r - l  + 1); 
    int sum = (r - p*l); 

    int t = sum / p;
    int t2 = sum % p;

   
    if(t2 == 0)t2 = p,t--;
    cout<<sum<<" "<<t<<" "<<t2<<endl;

    if(t2 == 1){
        if(t == 0)return 0;
        else return js2(l,t2);
    }
    else return l * (p - 1) + t2+ 1 + t*(p-1); 

}

inline long long getx(long long L, long long R, long long P) {
    if (R <= P * L) return R - L + 1;
    long long g = (R - (P * L + 1)) / P, pos = R - ((P * L + 1) + g * P);
    if (pos == 0) return getx(L,L+g-1,P);
    return L * (P - 1) + 1 + pos + g * (P - 1);
}


void solve(){

	int n;cin>>n;
    p=2;
    for(int i =1;i<=n;i++)cout<<i<<" ";cout<<endl;
    for(int i = 1;i<=n;i++)
    {
    	for(int j = 1;j<=n;j++){
    		cout<<js(i,j)<<" ";
    	}
    	cout<<endl;
    }

    cout<<endl;


    cout<<js2(1,6)<<endl;;
    // for(int i = 1;i<=n;i++)
    // {
    // 	for(int j = 1;j<=n;j++){
    	
    // 		cout<<js2(i,j)<<" ";
    // 	}
    // 	cout<<endl;
    // }
}

signed main(){

    int t = 1;
  //  cin >> t;
    while(t--)solve();
    return 0;
}
