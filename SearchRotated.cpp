#include<iostream>
#include<vector>
using namespace std;
class SearchRotated {
private:
    int comp ;
public:
    SearchRotated() {
        comp=0;
    }
    int getComparisons() {
        return comp;
    }
    int SearchROTA(vector<int>&arr,int size,int target) {
        int left=0,right=size-1;
        while (left<=right) {
            int mid=(left+right)/2;
            comp++;
            if (arr[mid]==target) {
                return mid;
            }
            bool leftMid = (arr[left] == arr[mid]);  // comparison 1
            comp++;

            bool rightMid = (arr[right] == arr[mid]); // comparison 2
            comp++;

            if (leftMid && rightMid) {
                left++;
                right--;
            }
            else if (arr[left]<=arr[mid]) {
                comp+=2;
                if (arr[left]<=target&&target<arr[mid]) {
                    right=mid-1;
                }else {
                    left=mid+1;
                }

            }else {
                comp+=2;
                if (arr[mid]<target&&target<=arr[right]) {
                    left=mid+1;
                }else {
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {

    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
  vector<int>arr(size);
    cout<<"Enter element of rotated sorted array \n";
    for (int i=0;i<size;i++) {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element to be Searched:";
    cin>>target;
    SearchRotated obj;
    int result=obj.SearchROTA(arr,size,target);
    if (result!=-1) {
        cout<<"Found at index "<<result<<endl;

    }else {
        cout<<" Not Found"<<endl;
    }
    cout<<"Number of Comparisons:"<<obj.getComparisons()<<endl;
    return 0;

}
/*
 Time complexity:
 Best Case: o(1)
 When the target is found at arr[mid]in the first comparison
 Average case:O(log n)
 Because the Search space is divided in half each time
 Worst case:O(n)
 when there are many duplicate elements,forcing the algorithm to shrink the search
 range linearly insted of dividing it

 */