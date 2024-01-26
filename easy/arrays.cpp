// largest element in an Array

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int i;
    int largest =arr[0];
    for (i=0; i<n; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }

    }
    return largest;
}

// Second Largest and second smallest no. in an arr

int secondLargest (vector <int> &a, int n) {

    int largest = a[0];
    int slargest = -1;
    for (int i=1; i<n; i++){
        if (a[i]>largest){
            
            slargest = largest;
            largest = a[i];

        }
        else if (a[i]<largest && a[i]>slargest){
            slargest = a[i];
        
        }
    
    }
    return slargest;
    
}

int secondSmallest (vector <int> &a, int n) {
    
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (int i=1; i<n; i++){

        if (a[i]<smallest){
            
            ssmallest = smallest;
            smallest = a[i];

        }
        else if (a[i] != smallest && a[i]< ssmallest){
            ssmallest = a[i];
        
        }
        
    }
    return ssmallest;

}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int slargest = secondLargest(a,n);
    int ssmallest = secondSmallest (a,n);
    return {slargest, ssmallest};
}

// Sorted Arrays

int isSorted(int n, vector<int> a) {
    // Write your code here.
    int i;

    for (int i=1; i<n; i++){
        if (a[i]>= a[i-1]) {
        }
        
        else {

            return 0;
        }
        
    }
    return 1;
}

// Remove duplicates from the arr

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0;
	for (int j=0; j<n; j++){
		if (arr[i] != arr[j]){

			arr [i+1] = arr [j];
			i++;

		}
	}
	return i+1;
}

// Left rotate the arr by 1

#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    
    int temp = arr[0];
    for (int i=1; i<n; i++){
        arr [i-1] = arr [i];

    }
    arr[n-1] = temp;
    return arr;
    
}

// left rotate the arr by K elements


vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    vector<int> temp(arr.size());

    int n=arr.size();

    for(int i=0;i<n;i++){

        temp[(i+n-k)%n]=arr[i];

    }

    return temp;
}

// Move zeros in an arr to end 

vector<int> moveZeros(int n, vector<int> a) {
    
    // step 1.
    vector <int> temp;
    for(int i=0; i<n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    //step 2.
    int nz = temp.size();
    for (int i =0; i<nz; i++) {
        a[i] = temp[i];
    }

    //step 3.
    for (int i=nz; i<n; i++){
        a[i] = 0;
    }
    return a;
}

// OPTIMAL SOLUTION for the SAME

vector<int> moveZeros(int n, vector<int> a) {

    int j= -1;
    for (int i =0; i<n; i++) {
        if (a[i] == 0){
            j =1;
            break;
        }
    }
    //no non-zero numbers
    if {j== -1} return a;
    
    for (int i = j+1;i<n; i++) {
        if (a[i] != 0) {
            swap (a[i], a[j]);
            j++;
        }
    }
    return a;
}

// Linear Search - Input: ‘n’ = 5, ‘num’ = 4 
// 'arr' =  [6,7,8,4,1]

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i=0; i<num; i++) {
        if (arr[i] == num){

            return i;
        }        
    }
    return -1;
}

// Union of 2 arrays- Merging 2 sorted arr

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, 
vector < int > b) {
    // Write your code here
    
    int n1 = a.size();
    int n2 = b.size();
    int i= 0;
    int j= 0;
    vector<int> unionArr;

    while(i<n1 && j <n2) {

        if(a[i] <= b[j]) {
            if (unionArr.size() == 0 ||
            unionArr.back() != a[i]) {
                unionArr.push_back (a[i]);

            }
            i++;
                
        }
        else {
                
            if(unionArr.size() == 0 ||
            unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);

            }    
            j++;
        }
    }

    while (j<n2) {

        if (unionArr.size() == 0 || 
        unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }


    while (i<n1) {

        if(unionArr.size() == 0 || 
        unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    
    return unionArr;    
}

// Intersection of 2 sorted arr

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
	// Write your code here.
	int i=0;
	int j =0;

	vector<int> ans;
	while(i<n && j<m) {
		if (A[i] <B[j]) {
			i++;
		}
		else if  (B[j] < A[i]) {
			j++;
		}
		else {
			ans.push_back (A[i]);
			i++;
			j++;
		}
	}
	return ans;
}

// Missing number in arr using optimal sol of xor

int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    int xor1 =0, xor2 =0;
    int n= N-1; // size of arr is always N-1
    
    for (int i=0; i<n; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
    
}

// Maximum consecutive ones 

int consecutiveOnes(vector<int>& nums){
    //Write your code here.

    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++) {


        if (nums[i] == 1) {
            cnt ++;

        } else{
            cnt = 0;
        }

        maxi = max(maxi, cnt);
    }
    return maxi;
}

//Find the single element in an arr (non- repeating)

#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int xorr=0;
	for (int i=0; i< arr.size(); i++) {
		xorr = xorr ^ arr [i];
	}
	return xorr;	
}

// OR ANOTHER APPROACH 
int getSingleElement(vector<int> &arr){
	for(int i =0;i<arr.size();i=i+2){

        if(arr[i] == arr[i+1]){
            continue;
        }
        else{

            return arr[i];
		}
	}	
}

// Longest sub-arr with sum k [POSITIVE]

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left =0, right =0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size() ;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left ++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right -left +1);
        }
        right ++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}