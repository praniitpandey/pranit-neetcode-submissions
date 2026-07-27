/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    unordered_map<int, int> cache;

    int getValue(MountainArray &arr, int index) {
        if (index < 0 || index >= arr.length())
            return -1e9;

        auto it = cache.find(index);
        if (it != cache.end())
            return it->second;
        return cache[index] = arr.get(index);
    }

    int searchValue(int left, int right, int target, MountainArray &arr, bool isAscending) {
        int mid = 0, midVal = 0;

        while (left <= right) {
            mid = left + (right - left)/2;
            midVal = getValue(arr, mid);

            if (target < midVal) {
                if (isAscending)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (target > midVal) {
                if (isAscending)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                return mid;
        }

        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int left = 0, right = n - 1, mid = 0;
        int a, b, c, peak;
        
        while (left <= right) {
            mid = left + (right - left)/2;

            a = getValue(arr, mid - 1);
            b = getValue(arr, mid);
            c = getValue(arr, mid + 1);

            if (a < b && b < c) {
                left = mid + 1;
            }
            else if (a > b && b > c) {
                right = mid - 1;
            }
            else if (a < b && b > c) {
                if (b == target)
                    return mid;
                peak = mid;
                break;
            }
        }

        int index1 = searchValue(0, peak - 1, target, arr, true);
        if (index1 != -1)
            return index1;
        else
            return searchValue(peak + 1, n - 1, target, arr, false);;
    }
};