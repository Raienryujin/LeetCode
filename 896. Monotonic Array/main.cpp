#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int>& A) {
    int increasing = 0;

    for (int i = 1; i < A.size(); ++i) {
        if (A[i] > A[i - 1]) {
            if (increasing == 0) {
                increasing = 1;
            } else if (increasing == -1) {
                return false;
            }
        } else if (A[i] < A[i - 1]) {
            if (increasing == 0) {
                increasing = -1;
            } else if (increasing == 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::vector<int> arr = {1, 2, 2, 3};
    bool result = isMonotonic(arr);

    if (result) {
        std::cout << "The array is monotonic." << std::endl;
    } else {
        std::cout << "The array is not monotonic." << std::endl;
    }

    return 0;
}
