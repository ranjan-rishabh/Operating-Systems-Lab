#include<bits/stdc++.h>
using namespace std;
// Linked Allocation

int c[100];
bool b;
struct link
{
    int val;
    link *n;
};
struct file
{
    string name;
    int type;
    int s;
    link *h;
};
struct directory
{
    string name;
    directory *l,*r,*u;
    file *f[100];
    int k;
}*h=NULL;
void ini()
{
    int i=99;
    for(;i>=0;i--)
    {
        c[100-i]=i;
    }
}
void path(directory *d)
{
    while(d!=h)
    {
        cout<<d->name<<"->";
        d=d->u;
    }
    cout<<"R"<<'\n';
}
directory *crn(string n)
{
    directory *d=new directory;
    d->name=n;
    d->l=NULL;
    d->u=NULL;
    d->r=NULL;
    d->k=0;
    return d;
}
void crdirec(string pa,file *fi)
{
    if(h==NULL)
    {
        h=crn("R");
    }
    int i;
    directory *c=h;
    for(i=0;i<pa.size();i++)
    {
        if(i==pa.size()-1)
        {
            if(pa[i]=='q')
            {
                h->f[h->k]=fi;
                h->k++;
                cout<<"File Added To Directory:";
                path(c);
            }
            else
            {
                c->f[c->k]=fi;
                c->k++;
                cout<<"File Added To Directory:";
                path(c);
            }
        }
        else
        {
            if(pa[i+1]=='l')
            {
                if(c->l==NULL)
                {
                    string s;
                    cout<<"Enter Name Of Directory To Be Formed:";
                    cin>>s;
                    c->l=crn(s);
                    c->l->u=c;
                }
                c=c->l;
            }
            if(pa[i+1]=='r')
            {
                if(c->r==NULL)
                {
                    string s;
                    cout<<"Enter Name Of Directory To Be Formed:";
                    cin>>s;
                    c->r=crn(s);
                    c->r->u=c;
                }
                c=c->r;
            }
        }
    }
}
void ndir(string x,directory *cu)
{
    if(cu==NULL)
    {
        cout<<"No Directories Found\n";
        return;
    }
    if(cu->name==x)
    {
        cout<<"Number Of Files:"<<cu->k<<'\n';
        b=1;
        return;
    }
    else
    {
        if(cu->l!=NULL)
            ndir(x,cu->l);
        if(cu->r!=NULL)
            ndir(x,cu->r);
        if(b==0)
        {
            cout<<"No Such Directory\n";
            b=1;
        }
    }
}
void shph(string n,directory *cu)
{
    int i;
    for(i=0;i<cu->k;i++)
    {
        if(cu->f[i]->name==n)
        {
            path(cu);
            b=1;
            break;
        }
    }
    if(b==1)
    {
        return;
    }
    else
    {
        if(cu->l!=NULL)
            shph(n,cu->l);
        if(cu->r!=NULL)
            shph(n,cu->r);
        if(b==0)
        {
            cout<<"No Such File Exists\n";
            b=1;
        }
    }
}
link *crl(int v)
{
    link *l=new link;
    l->val=v;
    l->n=NULL;
    return l;
}
void lall(file *fi)
{
    int i=0,t=99,p=1;
    link *cu;
    for(;i<5;i++)
    {
        if(i==0)
        {
            fi->h=crl(c[t]);
            cu=fi->h;
        }
        else
        {
            cu->n=crl(c[t]);
            cu=cu->n;
        }
        c[t]=0;
        sort(c,c+100);
        t=(t-2*p)%100;
        p=p+1;
    }
}
void crfile(string n)
{
    file *fi=new file;
    fi->name=n;
    cout<<"Type:";
    int q;
    cin>>q;
    fi->type=q;
    fi->s=5;
    int i=0,t=99,p=1;
    lall(fi);
    cout<<"File Created\n";
    string pl;
    cout<<"Specify Path Of Directory:";
    cin>>pl;
    crdirec(pl,fi);
}
void shcn(string n,directory *cu)
{
    int i;
    for(i=0;i<cu->k;i++)
    {
        if(cu->f[i]->name==n)
        {
            cout<<"File Name:"<<cu->f[i]->name<<'\n';
            cout<<"Type:"<<cu->f[i]->type<<'\n';
            cout<<"Memory Blocks:";
            link *c=cu->f[i]->h;
            for(;c!=NULL;c=c->n)
            {
                cout<<c->val<<" ";
            }
            cout<<"\n";
            b=1;
            break;
        }
    }
    if(b==1)
    {
        return;
    }
    else
    {
        if(cu->l!=NULL)
            shcn(n,cu->l);
        if(cu->r!=NULL)
            shcn(n,cu->r);
        if(b==0)
        {
            cout<<"No Such File Exists\n";
            b=1;
        }
    }
}
void delf(string n,directory *cu)
{
    int i;
    for(i=0;i<cu->k;i++)
    {
        if(cu->f[i]->name==n)
        {
            file *fl=cu->f[i];
            for(int j=i;j<cu->k-1;j++)
            {
                cu->f[j]=cu->f[j+1];
            }
            cu->k--;
            delete fl;
            cout<<"File Deleted\n";
            b=1;
            break;
        }
    }
    if(b==1)
    {
        return;
    }
    else
    {
        if(cu->l!=NULL)
            delf(n,cu->l);
        if(cu->r!=NULL)
            delf(n,cu->r);
        if(b==0)
        {
            cout<<"No Such File Exists\n";
            b=1;
        }
    }
}
void deld(string x, directory *cu)
{
    if(cu==NULL)
    {
        cout<<"No Directories Found\n";
        return;
    }
    if(cu->name==x)
    {
        delete cu;
        b=1;
        cout<<"Directory "<<x<<" And All Its Subdirectories Deleted\n";
    }
    else if(cu->l!=NULL&&cu->l->name==x)
    {
        directory *d=cu->l;
        cu->l->u=NULL;
        cu->l=NULL;
        delete d;
        b=1;
        cout<<"Directory "<<x<<" And All Its Subdirectories Deleted\n";
    }
    else if(cu->r!=NULL&&cu->r->name==x)
    {
        directory *d=cu->r;
        cu->r->u=NULL;
        cu->r=NULL;
        delete d;
        b=1;
        cout<<"Directory "<<x<<" And All Its Subdirectories Deleted\n";
    }
    else
    {
        if(cu->l!=NULL)
            deld(x,cu->l);
        if(cu->r!=NULL)
            deld(x,cu->r);
        if(b==0)
        {
            cout<<"No Such Directory\n";
            b=1;
        }
    }
}
main()
{
    int c=1;
    ini();
    while(c!=0)
    {
        cout<<"1)Create File\n2)Show File Path\n3)Show No Of Files In A Directory\n4)Show Contents Of A File\n5)Delete File\n6)Delete Directory\n0)Exit\nEnter:";
        cin>>c;
        switch(c)
        {
        case 1:
            {
                cout<<"Enter Name Of File:";
                string n;
                cin>>n;
                crfile(n);
                break;
            }
        case 2:
            {
                cout<<"Enter File Name:";
                string n;
                cin>>n;
                b=0;
                shph(n,h);
                break;
            }
        case 3:
            {
                cout<<"Enter Name Of Directory:";
                string d;
                cin>>d;
                ndir(d,h);
                break;
            }
        case 4:
            {
                cout<<"Enter File Name:";
                string n;
                cin>>n;
                b=0;
                shcn(n,h);
                break;
            }
        case 5:
            {
                b=0;
                cout<<"Enter File Name:";
                string n;
                cin>>n;
                delf(n,h);
                break;
            }
        case 6:
            {
                b=0;
                cout<<"Enter Directory Name:";
                string n;
                cin>>n;
                deld(n,h);
                break;
            }
        }
    }
}
