#include <stdio.h>
#define MOD 1000000007
typedef long long ll;
ll modpow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}
ll modinv4() {
    return modpow(4, MOD - 2); 
}
int main() {
    ll n;
    scanf("%lld", &n);
    ll total_cells = n * n;
    ll f0 = modpow(2, total_cells);
    ll half180 = (total_cells + 1) / 2;
    ll f180 = modpow(2, half180);
    ll orbits = (n * n + 3) / 4;
    ll f90 = modpow(2, orbits);
    ll f270 = f90; 
    ll sum = (f0 + f180 + f90 + f270) % MOD;
    ll result = sum * modinv4() % MOD;
    printf("%lld\n", result);
    return 0;
}
