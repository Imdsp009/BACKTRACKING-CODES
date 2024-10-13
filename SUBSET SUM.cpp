//SUBSET SUM
#include <iostream>

using namespace std;
bool flag = false;

void PrintSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
    if (targetSum == 0) {
        flag = true;
        cout << "[ ";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }

    if (i == n) {
        return;
    }

    PrintSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);
    if (set[i] <= targetSum) {
        subset[subsetSize] = set[i];


        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);
    }
}

int main() {

    int set[] = {1, 2, 1};
    int sum = 3;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[100];
    cout << "Output 1:" << endl;
    PrintSubsetSum(0, n, set, sum, subset, 0);
    cout << endl;
    flag = false;
    int set2[] = {3, 34, 4, 12, 18, 27};
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    int subset2[100];
    cout << "Output 2:" << endl;
    PrintSubsetSum(0, n2, set2, sum2, subset2, 0);
    if (!flag) {
        cout << "There is no such subset";
    }

    return 0;
}
