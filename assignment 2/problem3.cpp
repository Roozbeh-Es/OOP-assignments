#include <bits/stdc++.h>

long long* insert(const long long *arr, int &currentSize,long long value) {
    long long* newArr = new long long[currentSize+1];
    for (int i = 0; i < currentSize; i++) {
        newArr[i] = arr[i];
    }
    newArr[currentSize] = value;
    currentSize++;
    delete[] arr;
    return newArr;
}

long long* pop(const long long* arr, int pos, int& currentSize) {

    long long* newArr = new long long[currentSize - 1];
    for (int i = 0, j = 0; i < currentSize; i++) {
        if (i != pos) {
            newArr[j++] = arr[i];
        }
    }
    currentSize--;
    delete[] arr;

    return newArr;
}


int main() {
    long long* arr = nullptr;
    int currentSize = 0;

    std::string s;
    while(std::getline(std::cin, s)) {
        if(s=="exit")
            break;
        if(s.find("insert") == 0) {
            long long value = std::stoi(s.substr(7, s.length()));
            arr = insert(arr, currentSize, value);
        }
        else if(s.find("pop") == 0) {
            int pos = std::stoi(s.substr(4, s.length()));
            arr = pop(arr, pos, currentSize);
        }
        else if(s.find("print") == 0) {
            for (int i = 0; i < currentSize; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout<<std::endl;
        }
        else if(s.find("swap") == 0) {
            std::string trash;
            int pos1, pos2;
            std::stringstream ss(s);
            ss>>trash>>pos1>>pos2;
            std::swap(arr[pos1], arr[pos2]);
        }
    }
}