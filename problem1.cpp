#include <bits/stdc++.h>

void extractor(int n, int* arr) {
    while(n>0) {
        int hlp = n%10;
        arr[hlp-1]++;
        n/=10;
    }
}

int smallestNumber(int *arr) {
    int small=0;
    for(int i=0;i<10;i++) {
        if(arr[i]>0) {
            for(int j = 1; j<=arr[i]; j++) {
                small*=10;
                small+=(i+1);
            }
        }
    }
    return small;
}

int main() {
    int n;
    std::cin>>n;
    int arr[10];
    for(int i=0;i<10;i++) {
        arr[i]=0;
    }
    extractor(n, arr);
    std::cout<<smallestNumber(arr);
}