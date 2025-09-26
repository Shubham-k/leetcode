class Solution {
public:
    void reverseAnArray(vector<int>& arr, int low, int high) {
        while (low < high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int sizeOfArray = nums.size();
        int numberOfRotations = k % sizeOfArray;
        reverseAnArray(nums, sizeOfArray - numberOfRotations, sizeOfArray - 1);
        reverseAnArray(nums, 0, sizeOfArray - (numberOfRotations + 1));
        reverseAnArray(nums, 0, sizeOfArray - 1);
    }
};