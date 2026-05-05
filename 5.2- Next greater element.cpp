#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class NextGreaterElement {
private:
    vector<int> nums;
    vector<int> result;

    void compute() {
        int n = nums.size();
        result.assign(n, -1);
        stack<int> stack;

        for (int i = 0; i < 2 * n; ++i) {
            int currentIndex = i % n;

            while (!stack.empty() && nums[currentIndex] > nums[stack.top()]) {
                result[stack.top()] = nums[currentIndex];
                stack.pop();
            }

            if (i < n) {
                stack.push(currentIndex);
            }
        }
    }

public:
    NextGreaterElement(const vector<int>& inputNums) : nums(inputNums) {
        compute();
    }

    vector<int> getResult() const {
        return result;
    }

    void printResult() const {
        cout << "Output: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
};

int main() {
    NextGreaterElement case1({ 5, 5, 5 });
    case1.printResult();

    NextGreaterElement case2({ 1, 2, 3, 4 });
    case2.printResult();

    NextGreaterElement case3({ 3, 1, 2 });
    case3.printResult();

    return 0;
}
    //Time Complexity: O(n) - Each element is pushed and popped at most once
    //Space Complexity: O(n) - The stack can hold up to n indices in the worst case

