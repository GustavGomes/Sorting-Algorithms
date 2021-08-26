#include <iostream>
#include <vector>

std::vector<int> ReadInput() {
    size_t input;
    std::cin >> input;
    std::vector<int> arr(input);
    for (auto &i : arr) {
        std::cin >> i;
    }
    return arr;
}

void PrintVector(const std::vector<int>& arr) {
    for (auto &i : arr) {
        std::cout << i << " ";
    }
}

void InsertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int main = arr[i];
        size_t j = i;
        while (j >= 1 && arr[j - 1] > main) {
            arr[j] = arr[j - 1];
            j--;
            arr[j] = main;
        }
    }
}

int main() {
    std::vector<int> vec = ReadInput();
    InsertionSort(vec);
    PrintVector(vec);
    return 0;
}
