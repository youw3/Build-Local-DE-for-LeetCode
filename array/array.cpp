//
// Created by wei on 2018/8/23.
//
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void print_vector(vector<T>& t) {
    for(int i=0; i<t.size(); ++i) {
        cout<< t[i]<< " ";
    }
}


//add your function of array

int main() {
    vector<int> t={1,2,3};
    print_vector(t);
}
