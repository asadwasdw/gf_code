#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#define int long long
using namespace std;

const int N = 2e5+10;

int a[N];
vector<int>lshsz;
typedef pair<int,int>PII;
PII xw[N];
unordered_map<int,int>st;
int cnt=-1;

void lsh()
{
    sort(lshsz.begin(),lshsz.end());


    for(int i=0;i<lshsz.size();i++)
    {
        if(i==0||lshsz[i-1]!=lshsz[i]){
            cnt++;
            st[lshsz[i]]=cnt;
        }
    }

}

int tr[4*N];

void add(int u,int x)
{
  //  cout<<u<<" "<<x<<endl;
    for(int i=u;i<4*N;i+= i&-i )tr[i]+=x;
}

int query(int u)
{
    if(u==0)return 0;
    int res=0;
    for(int i=u;i;i-= i&-i)res+=tr[i];
    return res;
}


signed main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        lshsz.push_back(a[i]);
    }

    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        lshsz.push_back(a);
        lshsz.push_back(b);
        xw[i]={a,b};
    }

    lsh();
    int i=0,j=0;
    int last=0;
    for(;j<lshsz.size();j++){
        if(j!=0&&lshsz[j]==lshsz[j-1])continue;

        if(i%2)
        {
          //  cout<<i<<" " <<last<<" "<<lshsz[j]<<endl;
            add(st[lshsz[j]],lshsz[j]-last);
            last=lshsz[j];
           
        }

        if(lshsz[j]==a[i+1])
        {
            i++;
            last=a[i];
        }
    }
   // cout<<st[240]<<endl;
    //cout<<tr[0]<<endl;

   // for(int i=1;i<=5;i++)cout<<query(i)<<" ";cout<<endl;

   //for(auto t:lshsz)cout<<t<<" ";cout<<endl; 
    

    for(int i=1;i<=q;i++)
    {
       // cout<<xw[i].second<<" "<<xw[i].first<<endl;
        cout<<query(st[xw[i].second])-query(st[xw[i].first])<<endl;
    }




}