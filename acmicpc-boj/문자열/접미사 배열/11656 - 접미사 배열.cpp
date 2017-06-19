#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> sa;
string s;

struct Comparator{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t):group(_group),t(_t) {}
    bool operator () (int a,int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};

void getSuffixArray(const string& s){
    int n=(int)s.size(),t=1;
    vector<int> group(n+1);
    sa = vector<int>(n);
    for(int i=0; i<n; ++i){
        group[i] = s[i];
        sa[i] = i;
    }
    group[n]=-1;
    while(t<n){
        Comparator compareUsing2T(group,t);
        sort(sa.begin(),sa.end(),compareUsing2T);
        t *= 2;
        if( t>=n ) break;
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[sa[0]]=0;
        for(int i=1;i<n;++i){
            if(compareUsing2T(sa[i-1],sa[i]))
                newGroup[sa[i]] = newGroup[sa[i-1]] + 1;
            else
                newGroup[sa[i]] = newGroup[sa[i-1]];
        }
        group=newGroup;
    }
}

int main(){
    string s;
    getline(cin,s);
    getSuffixArray(s);
    for(auto &a : sa) {
        cout << s.substr(a) << '\n';
    }
}
