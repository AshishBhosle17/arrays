// PASCAL TRIANGLE

vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n)
{

    // Write your code here.

    vector<vector<int>> ans;
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

// Majority Elements (n / 3 times)

vector<int> majorityElement(vector<int> v)
{
    // Write your code here
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;

        else
        {
            cnt1--, cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }
    int mini = (int)(v.size() / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);

    if (cnt2 >= mini)
        ls.push_back(el2);
    sort(ls.begin(), ls.end());
    return ls;
}

// 3- SUM Problem

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

// 4 - SUM problem (GOOGLE)

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Write your code here
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}

// Subarrays with sum XOR k

#include <bits/stdc++.h>
int subarraysWithSumK(vector<int> a, int k)
{
    // Write your code here
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++; //{0,1}
    int cnt = 0;

    for (int i = 0; i < a.size(); i++)
    {
        xr = xr ^ a[i];
        // k

        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

// Merge All Overlapping Intervals

#include <vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    // Write your code here.

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

//  Merge Two Sorted Arrays Without Extra Space

#include <bits/stdc++.h>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // Write your code here.

    int left = a.size() - 1;
    int right = 0;
    int n = a.size();
    int m = b.size();

    while (left >= 0 && right < b.size())
    {
        if (a[left] >= b[right])
        {
            swap(a[left], b[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// Missing And Repeating Numbers

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    long long n = a.size();
    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - Sn; // x-y
    long long val2 = S2 - S2n;
    val2 = val2 / val1; // x+y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

// COUNT INVERSIONS / No. of Inversions

int merge(vector<int> &a, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;      // left halve pointer
    int right = mid + 1; // right halve pointer
    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        // right is smaller
        else
        {
            temp.push_back(a[right]);

            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {

        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    // transferring back to a
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
    return cnt;
}
int ms(vector<int> &a, int low, int high)
{

    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;

    cnt += ms(a, low, mid);          // left halve
    cnt += ms(a, mid + 1, high);     // right halve
    cnt += merge(a, low, mid, high); // merging both

    return cnt;
}
int numberOfInversions(vector<int> &a, int n)
{
    // Write your code here.
    return ms(a, 0, n - 1);
}

// REVERSE PAIRS

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);        // left half
    cnt += mergeSort(arr, mid + 1, high);   // right half
    cnt += countPairs(arr, low, mid, high); // Modification
    merge(arr, low, mid, high);             // merging sorted halves
    return cnt;
}

int team(vector<int> &skill, int n)
{
    // Write your code here.
    return mergeSort(skill, 0, n - 1);
}

// Maximum Product Sub-Array

#include <vector>
#include <bits/stdc++.h>

using namespace std;
int subarrayWithMaxProduct(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}