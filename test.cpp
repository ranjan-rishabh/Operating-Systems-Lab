#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;
ll x,co=0,t=0,awt=0,att=0;
vector < pair < ll , pair< ll , ll> > > wtt;
struct process
{
    int pid;
    int prior;
    int b_t;
    int bo_t;
    process *n;
}*h1=NULL,*h2=NULL;
process *crn()
{
    process *p=new process;
    cout<<"Enter Pid:";
    cin>>p->pid;
    p->prior=x;
    cout<<"Enter Burst Time:";
    cin>>p->b_t;
    p->bo_t=p->b_t;
    p->n=NULL;
    return p;
}
void crq1()
{
    if(h1==NULL)
    {
        h1=crn();
        h1->n=h1;
    }
    else
    {
        process *p=crn();
        process *cu=h1;
        while(cu->n!=h1)
        {
            cu=cu->n;
        }
        cu->n=p;
        p->n=h1;
    }
}
void crq2()
{
    if(h2==NULL)
    {
        h2=crn();
        h2->n=h2;
    }
    else
    {
        process *p=crn();
        process *cu=h2;
        while(cu->n!=h2)
        {
            cu=cu->n;
        }
        cu->n=p;
        p->n=h2;
    }
}
void shcn(process *p)
{
    cout<<"Process ID:"<<p->pid<<'\n';
    cout<<"Process Priority:"<<p->prior<<'\n';
}
void delq1(process *p)
{
    if(p==h1&&(h1->n==h1))
    {
        h1=NULL;
    }
    else
    {
        process *cu=h1;
        while(cu->n!=p)
        {
            cu=cu->n;
        }
        cu->n=p->n;
        if(p==h1)
            h1=h1->n;
    }
    //wtt.push_back(make_pair(p->pid,make_pair(t-p->bo_t,t)));
        cout<<"Waiting Time:"<<t-p->bo_t<<'\n';
    cout<<"Turnaround Time:"<<t<<'\n';
    awt+=t-p->bo_t;
    att+=t;
    shcn(p);
    co++;
    delete(p);
}
void delq2(process *p)
{
    if(p==h2&&(p->n==h2))
    {
        //cout<<"f\n";
        h2=NULL;
    }
    else
    {
        process *cu=h2;
        while(cu->n!=p)
        {
            cu=cu->n;
        }
        cu->n=p->n;
        if(p==h2)

        {
            //cout<<"f1\n";
            h2=h2->n;
        }
    }
    //wtt.push_back(make_pair(p->pid,make_pair(t-p->bo_t,t)));
    cout<<"Waiting Time:"<<t-p->bo_t<<'\n';
    cout<<"Turnaround Time:"<<t<<'\n';
    awt+=t-p->bo_t;
    att+=t;
    shcn(p);
    co++;
}
main()
{
    ll c,i=0;
    cout<<"Enter Number Of Processes:";
    cin>>c;
    for(i=0;i<c;i++)
    {
        cout<<"Enter Priority Of Process:";
        cin>>x;
        if(x==1)
        {
            crq1();
        }
        else
        {
            crq2();
        }
    }
    process *cu1=h1,*cu2=h2,*cu;
    while(co<c)
    {
        if(h1!=NULL)
        for(int j=0;j<4;j++)
        {
            if(cu1->b_t<2)
            {
                t+=cu1->b_t;
            }
            else
                t+=2;
            cu1->b_t-=2;
            cu=cu1->n;
            if(cu1->b_t<=0)
            {
                cout<<'\n'<<"Process Completed"<<'\n';
                delq1(cu1);
                getch();
            }
            if(h1==NULL)
                break;
            cu1=cu;
        }
        if(h2!=NULL)
        for(int j=0;j<2;j++)
        {
            if(cu2->b_t<2)
            {
                t+=cu2->b_t;
            }
            else
                t+=2;
            cu2->b_t-=2;
            cu=cu2->n;
            if(cu2->b_t<=0)
            {
                cout<<'\n'<<"Process Completed"<<'\n';
                delq2(cu2);
                getch();
            }
            if(h2==NULL)
                break;
            cu2=cu;
        }
    }
    /*cout<<"Waiting Times And Turnaround Time:\n";
    for(int j=0;j<wtt.size();j++)
    {
        cout<<wtt[i].first<<"\t"<<wtt[i].second.first<<"\t"<<wtt[t].second.second<<"\n";
    }*/
    cout<<"Average Waiting Time:"<<(double)awt/c;
    cout<<"Average Turnaround Time:"<<(double)att/c;
}
