//
// Created by wei on 2018/8/23.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template <typename T>
void print_vector(vector<T>& t) {
    cout<<'[';
    for(int i=0; i<t.size()-1; ++i) {
        cout<< t[i]<< ",";
    }
    cout<<t[t.size()-1]<<']'<<endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size()+nums2.size();
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    if(len%2) {
        return nums1[(len-1)/2]+0.0;
    } else {
        return (nums1[len/2-1]+nums1[len/2]+0.0)/2;
    }
}
//add your function of array

int main() {
    vector<int> t1 = {1, 2};
    vector<int> t2 = {3, 4};
    cout<<findMedianSortedArrays(t1, t2);
}
