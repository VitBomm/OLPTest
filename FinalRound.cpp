#include <iostream>
#include <math.h>
#include <vector>
#define lli long long int
using namespace std;
lli e;
int countt = 0;
int i,j,m;
void Check(vector<lli> &v,lli par,int n)
{
    i = 0;
    while (i<n-2) {
        if(v[i] <=par)
        {
            j = i+1;
            while(j<n-1)
            {
                if(v[i]*v[j] <=par)
                {
                    m = j+1;
                    while (m<n) {
                        if(v[i]*v[j]*v[m] == par)
                            {
                                countt++;
                            }
                        m++;
                    }
                }
                j++;
            }
        }
        i++;
    }
//    for(int i = 0; i<n-2;i++)
//    {
//        if(v[i]<=par){
//        for(int j = i+1 ;j<n-1;j++)
//        {
//            if(v[i]*v[j]<=par)
//            {
//            for(int m = j+1; m<n;m++)
//            {
//                    if(v[i]*v[j]*v[m] == par)
//                    {
//                        countt++;
//                    }
//            }
//            }
//        }
//        }
//    }
}
int main()
{
    int n;
    vector<lli> v;
    cin>>n;
    for(int i =0 ; i<3;i++)
    {
        cin>>e;
        v.push_back(e);
    }
    for(int i =3; i<n;i++)
    {
        cin>>e;
        v.push_back(e);
        Check(v,v[i],i);
    }
    cout<<countt;
    return 0;
}
// a * b * c =d
//
// 6 10 2 2 7 40 160
// Way1: 10 2 2 = 40
