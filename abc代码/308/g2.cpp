#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

multiset<int>m,ans;

void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        int x;
       // cout<<n<<" "<<op<<endl;
        if(op==1)
        {
            cin>>x;
            auto t1 =m.upper_bound(x);
            int a=-1,b=-1;
            if(t1!=m.end()){
                ans.insert((*t1)^x);
                a=*t1;
            }

            if(t1!=m.begin()){
                t1--;
                ans.insert((*t1)^x);
                b=(*t1);
            }

            if(a>-1&&b>-1){
                t1=ans.find(a^b);
                ans.erase(t1);
            }
            m.insert(x);
        }
        else if(op==2){
            cin>>x;
            auto t1 = m.upper_bound(x);
            int a=-1,b=-1;

            if(t1!=m.end())
            {
                ans.erase(ans.find(x ^ (*t1)));
                a=(*t1);
            }
            t1--;
            if(t1!=m.begin())
            {
                t1--;
                ans.erase(ans.find(x ^ (*t1)));b=(*t1);
            }

            if(a>-1&&b>-1)ans.insert(a^b);
            m.erase(m.find(x));

            // auto t1 = m.upper_bound(x);
			// if(t1 != m.end()) ans.erase(ans.find(x ^ (*t1))), a = *t1;
			// t1 --;  if(t1 != m.begin()) {
			// 	t1 --;  ans.erase(ans.find(x ^ (*t1)));  b = *t1;
			// }
			// if(a > -1 && b > -1) ans.insert(a ^ b);
			// m.erase(m.find(x));
        }
        else 
        {
          cout<<*ans.begin()<<endl;
        }

    }
    //cout<<"S"<<endl;
    

}


signed main()
{
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}



        // int op,x;
        // cin>>op;
        // if(op==1)
        // {
        //     cin>>x;
        //     m.insert(x);
        // }
        // else if(op==2)
        // {
        //     cin>>x;
        //     m.erase(m.find(x));
        // }
        // else {
        //     int t=*m.begin();
        //     m.erase(m.begin());
        //     cout<<(t^*m.begin())<<endl;
        //     cout<<t<<" "<<*m.begin()<<endl;
        //     m.insert(t);
        // }