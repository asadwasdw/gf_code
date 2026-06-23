#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;
#define int long long
const int N=2e6+10;

int tr[N];

unordered_map<int,int>st;
typedef pair<int,int> PII;
vector<int>lsh;
map<PII,int>num;
PII a[N];
int cnt=0;

bool cmp(PII a,PII b)
{
   if(a.first!=b.first) return a.first<b.first;
   return a.second>b.second;
}

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int c)
{
    for(int i=x;i<=cnt;i+=lowbit(i))tr[i]+=c;
}

int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}



signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        lsh.push_back(a[i].first);
        lsh.push_back(a[i].first-1);
        lsh.push_back(a[i].first+1);
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i].second;
        lsh.push_back(a[i].second);
        lsh.push_back(a[i].second-1);
        lsh.push_back(a[i].second+1);
    }

 

    sort(lsh.begin(),lsh.end());

    for(int i=0;i<lsh.size();i++)
    {
        if(i==0)
        {
            st[lsh[i]]=++cnt;
        }
        else{
            if(lsh[i]!=lsh[i-1]){
                 st[lsh[i]]=++cnt;
            }
        }
        //cout<<lsh[i]<<endl;
    }
   // cout<<cnt<<endl;

    sort(a+1,a+n+1,cmp);
    int ans=0;


    //add(3,1);
    //for(int i=1;i<=8;i++)cout<<tr[i]<<" ";cout<<endl;

    int T=0;
    for(int i=1;i<=n;i++)
    {   
        int t=a[i].second;
        if(i>T){
         add(st[t],1);
         T++;
        }
        while(a[T+1].first==a[T].first){
            T++;
            add(st[a[T].second],1);
        }
        
       // cout<<t<<" ";
        ans+=sum(cnt)-sum(st[t-1]);
      
      //  cout<<sum(cnt)<<endl;
      //cout<<i<<" "<<T<<endl;
    }

    cout<<ans<<endl;





}