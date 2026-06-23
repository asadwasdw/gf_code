#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<set>
#include<array>
#include<random>
#include<bitset>
#include<ctime>
#include<limits.h>
#include<assert.h>
#include<unordered_set>
#include<unordered_map>
#define RI register int
#define CI const int&
#define mp make_pair
#define fi first
#define se second
#define Tp template <typename T>
using namespace std;
typedef long long LL;
typedef long double LDB;
typedef unsigned long long u64;
typedef __int128 i128;
typedef pair <int,int> pi;
typedef vector <int> VI;
typedef array <int,3> tri;
const int N=55;
int t,n,c1[N],s1[N],s2[N],sp[N],c1_[N],s1_[N],s2_[N],used[N],ans[N],c[N][N],c_[N][N];
int main()
{
	//freopen("CODE.in","r",stdin); freopen("CODE.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	for (cin>>t;t;--t)
	{
		RI i,j,k; for (cin>>n,i=0;i<n;++i) c1[i]=s1[i]=s2[i]=sp[i]=0;
		for (i=0;i<n;++i) c1_[i]=s1_[i]=s2_[i]=used[i]=0;
		for (i=0;i<n;++i) for (j=0;j<n;++j) c[i][j]=c_[i][j]=0;
		for (i=0;i<n;++i) for (j=0;j<n;++j)
		{
			int x=i*j; if (x<n) { ++c1[x]; continue; }
			++s1[x/n]; ++s2[x%n]; ++c[x/n][x%n];
		}
		vector <int> err; static int id[10];
		for (i=0;i<n;++i) for (j=i+1;j<n;++j)
		if (c1[i]==c1[j]&&s1[i]==s1[j]&&s2[i]==s2[j])
		err.push_back(i),err.push_back(j),sp[i]=sp[j]=1;
		auto trs=[&](const char& ch)
		{
			if ('a'<=ch&&ch<='z') return ch-'a';
			return ch-'A'+26;
		};
		for (i=0;i<n*n;++i)
		{
			string s; cin>>s;
			if (s.size()==1) { ++c1_[trs(s[0])]; continue; }
			++s1_[trs(s[0])]; ++s2_[trs(s[1])]; ++c_[trs(s[0])][trs(s[1])];
		}
		for (i=0;i<n;++i) if (!sp[i])
		for (j=0;j<n;++j) if (c1[i]==c1_[j]&&s1[i]==s1_[j]&&s2[i]==s2_[j]) ans[i]=j,used[j]=1;
		vector <int> wl; for (i=0;i<n;++i) if (!used[i]) wl.push_back(i);
		for (i=0;i<err.size();++i) id[i]=i;
		//assert(err.size()==0||err.size()==2||err.size()==4);
		//assert(wl.size()==0||wl.size()==2||wl.size()==4);
		do
		{
			for (i=0;i<err.size();++i) ans[err[i]]=wl[id[i]];
			bool flag=1; for (i=0;i<n&&flag;++i) if (c1[i]!=c1_[ans[i]]) flag=0;
			for (i=0;i<n&&flag;++i) for (j=0;j<n&&flag;++j)
			if (c[i][j]!=c_[ans[i]][ans[j]]) flag=0;
			if (flag) break;
		} while (next_permutation(id,id+err.size()));
		for (i=0;i<n;++i) cout<<char(ans[i]<26?ans[i]+'a':ans[i]-26+'A'); cout<<endl;
	}
	return 0;
}
