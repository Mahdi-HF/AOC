#include <bits/stdc++.h>

int main() {
    int finalRes = 0, finalRes2 = 0, number = 0;
    std::string str;
    std::set<char> st;
    std::multiset<char> st2;
    while (getline(std::cin, str)) {
        if (str != "") {
            number++;
            for (int i = 0; i < str.length(); i++) {
                st.insert(str[i]);
                st2.insert(str[i]);
            }
        } else {
            std::set<char> hasSeen;
            for (auto el : st2) {
                if (st2.count(el) == number and !hasSeen.count(el)) finalRes2++;
                hasSeen.insert(el);
            }
            finalRes += st.size();
            st.clear();
            st2.clear();
            number = 0;
        }
    }
    std::set<char> hasSeen;
    for (auto el : st2) {
        if (st2.count(el) == number and !hasSeen.count(el)) finalRes2++;
        hasSeen.insert(el);
    }
    finalRes += st.size();

    std::cout << "part one: " << finalRes << std::endl;
    std::cout << "part two: " << finalRes2 << std::endl;

    return 0;
}