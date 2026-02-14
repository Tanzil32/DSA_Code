#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    cin>>v[i];
    int val;
    cin>>val;
    v.push_back(val);
    int current_index = v.size()-1;
    while (current_index!=0)
    {
        int par_index = (current_index-1)/2;
        if(v[par_index]< v[current_index])
        swap(v[par_index], v[current_index]);
        else
        break;
        current_index = par_index;
    }
    for(int x:v)
    cout<<x<<endl;
    
    return 0;
}