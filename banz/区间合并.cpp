#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1e5+10; 

struct q{

	int l,r,w;

}qj[N];


bool cmp(q a, q b)
{
	if(a.w!=b.w)return a.w<b.w;
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}

typedef pair<int,int>PII;

vector<PII>v;// 合并后的区间
int a[N];


int main()
{

    //所有区间都是闭区间
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=m;i++)cin>>qj[i].l>>qj[i].r>>qj[i].w;//区间左端点，右端点，种类

	sort(qj+1,qj+m+1,cmp);

	for(int i=1;i<m;i++)
	{
		if(qj[i].w!=qj[i+1].w){//这里划分了区间的种类，相同的区间才能合并
			v.push_back({qj[i].l,qj[i].r});
		}

		else if(qj[i].r<qj[i+1].l)
		{
			v.push_back({qj[i].l,qj[i].r});
		}
		else 
		{
			qj[i+1].l=qj[i].l;
			qj[i+1].r=max(qj[i+1].r,qj[i].r);
		}
	}

	v.push_back({qj[m].l,qj[m].r});




}