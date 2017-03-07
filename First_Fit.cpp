#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;
ll co=0,ifr=0,efr=0,ti=0;bool mj[100];
vector <ll> m;
vector < pair<ll,ll> > jo;
ll d[100],wt[100],ma[100];
bool cor[100];
void mem_alloc(ll s,ll c)
{
    ll t,i=1,j;
    for(t=0;t<s&&i<=c;)
    {
        if(d[i]==0)
        for(j=1;j<=s;j++)
        {
            if(mj[j]!=1)
            if(jo[i].second<=m[j])
            {
                d[i]=j;
                ma[i]=ti;
                mj[j]=1;
                ifr+=m[j]-jo[i].second;
                t++;
                if(efr>0)
                {
                    efr-=m[j];
                }
                break;
            }
        }
        i++;
    }
}
ll proc_d(ll c)
{
    ll i;
    for(ll k=1;k<=c;k++)
    {
        if(cor[k]!=1)
        if(d[k]!=0)
        {
            //cout<<"no\n";
            ti+=jo[k].first;
            wt[k]=ti-ma[k]-jo[k].first;
            mj[d[k]]=0;
            cor[k]=1;
            ifr-=(m[d[k]]-jo[k].second);
            if(ifr<0)
                ifr=0;
            co++;
            i=k;
            break;
        }
    }
    return i;
}
main()
{
    memset(d,0,100);
    memset(wt,-1,100);
    m.push_back(0);
    cout<<"Enter Number Of Memory Bocks:";
    ll s,i=0,maxi=0;
    cin>>s;
    cout<<"Enter Size Of Memory Blocks Serial Wise:\n";
    while(i<s)
    {
        ll x;
        cin>>x;
        maxi=max(x,maxi);
        m.push_back(x);
        i++;
    }
    cout<<"Enter Number Of Jobs:";
    ll c,j,t=0;i=0;
    jo.push_back(make_pair(0,0));
    cin>>c;
    cout<<"Enter Time And Size Of Jobs Serial Wise:\n";
    while(i<c)
    {
        ll x,f;
        cin>>x>>f;
        if(f>maxi)
        {
            cor[i+1]=1;co++;
        }
        jo.push_back(make_pair(x,f));
        i++;
    }
    while(co<c)
    {
        i=1;
        mem_alloc(s,c);
        for(ll k=1;k<=s;k++)
        {
            if(!mj[k])
            {
                efr+=(m[k]);
            }
        }
        cout<<"Internal Fragmentation:"<<ifr<<'\n';
        cout<<"External Fragmentation:"<<efr<<'\n';
        i=proc_d(c);
        cout<<"Process Completed:"<<i<<"\tTime:"<<ti<<'\n';
        cout<<"Waiting Time:"<<wt[i]<<'\n';
        getch();
        cout<<'\n';
    }
    cout<<"Throughput:"<<(double)c/ti<<'\n';
}
