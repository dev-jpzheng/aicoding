#include <iostream>
#include <vector>
#include <cstddef>

// 快速排序：选取基准元素，将数组划分为 <= pivot 和 > pivot 两部分，递归排序
std::size_t partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 以最后一个元素为基准
    int i = low - 1;       // i 指向“小于等于基准区”的最后一个元素

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return static_cast<std::size_t>(i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = static_cast<int>(partition(arr, low, high));
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    if (!arr.empty()) {
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, -3, 42, 0, 17};

    std::cout << "排序前: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    quickSort(arr);

    std::cout << "排序后: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
