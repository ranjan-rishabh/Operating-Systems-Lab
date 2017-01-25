#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;

ll att=0,awt=0;
struct process
{
    string id;
    int ar;
    int ct;
    int wt;
    int tt;
    process()
    {
        wt=0;
        tt=0;
    }
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
    p->n=NULL;
    return p;
}
void shcn(int t, process *cu)
{
    cout<<"Process ID:"<<cu->id<<'\n';
    cout<<"Process Arrival:"<<cu->ar<<'\n';
    cout<<"Process CPU Time:"<<cu->ct<<'\n';
    cu->wt=t-cu->ar-cu->ct;
    cu->tt=t-cu->ar;
    cout<<"Waiting Time:"<<cu->wt<<'\n';
    cout<<"Turnaround Time:"<<cu->tt<<'\n';
    att+=cu->tt;
    awt+=cu->wt;
}
void del(process *p)
{
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
    process *te=h;
    ll t=0,lt=LLONG_MAX;
    for(i=0;i<c;i++)
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
        t=t+cu->ct;
        cout<<"Process Completed\n";
        shcn(t,cu);
        cout<<'\n';
        del(cu);
        getch();
    }
    cout<<"Average Turnaround Time:"<<att/c<<'\n';
    cout<<"Average Waiting Time:"<<awt/c<<'\n';
}
