#include "../class/BST.h"
#define SIZE 100

int getLength(int arr[]) {
    return sizeof(arr[0]) / sizeof(arr);
}

BST<int> convertArrayToBST(int arr[]) {
    BST<int> returnBST;
    for(int i = 0; i < getLength(arr);i++) {
        returnBST.insert(arr[i]);
    }
    return returnBST; // return the created BST
}

// Your First C++ Program

int main() {
    int arr[SIZE] = {1,3,4,2,2};
    convertArrayToBST(arr);
    return 0;
}
