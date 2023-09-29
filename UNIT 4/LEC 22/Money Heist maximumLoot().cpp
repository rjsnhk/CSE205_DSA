#include <iostream>
#include <vector>

int maximumLootHelper(const std::vector<int>& houses, int start, int end) {
    if (start > end) {
        return 0;
    }

    int robCurrent = houses[start] + maximumLootHelper(houses, start + 2, end);
    int skipCurrent = maximumLootHelper(houses, start + 1, end);

    return std::max(robCurrent, skipCurrent);
}

int maximumLoot(const std::vector<int>& houses) {
    int n = houses.size();
    if (n == 0) {
        return 0;
    }

    return maximumLootHelper(houses, 0, n - 1);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> houses(n);
    for (int i = 0; i < n; i++) {
        std::cin >> houses[i];
    }

    int maxLoot = maximumLoot(houses);
    std::cout << maxLoot << std::endl;

    return 0;
}

