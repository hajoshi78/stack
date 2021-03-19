/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on March 18, 2021, 7:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Interval{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2){
    return (i1.start <i2.start);
}
void printSorted(Interval arr[], int n){
    for( int i=0; i< n;i++){
        cout<< "("<<arr[i].start<<","<<arr[i].end<<")"<<" ";
    }  
    cout<<endl;
}
vector<Interval> mergeIntervals(Interval arr[], int n){
    vector<Interval> result;
    if( n>0){

        stack<Interval> st;
        sort(arr, arr+n, compareInterval);
        printSorted(arr, n);
        st.push(arr[0]);

        for(int i=1;i<n;i++){
            Interval stTop = st.top();
            if(arr[i].end <= stTop.end){
                continue;
            }
            //merging overlapped intervals
            else if(arr[i].start> stTop.start && arr[i].start <= stTop.end){
                st.pop();
                stTop.end = arr[i].end;
                st.push(stTop);
            }
            //if not overlapping with top of the stack push it to the stack
            else if(arr[i].start >stTop.end){
                st.push(arr[i]);
            }
        }
           
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {
    Interval arr[]={{1,3},{0,2},{9,10},{8,10},{4,5},{5,7},{2,6}};
  
    vector<Interval> result;
    
    result = mergeIntervals(arr,7);
    cout<< "[";
    for( auto x:result){
        Interval i = x;
        cout<< "("<<i.start<<","<<i.end<<")"<<" ";
    }
    cout<< "]";
    return 0;
}

