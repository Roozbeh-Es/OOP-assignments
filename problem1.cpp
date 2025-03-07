#include <bits/stdc++.h>

void extractor(long long n, int* arr) {
    while (n > 0) {
        int hlp = n % 10;
        arr[hlp]++;
        n /= 10;
    }
}

long long smallestNumber(int *arr) {
    long long small = 0; /
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 0) {
            for (int j = 1; j <= arr[i]; j++) {
                small = small * 10 + i;
            }
        }
    }
    return small;
}

long long biggestNumber(int *arr) {
    long long big = 0;
    for (int i = 9; i >= 0; i--) {
        if (arr[i] > 0) {
            for (int j = 1; j <= arr[i]; j++) {
                big = big * 10 + i;
            }
        }
    }
    return big;
}

int main() {
    long long n;
    std::cin >> n;
    int arr[10] = {0};
    extractor(n, arr);
    std::cout << smallestNumber(arr) + biggestNumber(arr);
    return 0;
}
