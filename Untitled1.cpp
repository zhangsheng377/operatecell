#include <iostream>
#include <math.h>
using namespace std;
struct Node
{
    int left=0;
    int right=0;
    int sum=0;
    int max=0;
}t[2000000];
void adjust(int i,int n)
{
    int ii=i/2;
    t[ii].left=t[ii*2].left;
    /*
    if ((ii*2+1)<=(n)) {t[ii].right=t[ii*2+1].right;
                            t[ii].sum=t[ii*2].sum + t[ii*2+1].sum;
                            if (t[ii*2].max > t[ii*2+1].max) t[ii].max=t[ii*2].max;
                            else t[ii].max=t[ii*2+1].max;
                            }
    else {t[ii].right=t[ii*2].right;
             t[ii].sum=t[ii*2].sum;
             t[ii].max=t[ii*2].max;}*/
    if(t[ii*2+1].right>t[ii*2].right) t[ii].right=t[ii*2+1].right;
    else t[ii].right=t[ii*2].right;
    t[ii].sum=t[ii*2].sum + t[ii*2+1].sum;
    if (t[ii*2].max > t[ii*2+1].max) t[ii].max=t[ii*2].max;
    else t[ii].max=t[ii*2+1].max;

    if (ii>1) adjust(ii,n);
}
int tmax(int a,int b,int i)
{   /*int mid=(t[i].right-t[i].left)/2+t[i].left;
    if(a==t[i].left && b==t[i].right) {return t[i].max;}
    if(a>mid && b>mid) return tmax(a,b,2*i+1);
    //if(a<mid && b>mid) return tmax(a,mid,2*i)+tmax(mid+1,b,2*i+1);
    if(a<=mid && b>mid) {int aa=tmax(a,mid,2*i);int bb=tmax(mid+1,b,2*i+1);if(aa>bb) return aa;else return bb;}
    if(a<=mid && b<=mid) return tmax(a,b,2*i);*/
    if(a==t[i].left && b==t[i].right) return t[i].max;
    if(a>t[2*i].right && b>t[2*i].right) return tmax(a,b,2*i+1);
    if(a<=t[2*i].right && b>t[2*i].right) {int aa=tmax(a,t[2*i].right,2*i);int bb=tmax(t[2*i].right+1,b,2*i+1);if(aa>bb) return aa;else return bb;}
    if(a<=t[2*i].right && b<=t[2*i].right) return tmax(a,b,2*i);
}
int tsum(int a,int b,int i)
{   /*int mid=(t[i].right-t[i].left)/2+t[i].left;
    if(a==t[i].left && b==t[i].right) {return t[i].sum;}
    if(a>mid && b>mid) return tsum(a,b,2*i+1);
    if(a<=mid && b>mid) return tsum(a,mid,2*i)+tsum(mid+1,b,2*i+1);
    //if(a<=mid && b>mid) {int aa=tmax(a,mid,2*i);int bb=tmax(mid+1,b,2*i+1);if(aa>bb) return aa;else return bb;}
    if(a<=mid && b<=mid) return tsum(a,b,2*i);*/
    if(a==t[i].left && b==t[i].right) return t[i].sum;
    if(a>t[2*i].right && b>t[2*i].right) return tsum(a,b,2*i+1);
    if(a<=t[2*i].right && b>t[2*i].right) return tsum(a,t[2*i].right,2*i)+tsum(t[2*i].right+1,b,2*i+1);
    if(a<=t[2*i].right && b<=t[2*i].right) return tsum(a,b,2*i);
}
int main()
{
    int n,m;
    cin>>n;cin>>m;

    int i;
    int nn=log(n)/log(2);
    if(log(n)/log(2) >nn) nn++;//cout<<log(n)/log(2)<<endl;
    nn=pow((double)2,(double)nn);//cout<<nn<<endl;
    for(i=nn;i<nn+n;i++)
    {
        cin>>t[i].sum;
        t[i].max=t[i].sum;
        t[i].left=i;
        t[i].right=i;
        adjust(i,nn+n-1);
    }
    //for(i=1;i<nn+n;i++) cout<<i<<" "<<t[i].left<<" "<<t[i].right<<" "<<t[i].sum<<" "<<t[i].max<<" "<<endl;
    int p,x,y;
    for(i=0;i<m;i++)
    {
        cin>>p;cin>>x;cin>>y;
        switch(p)
        {
        case 1:
            {
                t[x+nn-1].sum=y;t[x+nn-1].max=y;
                adjust(x+nn-1,nn+n-1);
                break;
            }
        case 2:
            {
                cout<<tsum(x+nn-1,y+nn-1,1)<<endl;
                break;
            }
        case 3:
            {
                cout<<tmax(x+nn-1,y+nn-1,1)<<endl;
                break;
            }

        }
    }



    return 0;
}


