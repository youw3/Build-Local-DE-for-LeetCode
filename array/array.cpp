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


int gcd(int a, int b) {
    if(a<b) {
        swap(a,b);
    }
    while(b) {
        int c = a;
        a = b;
        b = c%b;
    }
    return a;
}

//add your function of array

int main() {
   cout<<gcd(20, 12);
}