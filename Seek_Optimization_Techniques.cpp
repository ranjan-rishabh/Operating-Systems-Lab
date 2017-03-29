#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector <pair<pair<ll,ll>,pair<ll,ll> > > in;
double lt[1000];
ll c;bool v[1000];
double calc(ll tr,ll sec,ll ptr,ll psec)
{
    double an=0;
    if(ptr>tr)
        an+=10+0.1*(ptr-tr);
    else
        an+=10+0.1*(tr-ptr);
    if(sec-psec<0)
        an+=sec-psec+8;
    else
        an+=sec-psec;
    return an+1;
}
double fcfs()
{
    ll ptr=100,psec=0;
    double ti=0;
    for(int i=0;i<c;i++)
    {
        lt[in[i].first.second]=calc(in[i].second.first,in[i].second.second,ptr,psec)-1;
        ptr=in[i].second.first;
        psec=in[i].second.second;
        ti+=lt[in[i].first.second]+1;
        if(ti<in[i+1].first.first&&i<c-1)
            ti=in[i+1].first.first;
    }
    return ti;
}
double sstf()
{
    double ti=in[0].first.second;
    ll ptr=100,psec=0;
    lt[in[0].first.second]=calc(in[0].second.first,in[0].second.second,ptr,psec)-1;
    ptr=in[0].second.first;
    psec=in[0].second.second;
    ti+=lt[in[0].first.second];
    v[in[0].first.second]=1;
    for(int i=1;i<c;i++)
    {
        bool po=0;
        double temp=1000000000;
        ll p=0;
        for(ll j=0;j<c;j++)
        {
            if(v[in[j].first.second]==0&&ti>=in[j].first.first)
            {
                po=1;
                if(temp>calc(in[j].second.first,in[j].second.second,ptr,psec));
                {
                    temp=calc(in[j].second.first,in[j].second.second,ptr,psec);
                    p=j;
                }
            }
        }
        if(po==1)
        {
            lt[in[p].first.second]=temp-1;
            ti+=temp;
            v[in[p].first.second]=1;
            ptr=in[p].second.first;
            psec=in[p].second.second;
        }
        else
        {
            ti=in[i].first.first;
            i--;
        }
    }
    return ti;
}
main()
{
    cout<<"Enter Number Of Requests:";
    cin>>c;
    cout<<"Enter Arrival Time, Track No, Sector No Of All Requests:\n";
    for(int i=0;i<c;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        in.push_back(make_pair(make_pair(x,i+1),make_pair(y,z)));
    }
    int po;
    double et;
    cout<<"1)FCFS\n2)SSTF\nEnter Choice:";
    cin>>po;
    if(po==1)
        et=fcfs();
    else
        et=sstf();
    double avg=0;
    for(int i=1;i<=c;i++)
    {
        cout<<i<<'\t'<<lt[i]<<'\n';
        avg+=lt[i];
    }
    cout<<"End Time:"<<et<<'\n';
    cout<<"Average Latency Time:"<<(double)(avg/c)<<'\n';
    cout<<"Average Time:"<<(double)(et/c);
}
