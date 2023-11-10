#include <iostream>
#include <stack>
#include <string>
using namespace std;

string encodeString(const string& str) {
    stack<pair<char, int>> st; // Khai bao stack voi ky tu va so lan xuat hien ky tu
    string result;
    for (char c : str) {
        if (!st.empty() && st.top().first == c) {
            // Kiem tra stack
            st.top().second++; 
        }
        else {
            st.push({ c, 1 });  //Neu khac ky tu thi them cap moi voi so lan la 1
        }
    }
    // Dao nguoc chuoi
    while (!st.empty()) {
        auto& top = st.top();
        result = top.first + to_string(top.second) + result;
        st.pop();
    }
    return result;
}
int main() {
    string S;
    cin >> S; 
    string encoded = encodeString(S);
    cout << encoded << endl;
    return 0;
}
