    // Bitonic array is an array having strictly increasing order upto an element and then having strictly
    // decreasing order. It is also called Mountain array.

    // Program to find element in a bitonic array
    // T.C.: O(log n)
    // S.C.: O(1)
    #include <iostream>
    #include <vector>
    using namespace std;

    int findPeakIndex (vector<int> vect, int size) { // find index of peak element
        int lo = 0, hi = size-1;
        int mid = lo + (hi - lo)/2;

        while (lo < hi) {
            if (mid == size-1 || vect[mid] > vect[mid+1]) {
                hi = mid;
            }
            else if (mid == 0 || vect[mid] > vect[mid-1]) {
                lo = mid+1;
            }
            mid = lo + (hi - lo)/2;
        }
        return lo;
    }

    int leftPart (vector<int> vect, int target, int hi) { // search element in left part
        int lo = 0;
        int mid = lo + (hi - lo)/2;
        while (lo <= hi) {
            if (vect[mid] == target) {
                return mid;
            }
            else if (vect[mid] > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
            mid = lo + (hi - lo)/2;
        }
        return -1;
    }

    int rightPart (vector<int> vect, int target, int lo) { // search element in right part
        int hi = vect.size()-1;
        int mid = lo + (hi - lo)/2;
        while (lo <= hi) {
            if (vect[mid] == target) {
                return mid;
            }
            else if (vect[mid] < target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
            mid = lo + (hi - lo)/2;
        }
        return -1;
    }

    int findElement(vector<int> vect, int size, int target) {
        // DRIVER CODE
        // find peak of array
        int peak = findPeakIndex (vect, size);
        // compare peak element with target
        if (target > vect[peak]) {return -1;}
        else if (target == vect[peak]) {return peak;}
        // find element in increasing/decreasing sequence
        else {
            int leftIndex = leftPart(vect, target, peak);
            if (leftIndex != -1) {
                return leftIndex;
            }
            else {
                return rightPart(vect, target, peak);
            }
        }
        return 0;
    }

    int main () {
        vector<int> numvect;
        int num, target;
        cin>>num;
        cin>>target;
        for (int i = 0; i < num; i++) {
            int temp;
            cin>>temp;
            numvect.push_back(temp);
        }
        cout<<findElement(numvect, num, target);
        return 0;
    }
