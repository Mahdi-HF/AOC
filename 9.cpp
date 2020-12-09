#include <bits/stdc++.h>

using namespace std;
vector<int> vec;

#define int long long

int32_t main() {
    int n;
    while (cin >> n) vec.push_back(n);

    int weakness = 0;
    int weaknessIndex = 0;

    for (int i = 25; i < vec.size(); i++) {
        bool possible = false;
        int number = vec[i];
        for (int j = i - 25; j < i; j++) {
            if (possible) break;
            for (int k = j + 1; k < i; k++) {
                if (vec[j] + vec[k] == number) {
                    possible = true;
                    break;
                }
            }
        }
        if (!possible) {
            cout << "part One: " << number << endl;
            weakness = number;
            weaknessIndex = i;
        }
    }

    bool found = false;
    set<int> st;
    for (int i = 0; i < weaknessIndex; i++) {
        if (found == true) break;
        int acc = vec[i];
        for (int j = i + 1; j < weaknessIndex; j++) {
            if (weakness == acc) {
                for (int kk = i; kk < j; kk++) st.insert(vec[kk]);

                int kk = 0, min, max;
                for (auto el : st) {
                    if (kk == 0) min = el;
                    if (kk == st.size() - 1) max = el;
                    kk++;
                }
                cout << "part Two: " << min + max << endl;
                found = true;
                break;
            }
            acc += vec[j];
        }
    }
}