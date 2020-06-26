#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;

//ax + by = gcd(a,b), solves for (x,y)
//bx + (a-kb)y = g

/*
 ll g(ll a, ll b)
 {
 if (b == 0) return a;
 return g(b, a%b);
 }*/

ll GCD = 0;

ll2 gcd(ll a, ll b)
{
    if (b == 0) {GCD = a; return {1,0};}
    ll2 nxt = gcd(b, a%b);
    ll x = nxt.first;
    ll y = nxt.second;
    ll k = a/b;
    return {y, x-k*y};
}

int main()
{
    //ifstream inf("");
    //ofstream outf("");
    cout << setprecision(10);
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (true)
    {
        ll a, b, c; //solve ax + by = c
        cin >> a >> b >> c;
        ll2 d = gcd(a,b);
        if (c % GCD == 0)
        {
            ll mult = c/GCD;
            ll x = d.first*mult;
            ll y = d.second*mult;
            
            cout << a << "*" << x << " + " << b << "*" << y << " = " << c << '\n';
            
        }
        else cout << "impossible\n";
    }
    
    return 0;
    
}



