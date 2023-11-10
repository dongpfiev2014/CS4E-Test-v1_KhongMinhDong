#include <iostream>
using namespace std;

int TongUocSo(int n);

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, res;
        cin >> n;
        res = TongUocSo(n);
        cout << res << endl;
    }
    return 0;
}

int TongUocSo(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum + n;
}