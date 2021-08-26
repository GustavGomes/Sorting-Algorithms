#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
struct CustomComparator {
    bool operator()(const T &lhs, const T &rhs) {
        return lhs < rhs;
    }
};

template <typename T, typename Compare = CustomComparator<T>>
T SelectPivot(const std::vector<T> &arr, size_t left, size_t right, Compare comp = Compare()) {
    size_t middle = (right + left) / 2;
    if (comp(arr[middle], arr[left])) {
        if (comp(arr[right], arr[middle])) {
            return middle;
        } else if (comp(arr[right], arr[left])) {
            return right;
        } else {
            return left;
        }
    } else {
        if (comp(arr[right], arr[left])) {
            return left;
        } else if (comp(arr[right], arr[middle])) {
            return right;
        } else {
            return middle;
        }
    }
}

template <typename T, typename Compare = CustomComparator<T>>
size_t Partition(std::vector<T> &arr, size_t left, size_t right, Compare comp = Compare()) {
    std::swap(arr[left], arr[SelectPivot(arr, left, right, Compare())]);
    T pivot = arr[left];
    size_t final_position = left;
    for (size_t j = left + 1; j <= right; j++) {
        if (comp(arr[j], pivot)) {
            final_position++;
            std::swap(arr[final_position], arr[j]);
        }
    }
    std::swap(arr[left], arr[final_position]);
    return final_position;
}

template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T> &arr, size_t left, size_t right, Compare comp = Compare()) {
    if (comp(left, right)) {
        size_t division = Partition(arr, left, right);
        Sort(arr, left, division - 1);
        Sort(arr, division + 1, right);
    }
}

template <typename T>
std::vector<T> ReadInput() {
    size_t input;
    std::cin >> input;
    std::vector<T> arr(input);
    for (auto &i : arr) {
        std::cin >> i;
    }
    return arr;
}

void PrintVector(const std::vector<int> &arr) {
    for (auto &i : arr) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> arr = ReadInput<int>();
    Sort(arr, 0, arr.size() - 1);
    PrintVector(arr);
    return 0;
}
