#include <iostream>
#include <vector>

using namespace std;

int binarySearchFirst(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching on the left side
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int binarySearchLast(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching on the right side
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = binarySearchFirst(nums, target);
    int last = binarySearchLast(nums, target);

    return {first, last};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);

    cout << "First Position: " << result[0] << endl;
    cout << "Last Position: " << result[1] << endl;

    return 0;
}
