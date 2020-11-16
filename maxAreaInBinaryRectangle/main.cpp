/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 16, 2020, 8:14 AM
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int* combineData(int arr[4][4], int rows, int cols, int currentRow, int* previousRowMAHValues){
    int * result = new int(cols);
    for(int i=0;i<cols; i++){
        if(arr[currentRow][i] == 0){
            result[i]=0;
        }
        else{
            result[i]= arr[currentRow][i]+ previousRowMAHValues[i];
        }
    }
    return result;
}
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
int getMAH(int *arr, int n ){
    vector<int> nsrIndexes = getNSRIndexes(arr, n);
    vector<int> nslIndexes = getNSLIndexes(arr, n);
    
    int maxArea = 0;
    for( int i=0; i<n;i++){
        int areaContributedByIndexI = ((nsrIndexes[i]- nslIndexes[i] -1)* arr[i]);
        //cout <<areaContributedByIndexI<<","<<"\t";
        if(areaContributedByIndexI> maxArea){
            maxArea = areaContributedByIndexI;
        }
    }
    return maxArea;
}

int* getMAHIntermediate(int arr[4][4], int rows, int cols, int currentRow, int* previousRowMAHValues, int& mahValue){
    
    previousRowMAHValues = combineData(arr, rows, cols, currentRow, previousRowMAHValues);
    mahValue = getMAH(previousRowMAHValues,cols);
    return previousRowMAHValues;
}


int getMaxAreaInBinaryMatrix(int arr[4][4], int rows, int cols){
    int maxArea= 0;
    vector<int> mahValuesForRows;
    int *mahIntermediate=NULL;
    mahIntermediate = new int(cols);
    for(int i=0;i<cols;i++){
        mahIntermediate[i]=0;
    }
    int mahValue=0;
    int maxMahValue =0;
    for(int i=0; i< rows;i++){
        mahIntermediate= getMAHIntermediate(arr, rows,cols,i,mahIntermediate,mahValue);
        if(mahValue>maxMahValue){
            maxMahValue = mahValue;
        }
    }
    
    return maxMahValue;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int array[4][4]={{1,0,0,0},
                     {1,1,1,0},
                     {1,1,1,1},
                     {1,1,1,1}
                };
    int maxArea = getMaxAreaInBinaryMatrix(array,4,4);
    cout <<"Max Area is "<<maxArea;
    return 0;
}


