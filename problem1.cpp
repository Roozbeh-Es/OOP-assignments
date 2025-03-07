#include <bits/stdc++.h>

int digits(long long n) {
    int count = 0;
    while (n) {
        n /= 10;
        count++;
    }
    return count;
}

void extractor(int n, int* arr) {
    while(n>0) {
        int hlp = n%10;
        arr[hlp]++;
        n/=10;
    }
}

long long smallestNumber(int *arr) {
    int small=0;
    for(int i=0;i<10;i++) {
        if(arr[i]>0) {
            for(int j = 1; j<=arr[i]; j++) {
                small*=10;
                small+=i;
            }
        }
    }
    return small;
}
int biggestNumber(int *arr) {
    int big = 0;
    for(int i=9;i>=0;i--) {
        if(arr[i]>0) {
            for(int j = 1; j<=arr[i]; j++) {
                big = big*10+i;
            }
        }
    }
    return big;
}

int main() {
    long long n;
    std::cin>>n;
    int arr[10];
    for(int i=0;i<10;i++) {
        arr[i]=0;
    }
    extractor(n, arr);
    std::cout<< smallestNumber(arr) + biggestNumber(arr);
}