/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 15, 2020, 6:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
 * 
 */

vector<int> getNSLIndexes(int arr[], int size){
    stack<pair<int,int>> st;
    vector<int> result;
    
    for( int i = 0; i<size; i++){
        if(st.empty()){
            result.push_back(-1);
        }
        else{
            if(st.top().first < arr[i]){
                result.push_back(st.top().second);
            }
            else{
                while(!st.empty()&& st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    result.push_back(-1);
                }
                else{
                    result.push_back(st.top().second);
                }
            }    
        }
        st.push(make_pair(arr[i], i));
    }
    return result;
}

vector<int> getNSRIndexes(int arr[], int size){
    stack<pair<int,int>> st; //first-> element value , second-> index of that element
    vector<int> result; //index of the NSR 
    
    for( int i = size-1; i>=0; i--){
        if(st.empty()){
            result.push_back(size);
        }
        else{
            if(st.top().first < arr[i]){
                result.push_back(st.top().second);
            }
            else{
                while(!st.empty()&& st.top().first >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    result.push_back(size);
                }
                else{
                    result.push_back(st.top().second);
                }
            }
        }
        st.push(make_pair(arr[i], i));
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int maxAreaofHistogram(int arr[], int size){
    vector<int> nsrIndexes;
    vector<int> nslIndexes;
    
    vector<int> area;
    
    nsrIndexes = getNSRIndexes(arr, size);
    for( auto x: nsrIndexes){
        cout <<x<<"," <<"\t";
    }
    cout <<endl;
    nslIndexes = getNSLIndexes(arr, size);
    for( auto x: nslIndexes){
        cout <<x<<"," <<"\t";
    }
    cout <<endl;
    int maxArea = 0;
    for( int i=0; i<size;i++){
        int areaContributedByIndexI = ((nsrIndexes[i]- nslIndexes[i] -1)* arr[i]);
        cout <<areaContributedByIndexI<<","<<"\t";
        if(areaContributedByIndexI> maxArea){
            maxArea = areaContributedByIndexI;
        }
    }
    return maxArea;
}
int main(int argc, char** argv) {
    int arr[]={2,4,3,5,2,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maxHistArea = maxAreaofHistogram(arr,size);
    cout << endl<<"Max area of the Historgram is : "<< maxHistArea;
    return 0;
}

