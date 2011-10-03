//#define _GLIBCXX_DEBUG
/*
 * File: main.cpp
 * Author: eriksi
 *
 * Created on October 1, 2011, 11:05 AM
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <set>
//#include <multimap.h>

using namespace std;

#define sz(c) ((c).size())
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef long long LL;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <string> VS;

int treeSize;
VI tree;

int startpos(int v){
    return treeSize/2+v;
}

void insert(int v){
    int x = startpos(v);
    while(x){
        tree[x]++;
        x/=2;
    }
}

int less_than(int v){
    int x = startpos(v);
    int sum = 0;
    while(x>1){
        if(x&1){
            sum += tree[x-1];
        }
        x/=2;
    }
    return sum;
}


int greater_than(int v){
    int x = startpos(v);
    int sum = 0;
    while(x>1){
        if((x&1) == 0){
            sum += tree[x+1];
        }
        x/=2;
    }
    return sum;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    treeSize = 1 << 18;
// while(n > treeSize){
// treeSize<<=1;
// }
// treeSize<<=1;
// cout << treeSize << endl;
    
    VI a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    VI greaters(n);
    {
        tree = VI(treeSize);
        for (int i = n-1; i >= 0; i--) {
            greaters[i] = greater_than(i);
            insert(a[i]);
        }
    }

    VI lessers(n);
    {
        tree = VI(treeSize);
        for (int i = 0; i < n; i++){
            lessers[i] = less_than(i);
            insert(a[i]);
        }
    }
    
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        sum += LL(lessers[i]) * LL(greaters[i]);
    }

    cout << sum << endl;
}


