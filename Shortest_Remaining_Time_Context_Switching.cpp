#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;

double att=0,awt=0,ctw;
ll co=0;
vector <pair<string,pair<double,double> > > v;
struct process
{
    string id;
    int ar;
    int ct;
    int cct;
    process *n;
}*h=NULL;
process *crn()
{
    process *p=new process;
    cout<<"Enter Process ID:";
    cin>>p->id;
    cout<<"Enter Arrival Time:";
    cin>>p->ar;
    cout<<"Enter CPU Time:";
    cin>>p->ct;
    p->cct=p->ct;
    p->n=NULL;
    return p;
}
void shcn(double t, process *cu)
{
    cout<<"Process ID:"<<cu->id<<'\n';
    cout<<"Process Arrival:"<<cu->ar<<'\n';
    cout<<"Process CPU Time:"<<cu->ct<<'\n';
}
void del(process *p,double t)
{
    co++;
    awt+=t-p->ar-p->cct-ctw;
    att+=t-p->ar-ctw;
    v.push_back(make_pair(p->id,make_pair((double)(t-p->ar-p->cct-ctw),(double)(t-p->ar-ctw))));
    if(p==h)
    {
        h=h->n;
    }
    else
    {
        process *cu=h;
        while(cu->n!=p)
            cu=cu->n;
        cu->n=p->n;
    }
}
main()
{
    cout<<"Enter Number Of Processes:";
    ll c,i=1;
    cin>>c;
    cout<<"Enter Context Switching:";
    cin>>ctw;
    process *cu;
    bool q=0;
    while(i<=c)
    {
        if(h==NULL)
        {
            h=crn();
            cu=h;
        }
        else
        {
            cu->n=crn();
            cu=cu->n;
        }
        i++;
    }
    process *te=h,*px=NULL;
    bool qp=0;
    ll lt=LLONG_MAX;
    double t=0;
    while(co<c)
    {
        te=h;
        lt=LLONG_MAX;
        cout<<"At Time:"<<t<<'\n';
        cout<<"Ready Queue:";
        while(te!=NULL)
        {
            if(te->ar<=t)
            {
                cout<<te->id<<" ";
                if(lt>te->ct)
                {
                    lt=te->ct;
                    cu=te;
                }
            }
            te=te->n;
        }
        cout<<'\n';
        t=t+1;
        if(px!=cu&&qp==1)
        {
            t+=ctw;
        }
        cu->ct--;
        shcn(t,cu);
        cout<<'\n';
        if(cu->ct<=0)
        {
            del(cu,t);
        }
        px=cu;
        qp=1;
        getch();
    }
    cout<<"Tasks Completed At:"<<t<<'\n';
    cout<<"Individual Waiting and Turnaround Times:\n";
    for(i=0;i<v.size();i++)
    {
        cout<<v[i].first<<'\t'<<v[i].second.first<<'\t'<<v[i].second.second<<'\n';
    }
    cout<<"Average Turnaround Time:"<<att/c<<'\n';
    cout<<"Average Waiting Time:"<<awt/c<<'\n';
}
