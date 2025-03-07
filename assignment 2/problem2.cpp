#include <bits/stdc++.h>

int main() {
    std::vector<std::pair<int, std::string>> vec;

    std::string s;
    while (getline(std::cin, s)) {
        if (s != "end") {
            std::stringstream ss(s);
            int hlp1;
            std::string hlp2;
            ss >> hlp1 >> hlp2;
            vec.emplace_back(hlp1, hlp2);
        } else {
            break;
        }
    }

    int k, t;
    std::cin >> k >> t;

    int start = 0;
    int sum = 0;
    bool ans = false;

    for (int i = 0; i <= vec.size() - k; i++) {
        if (vec[i].second == "Gold") {
            bool prob = false;
            sum = vec[i].first;

            for (int j = 1; j < k; j++) {
                if (i + j >= vec.size() || vec[i + j].second != "Gold") {
                    prob = true;
                    break;
                }
                sum += vec[i + j].first;
            }

            if (!prob && sum == t) {
                ans = true;
                start = i + 1;
                break;
            }
        }
    }

    if (!ans) {
        int minSum = INT_MAX;

        for (int i = 0; i <= vec.size() - k; i++) {
            int hlp = 0;

            for (int j = 0; j < k; j++) {
                if (i + j >= vec.size()) {
                    break;
                }
                hlp += vec[i + j].first;
            }

            if (hlp < minSum) {
                minSum = hlp;
                start = i + 1;
            }
        }

        std::cout << start << std::endl;
    } else {
        std::cout << start << std::endl;
    }

    return 0;
}
