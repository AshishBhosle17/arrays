// Longest sub-arr with sum k [Positive and Negative]

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    // Write your code here
    map < long long, int> preSumMap;
    long long sum =0;
    int maxLen =0;
    for (int i =0; i<a.size(); i++){
        sum += a[i];
        if (sum == k){
            maxLen = max (maxLen, i+1);

        }
        long long rem = sum -k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int  len =i- preSumMap[rem];
            maxLen =max (maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] =i;

        }
    }
    return maxLen;
    
}

// Two sum problem

string read(int n, vector<int> book, int target)
{
    // Write your code here.it
    int left =0, right = n-1;

    sort (book.begin(), book.end());
    while (left < right) {
        int sum = book[left] + book [right];
        if (sum == target) {
            return "YES";
        }

        else if (sum < target) left++;
        else right --;
    }
    return "NO";
}

// Sort an arr pf 0s 1s and 2s

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int low =0, mid=0, high= n-1;
    while (mid <= high) {
        if (arr[mid] ==0) {
            swap (arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) {
            mid++;
            
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Majority elements in an arr

int majorityElement(vector<int> v) {
	// Write your code here
	int cnt=0;
	int el;
	for (int i=0; i<v.size(); i++){
		if (cnt==0){
			cnt =1;
			el =v[i];
		}
		else if (v[i] ==el){
			cnt++;
		}
		else{
			cnt--;
		}

	}
	int cnt1 =0;
	for (int i=0; i<v.size(); i++){
		if(v[i] == el) cnt1++;
	}
	if (cnt1 >v.size() /2) {
		return el;
	}
	return -1;
}

// Kadanes (maximum sub arr)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxi = INT_MIN;
        for (auto it : nums) {
            sum += it;
            maxi = max(sum, maxi);
            if (sum <0) sum =0;
        }
        return maxi;
                
    }
};

// buy and sale Stocks

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;

}

// longest consecutive sequence element
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

// Next Greater Permutation 

int ind =-1;
        int n =nums.size();
        for (int i= n-2 ; i>=0; i-- ) {
            if (nums[i] < nums[i+1]) {
                ind =i;
                break;
            }

        }
        if (ind ==-1) {
            reverse (nums.begin(), nums.end());
            return ;
        }
        for (int i=n-1; i>ind; i--) {
            if (nums[i] > nums[ind]) {
                swap (nums[i], nums[ind]);
                break;
            }
        }
        reverse (nums.begin() +ind +1, nums.end());
}

// Rotate the MATRIX by 90 DEGREE

#include<vector>

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n= mat.size();
	//transpose

	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++) {
			swap (mat[i][j], mat[j][i]);
		}
	}
	//reverse
	for(int i=0; i<n; i++){
		reverse(mat[i].begin(), mat[i].end());
	}
}

// 

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    
    map<int , int> mpp;
    int n = arr.size(); // size of the given array.    
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
    
}