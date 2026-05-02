#include <iostream>
#include <algorithm>
using namespace std;

class BitonicArray {
private:
    int comp;
    int swaps;
public:
    BitonicArray() {
        comp = 0;
        swaps = 0;
    }
    void BubbleSort(int arr[], int start, int end) {
        for (int i = start; i < end; i++) {
            for (int j = start; j < end - (i - start); j++) {
                comp++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }
    }
    void SelectionSort(int arr[], int start, int end) {
        for (int i = start; i <= end; i++) {
            int maxindex = i;
            for (int j = i + 1; j <= end; j++) {
                comp++;
                if (arr[j] > arr[maxindex]) {
                    maxindex = j;
                }
            }
            if (maxindex != i) {
                swap(arr[i], arr[maxindex]);
                swaps++;
            }
        }
    }
    int linearSearch(int arr[], int size, int target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target)
                return i;
        }
        return -1;
    }

    void solve(int arr[], int size, int target) {
        comp = 0;
        swaps = 0;

        int mid = size / 2;

        BubbleSort(arr, 0, mid - 1);
        SelectionSort(arr, mid, size - 1);

        cout << "Bitonic array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int index = linearSearch(arr, size, target);

        if (index != -1)
            cout << "Found at index: " << index << endl;
        else
            cout << "Not found" << endl;

        cout << "Comparisons: " << comp << endl;
        cout << "Swaps: " << swaps << endl;
        cout << "----------------------" << endl;
    }
};
int main() {
    BitonicArray obj;

    int arr1[] = {1, 5, 9, 7, 3};
    obj.solve(arr1, 5, 9);

    int arr2[] = {4, 2, 8, 6, 1};
    obj.solve(arr2, 5, 2);

    int arr3[] = {3, 7, 2, 9, 5};
    obj.solve(arr3, 5, 5);

    int arr4[] = {10, 3, 6, 2, 8};
    obj.solve(arr4, 5, 100);

    int arr5[] = {2, 4, 4, 6, 3, 3, 1};
    obj.solve(arr5, 7, 4);

    return 0;
}
//time complexity:O(n**2)+O(n**2)+O(n)=O(n**2)(**=power)
// Array is divided into two halves:
// Left half sorted ascending using Bubble Sort
// Right half sorted descending using Selection Sort