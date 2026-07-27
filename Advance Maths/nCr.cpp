#include <bits/stdc++.h>
using namespace std;
 
long long MAX = 1e6;
long long M = 1e9 + 7;
 
vector<long long>fact(MAX + 1 , 0);
vector<long long>invfact(MAX + 1 , 0);
 
long long power(long long a , long long b){
    if(b == 0) return 1;
    
    long long half = power(a , b / 2);
    long long ans = half * half % M;
    if(b % 2 == 1) ans = ans * a % M;
    return ans;
}
 
void compute(){
    fact[0] = 1;
    for(int i=1 ; i<=MAX ; i++) fact[i] = 1LL * i * fact[i-1] % M;
    
    invfact[MAX] = power(fact[MAX] , M - 2) % M;
    
    for(int i = MAX ; i>=1 ; i--) invfact[i-1] = 1LL* i * invfact[i] % M;
}
 
long long nCr(long long n , long long r){
    if(r < 0 || r > n) return 0;
    
    return fact[n] * invfact[n-r] % M * invfact[r] % M;
}
 
int main() {
    int n;
    cin >> n;
    
    compute();
    
    while(n--){
        long long n , r;
        cin >> n >> r;
        cout << nCr(n , r) << endl;
    }
}