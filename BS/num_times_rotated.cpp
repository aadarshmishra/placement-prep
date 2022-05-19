class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int start = 0, end = n - 1;
	    while (start < end) {
	        int mid = start + (end - start) / 2;
	        if (arr[mid] > arr[end]) start = mid + 1;
	        else end = mid;
	    }
	    return start;
	}
};