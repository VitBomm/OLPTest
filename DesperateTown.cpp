#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;
int Matrix[MAX][MAX];
int n,r,e;
int _Maxtemp;
bool kt2;
int o;
bool Check(int x1,int y1,int x2, int y2,int r)
{
    if(r>=(abs(x1-x2) + abs(y1-y2)))
    {
        return true;
    }
    return false;
}
vector<pair<pair<int, int>,pair<int, int>>> v;
int main()
{
    cin>>n>>r;
    pair<pair<int, int>, pair<int, int>> temp;
    for(int i = 0 ; i<n;i++)
    {
        for(int j = 0; j<n;j++)
        {
            cin>>e;
            temp.first.first = j;
            temp.first.second = i;
            temp.second.first = e;
            temp.second.second = 1;
            v.push_back(temp);
        }
    }
    bool kt = false;
    do {
        kt = false;
        for(int i = 0; i<v.size();i++)
        {
            kt2 = false;
            _Maxtemp = v[i].second.first;
            for(int j =0 ; j<v.size();j++)
            {
                if(v[i]!=v[j] && v[i].second.second != 0)
                {
                    // v[i].first.first = j
                    if(Check(v[i].first.second,v[i].first.first,v[j].first.second, v[j].first.first,r))
                    {
                        if(v[j].second.first > _Maxtemp)
                        {
                            _Maxtemp = v[j].second.first;
                            o = j;
                            kt = true;
                            kt2 = true;
                        }
                    }
                }
            }
            if(o!=i && kt2 == true)
                {
                    v[o].second.second += v[i].second.second;
                    v[i].second.second = 0;
                    break;
                }
//            for(int m =0; m<v.size();m++)
//            {
//
//                if(v[m].second.first == _Maxtemp && v[m] != v[i])
//                {
//                    v[m].second.second += v[i].second.second;
//                    v[i].second.second = 0;
//                    break;
//                }
//            }
        }
    }while (kt == true);
    int house = n*n;
    int resultmax = 1;
    pair<pair<int, int>, pair<int, int>> tempp;
    for(int i = 0; i<v.size();i++)
    {
        tempp = v[i];
        if(tempp.second.second ==0)
        {
            house--;
        }
        resultmax = max(resultmax,tempp.second.second);
    }
    cout<<house<<" "<<resultmax;

    return 0;
}
/*
 3 0 9 1 6 5 3 2 7 4 8
 1 1 1
 3 4 9 1 6 5 3 2 7 4 8
 */
