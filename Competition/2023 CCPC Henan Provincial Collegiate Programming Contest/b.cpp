#include <iostream>
using namespace std;
#define endl '\n'
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define _mp(a, b) make_pair(a, b)
#define _lowbit(x) ((x) & -(x))
typedef long long ll;
typedef pair<int, int> pii;
inline void read(int &x) {scanf("%d", &x);}
inline void read(int &x, int &y) {scanf("%d%d", &x, &y);}
inline void read(int &x, int &y, int &z) {scanf("%d%d%d", &x, &y, &z);}
inline void read(int &x, int &y, int &z, int &w) {scanf("%d%d%d%d", &x, &y, &z, &w);}
const string SX = "  XXX  ", SY = "  YYY  ", FG = "    00----------00\n";
const int N = 1000009, M = 1000009, mod = 998244353;

int f1[N][25],f0[N][25];
int a[N];
int n;
int logg[N];

void init()
{
	
	for(int i=2;i<=n;i++)logg[i]= logg[i /2]+1  ;
	for(int i=1;i<=n;i++)f1[i][0]=a[i],f0[i][0]=a[i];
	int t=logg[n]+1;
	
	for(int j=1;j<t;j++)
	{
		int IM = n-(1<<j)+1;
		for(int i=1;i<=IM;i++)
		{
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f0[i][j]=min(f0[i][j-1],f0[i+(1<<(j-1))][j-1]);
		}
	}
}

bool vis[N];



void solved() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	init();
	int ans=1;
	for(int k=1;k<=n-1;k++)
	{
        if(vis[k])
        {
            ans++;
            continue;

        }
		bool f=true;
		for(int l=k+1;l<=n;l+=k)
		{
			int r=min(n,l+k-1);
			int kt=logg[r-l+1];
			int fkt=logg[l-1];
			// if(query(1,l-1,1)>query(l,r,0))
			if(a[1] == a[n] && a[1] == 0) continue;
			if(max(f1[1][fkt],f1[l-(1<<fkt)][fkt]) > min(f0[l][kt],f0[r-(1<<kt)+1][kt]))
			{
					f=false;
					break;
			}
		}
		if(f)
		{
			ans++;

            for(int z=k;z<=n;z+=k)
            {
                vis[z]=true;
            }
		}
	}
	printf("%d\n",ans);
}
int main() {
	// int ttx;  read(ttx);  while(ttx --)
	solved();
	return 0;
}