    #include<iostream>
    #include<algorithm>
    using namespace std;

    const int N=2e5+10;
    long long a[N],s[N];

    void solve()
    {
        int n;cin>>n;

        long long ans=0;
        bool y0=false;
        bool ky=true;


        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            ans+=x;
            a[i]=x;
            s[i]=a[i]+s[i-1];



            if(s[i]==0){
                if(!y0){
                    y0=true;
                }
            }else{
                if(y0)ky=false;
            }
            if(s[i]<0)ky=false;

        // cout<<s[i]<<" ";
        }
        //cout<<endl;
        if(ans)ky=false;

        if(ky)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


    }


    int main()
    {
        int t;cin>>t;while(t--)
        solve();
    }
