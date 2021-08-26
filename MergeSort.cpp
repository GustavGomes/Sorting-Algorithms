#include <iostream>
#include <vector>

template <typename T>
struct CustomComparator {
    bool operator()(const T &lhs, const T &rhs) {
        return (lhs < rhs);
    }
};

template <typename T, typename Compare = CustomComparator<T>>
void Merge(std::vector<T> &array, size_t first_begin, size_t first_end, size_t second_begin,
           size_t second_end, Compare comp = Compare()) {
    std::vector<T> first_array(second_begin - first_begin);
    std::vector<T> second_array(second_end - first_end);

    for (size_t i = 0; i < first_array.size(); i++) {
        first_array[i] = array[first_begin + i];
    }
    for (size_t j = 0; j < second_array.size(); j++) {
        second_array[j] = array[first_end + 1 + j];
    }

    size_t i = 0, j = 0;
    size_t k = first_begin;
    while (i < first_array.size() && j < second_array.size()) {
        if (first_array[i] <= second_array[j]) {
            array[k] = first_array[i];
            i++;
        } else {
            array[k] = second_array[j];
            j++;
        }
        k++;
    }
    while (i < first_array.size()) {
        array[k] = first_array[i];
        i++;
        k++;
    }
    while (j < second_array.size()) {
        array[k] = second_array[j];
        j++;
        k++;
    }
}

template <typename T, typename Compare = CustomComparator<T>>
void MergeSort(std::vector<T> &array, size_t begin, size_t end, Compare comp = Compare()) {
    if (begin >= end) {
        return;
    }
    size_t m = (begin + end) / 2;
    MergeSort(array, begin, m);
    MergeSort(array, m + 1, end);
    Merge(array, begin, m, m + 1, end);
}

template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T> &array) {
    MergeSort(array, 0, array.size() - 1);
}

template <typename T>
std::vector<T> ReadInput() {
    size_t input;
    std::cin >> input;
    std::vector<T> array(input);
    for (auto &i : array) {
        std::cin >> i;
    }
    return array;
}

template <typename T>
void PrintVector(const std::vector<T> &array) {
    for (auto &i : array) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> arr = ReadInput<int>();
    Sort(arr);
    PrintVector(arr);
    return 0;
}
