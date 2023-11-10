#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int num) { //Ham kiem tra so nguyen to
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
bool isSuperPrime(int num) { //Ham kiem tra so sieu nguyen to
    while (num > 0) {
        if (!isPrime(num))
            return false;
        num /= 10;
    }
    return true;
}

vector<int> TimSNT(int n) {
    vector<int> SuperPrimes;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            SuperPrimes.push_back(i);
        }
    }
    return SuperPrimes;
}
int main() {
    int n;
    cin >> n;
    vector<int> superPrimes = TimSNT(n);

    sort(superPrimes.begin(), superPrimes.end());
 
    for (int res : superPrimes) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
