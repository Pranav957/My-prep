class Solution {
    const int MOD = 1e9 + 7;
public:
    long long power(long long base, long long expo) {
        if (expo == 0)
            return 1;

        if (expo % 2 == 0)
            return power((base * base) % MOD, expo / 2);
        else
            return (base * power(base, expo - 1)) % MOD; // FIXED
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long evenDigits = power(5, evenPos);
        long long oddDigits = power(4, oddPos);

        return (evenDigits * oddDigits) % MOD;
    }
};
