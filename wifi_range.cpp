#include<iostream>
#include<string>
using namespace std;

bool check(int X, int N, string S) {
    char* C;
    C = new char[N];
    for (int i = 0; i < N; i++) {
        C[i] = '0';
    }
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (X > i) {
                for (int k = i - 1; k >= 0; k--) {
                    C[k] = '1';
                }
            }
            if (N - i <= X) {
                for (int h = i + 1; h < N; h++) {
                    C[h] = '1';
                }
            }
            if (N - i > X) {
                for (int h = i + 1; h <= i + X; h++) {
                    C[h] = '1';
                }
            }
            if (X <= i) {
                for (int k = i - 1; k >= i - X; k--) {
                    C[k] = '1';
                }
            }
        }
        if (S[i] == '1') {
            C[i] = '1';
        }
    }
    for (int i = 0; i < N; i++) {
        if (C[i] == '0') {
            delete[] C;
            return 0;
        }
    }
    delete[] C;
    return 1;
}

/*
bool wifiRange(int N, string S, int X)
    {
        set<int> uncovered;
        for (int i = 0; i < N; i++) {
            uncovered.insert(i);
        }
        int i = 0;
        while (i < S.size() && !uncovered.empty()) {
            if (S[i] == '1') {
                for (int j = max(0, i - X);
                     j <= min(N - 1, i + X); j++) {
                    if (uncovered.find(j)
                        != uncovered.end()) {
                        uncovered.erase(j);
                    }
                }
            }
            i++;
        }
        return uncovered.empty();
    }
*/

/*
class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        vector<int> A(N, -1e9), B(N, 1e9);
        int cur = -1e9;
        for(int i = 0; i < N; i++){
            if(S[i] == '1'){
                cur = i;
            }
            A[i] = cur;
        }
        cur = 1e9;
        for(int i = N - 1; i >= 0; i--){
            if(S[i] == '1'){
                cur = i;
            }
            B[i] = cur;
        }
        for(int i = 0; i < N; i++){
            if(abs(i - A[i]) > X && abs(i - B[i]) > X){
                return false;
            }
        }
        return true;
    }
};
*/

int main() {
    int n;
    string S;
    int X;
    cout << "S= ";
    getline(cin, S);
    cout << "n= ";
    cin >> n;
    cout << "X= ";
    cin >> X;
    cout << check(X, n, S);
}
