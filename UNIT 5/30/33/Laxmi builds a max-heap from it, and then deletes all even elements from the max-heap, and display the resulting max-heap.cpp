#include <iostream>
#include <vector>
#include <algorithm>

void heapify(std::vector<int>& v) {
    std::make_heap(v.begin(), v.end());
}

void removeEvenElements(std::vector<int>& v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }), v.end());
    std::make_heap(v.begin(), v.end());
}

void displayHeap(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    heapify(v);
    removeEvenElements(v);
    displayHeap(v);

    return 0;
}
