#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
int n,m,k;
typedef long long ll;
const long long mod =998244353;
bool st[5010][5010];
long long f[5010][5010];
const int N=15010;
int h[N],e[N],ne[N],idx;

void add(int a,int b){
	ne[idx] = h[a],e[idx] = b,h[a] = idx++;
}

int main()
{
   
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }


    f[0][1]=1;

 f[0][1] = 1;
	for(int i = 1;i <= k;i++){
		ll sum = 0;
		for(int j = 1;j <= n;j++) sum += f[i - 1][j];
		for(int j = 1;j <= n;j++){
			f[i][j] = sum - f[i - 1][j];
			for(int p = h[j];~p;p = ne[p]) f[i][j] -= f[i - 1][e[p]];
			f[i][j] %= mod;
		} 
	}


    cout<<f[k][1]<<endl;




    
   return 0;

}