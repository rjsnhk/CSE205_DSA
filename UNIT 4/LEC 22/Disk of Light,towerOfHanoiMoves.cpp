#include <iostream>

void towerOfHanoiMoves(int n, char source, char destination, char auxiliary, int *total_moves) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        (*total_moves)++;
        return;
    }

    towerOfHanoiMoves(n - 1, source, auxiliary, destination, total_moves);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    (*total_moves)++;
    towerOfHanoiMoves(n - 1, auxiliary, destination, source, total_moves);
}

int main() {
    int n;
    std::cin >> n;

    int total_moves = 0;
    towerOfHanoiMoves(n, 'A', 'C', 'B', &total_moves);

    std::cout << "Total number of times the disk is moved: " << total_moves << std::endl;

    return 0;
}

