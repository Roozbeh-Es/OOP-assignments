#include <bits/stdc++.h>

int* insert(int *arr, int &currentSize,int value) {
    int* newArr = new int[currentSize+1];
    for (int i = 0; i < currentSize; i++) {
        newArr[i] = arr[i];
    }
    newArr[currentSize] = value;
    currentSize++;
    delete[] arr;
    return newArr;
}

int* pop(int *arr,int pos,int &currentSize) {
    int* newArr = new int[currentSize-1];
    for (int i = 0; i < currentSize; i++) {
        if (i<pos)
            newArr[i] = arr[i];
        else if (i==pos) {
            i++;
            newArr[i] = arr[i];
        }
    }
    currentSize--;
    delete[] arr;
    return newArr;
}

int main() {
    int* arr = nullptr;
    int currentSize = 0;

    std::string s;
    while(std::getline(std::cin, s)) {
        if(s=="exit")
            break;
        if(s.find("insert") == 0) {
            int value = std::stoi(s.substr(7, s.length()));
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