#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Comparator{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t):group(_group),t(_t) {}
    bool operator () (int a,int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};

vector<int> getSuffixArray(const string& s){
    int n=(int)s.size(),t=1;
    vector<int> group(n+1), perm(n);
    for(int i=0; i<n; ++i){
        group[i] = s[i];
        perm[i] = i;
    }
    group[n]=-1;
    while(t<n){
        Comparator compareUsing2T(group,t);
        sort(perm.begin(),perm.end(),compareUsing2T);
        t *= 2;
        if( t>=n ) break;
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]]=0;
        for(int i=1;i<n;++i){
            if(compareUsing2T(perm[i-1],perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group=newGroup;
    }
    return perm;
}

vector<int> makeLcp(const string& s, const vector<int>& sa){
    int i,j,k=0,n=(int)s.size();
    vector<int> lcp(n),rank(n);
    for(i=0;i<n;++i)rank[sa[i]]=i;
    for(i=0;i<n;lcp[rank[i++]]=k){
        for(k?k--:0,j=(rank[i]?sa[rank[i]-1]:n);i+k<n&&j+k<n&&s[i+k]==s[j+k];k++);
    }
    return lcp;
}

int main(){
    string s;
    getline(cin,s);
    vector<int> sa = getSuffixArray(s), lcp=makeLcp(s,sa);	
    for(int i=0; i<sa.size();++i) printf("%d ",sa[i]+1);
    printf("\nx ");
    for(int i=1; i<lcp.size();++i) printf("%d ",lcp[i]);
}
