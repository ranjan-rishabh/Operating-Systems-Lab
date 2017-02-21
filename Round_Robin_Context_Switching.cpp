#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;

double att=0,awt=0,ctw;
ll co=0;
bool lp=0;
vector <pair<string,pair<double,double> > > v;
struct process
{
    string id;
    int ar;
    int ct;
    int cct;
    double wt;
    double tt;
    process()
    {
        wt=0;
        tt=0;
    }
    process *n;
}*h=NULL,*hq=NULL;
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
process *cpy(process *p)
{
    process *p1=new process;
    p1->id=p->id;
    p1->ar=p->ar;
    p1->ct=p->ct;
    p1->cct=p->cct;
    p1->n=NULL;
    return p1;
}
void clq(process *p,process *pt)
{
    if(hq==NULL)
    {
        hq=cpy(pt);
        hq->n=hq;
        return;
    }
    process *cu=hq;
    if(cu->n==NULL||cu->n==cu)
    {
        process *p1=cpy(pt);
        cu->n=p1;
        p1->n=p;
    }
    else
    {
        while(cu->n!=p)
        {
            cu=cu->n;
        }
        process *p1=cpy(pt);
        cu->n=p1;
        p1->n=p;
    }

}
void del(process *p)
{
    process *cu=h;
    if(cu==p)
    {
        h=h->n;
        delete p;
        return;
    }
    while(cu->n!=p)
    {
        cu=cu->n;
    }
    cu->n=p->n;
    delete p;
}
void delc(process *p)
{
    process *cu=hq;
    if(p==hq)
    {
        if(hq->n==hq)
        {
            hq=NULL;
            lp=1;
        }
        else
            hq=hq->n;
    }
    if(hq==NULL)
        return;
    while(cu->n!=p)
    {
        cu=cu->n;
    }
    cu->n=p->n;
    lp=1;
}
void shcn(process *p,double t)
{
    cout<<"Process ID:"<<p->id<<'\n';
    cout<<"Process Arrival:"<<p->ar<<'\n';
    if(p->ct<=0)
    {
        p->wt=t-p->ar-p->cct-ctw;
        p->tt=t-p->ar-ctw;
        v.push_back(make_pair(p->id,make_pair(p->wt,p->tt)));
        att+=p->tt;
        awt+=p->wt;
        co++;
        delc(p);
    }
}
main()
{
    cout<<"Enter Number Of Processes:";
    ll c,i=1;
    cin>>c;
    ll ts;
    cout<<"Enter Time Slice:";
    cin>>ts;
    cout<<"Enter Context Switching Time:";
    cin>>ctw;
    process *cu;
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
    process *te=h;
    double t=0;
    bool z=0;
    process * px;
    while(co<c)
    {
        te=h;
        lp=0;
        cout<<"At Time:"<<t<<'\n';
        while(te!=NULL)
        {
            if(te->ar<=t)
            {
                if(hq==NULL)
                {
                    clq(NULL,te);
                    cu=hq;
                }
                else
                {
                    clq(cu,te);
                }
                del(te);
            }
            te=te->n;
        }
        if(z==0)
        {
            px=cu;
            z=1;
        }
        else
        {
            px=cu->n;
        }
        if(px->ct<ts)
        {
            t+=px->ct;
            px->ct-=ts;
        }
        else
        {
            px->ct-=ts;
            t+=ts;
        }
        t+=ctw;
        shcn(px,t);
        if(lp==0)
            cu=px;
        else
        {
            z=0;
            cu=px->n;
        }
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
