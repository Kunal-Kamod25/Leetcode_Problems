class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;

        // Walk UP
        while (i + 1 < n && arr[i] < arr[i + 1]) i++;

        // Peak can't be first or last
        if (i == 0 || i == n - 1) 
        return false ;

        // Walk Down
        while (i + 1 < n && arr[i] > arr[i + 1]) i++;
        return i == n - 1 ;
    }
};