class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool top = false;
        for(int i=0; i<arr.size()-1; i++) {
            if(!top && arr[i] > arr[i+1]) {
                if(i == 0) return false;
                top = true;
            } 
            else if(arr[i] == arr[i+1]) {
                return false;
            }
            else if(top && arr[i] < arr[i+1]) {
                return false;
            }
        }
        if(!top) return false;
        return true;
    }
};