#include <iostream>
#include <vector>
using namespace std;

class SearchRotated
{
private:
    int comp;

public:
    SearchRotated() { comp = 0; }

    void reset() { comp = 0; }

    int getComparisons() { return comp; }

    int SearchROTA(vector<int> &arr, int size, int target)
    {
        reset();
        int left = 0, right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // comparison 1
            comp++;
            if (arr[mid] == target)
                return mid;

            // duplicates handling
            comp++;
            if (arr[left] == arr[mid])
            {

                comp++;
                if (arr[right] == arr[mid])
                {
                    left++;
                    right--;
                    continue;
                }
            }

            comp++;
            if (arr[left] <= arr[mid])
            {
                // left half sorted

                comp++;
                if (arr[left] <= target)
                {

                    comp++;
                    if (target < arr[mid])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {

                comp++;
                if (arr[mid] < target)
                {

                    comp++;
                    if (target <= arr[right])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter elements of rotated sorted array:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    SearchRotated obj;

    int target;
    cout << "Enter the element to be Searched: ";
    cin >> target;

    int result = obj.SearchROTA(arr, size, target);

    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not Found" << endl;

    cout << "Number of Comparisons: " << obj.getComparisons() << endl;

    return 0;
}

/*
Time Complexity:
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(n) (due to duplicates)
*/