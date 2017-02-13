#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;

double att=0,awt=0;
ll co=0;
bool lp=0;
vector <pair<string,pair<int,int> > > v;
struct process
{
    string id;
    int ar;
    int ct;
    int cct;
    int wt;
    int tt;
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
        //cout<<"d3\n";
        hq=cpy(pt);
        return;
    }
    process *cu=hq;
    if(cu->n==NULL||cu->n==cu)
    {
        //cout<<"d4\n";
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
        //cout<<"l1\n";
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
    bool z=0;
    process *cu=hq;
    if(p==hq)
    {
        hq=hq->n;
    }
    while(cu->n!=p)
    {
        z=1;
        cu=cu->n;
    }
    if(z==1)
    {
        cu->n=p->n;
    }
    else
    {
        cu->n=NULL;
        //cout<<"NU\n";
    }
    lp=1;
}
void shcn(process *p,int t)
{
    cout<<"Process ID:"<<p->id<<'\n';
    cout<<"Process Arrival:"<<p->ar<<'\n';
    if(p->ct<=0)
    {
        //cout<<"d1\n";
        p->wt=t-p->ar-p->cct;
        p->tt=t-p->ar;
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
    ll t=0,pt=0;
    bool z=0;
    process * px;
    while(co<c)
    {
        te=h;
        lp=0;
        cout<<"At Time:"<<t<<'\n';
        while(te!=NULL)
        {
            //cout<<"nu\n";
            if(te->ar<=t)
            {
                if(hq==NULL)
                {
                    //cout<<"d1\n";
                    clq(NULL,te);
                    cu=hq;
                }
                else
                {
                    //cout<<"d2\n";
                    clq(cu,te);
                }
                del(te);
            }
            te=te->n;
        }

        pt+=ts;

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
            //cout<<"d2\n";
            t+=px->ct;
            px->ct-=ts;
            if(pt>t)
                pt-=ts;
        }
        else
        {
            px->ct-=(pt-t);
            //cout<<px->ct<<'\n';
            t=pt;
        }
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
        cout<<v[i].first<<"\t"<<v[i].second.first<<"\t"<<v[i].second.second<<"\n";
    }
    cout<<"Average Turnaround Time:"<<att/c<<'\n';
    cout<<"Average Waiting Time:"<<awt/c<<'\n';
}
