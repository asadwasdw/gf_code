#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>

using namespace std;
typedef pair<long double,long double> PII;
const int N=4e5+10;

vector<PII> a;


bool cmp(PII a,PII b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}


int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
       long double x,y;
        cin>>x>>y;
        a.push_back({atan2(y-1,x),atan2(y,x-1)});
    }

    sort(a.begin(),a.end(),cmp);
    long double last=-1;
    long long res=0;
    for(auto t:a)
    {
        if(t.first>=last){
            res++;
            last=t.second;
            continue;
        }

        if(t.second<last){
            last=t.second;
        }

    }

    cout<<res<<endl;


}

