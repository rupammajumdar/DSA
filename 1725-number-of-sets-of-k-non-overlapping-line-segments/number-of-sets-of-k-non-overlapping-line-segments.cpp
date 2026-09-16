class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;
        
        // If we need to pick more points than available
        if (K > N) return 0;
        
        // Function to calculate (base^exp) % MOD
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        
        // Function to find modular inverse using Fermat's Little Theorem
        auto modInverse = [&](long long n) {
            return power(n, MOD - 2);
        };
        
        // Calculate C(N, K) % MOD
        long long num = 1;
        long long den = 1;
        for (int i = 1; i <= K; ++i) {
            num = (num * (N - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        
        return (num * modInverse(den)) % MOD;
    }
};