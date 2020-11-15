/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 15, 2020, 11:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> getMaxLeft(int arr[], int size){
    vector<int> result;
    int currentMax = INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i]> currentMax){
            result.push_back(arr[i]) ;
            currentMax = arr[i];
        }
        else{
            result.push_back(currentMax);
        }
    }
    return result;
}


vector<int> getMaxRight(int arr[], int size){
    vector<int> result;
    int currentMax = INT_MIN;

    for(int i=size-1;i>=0;i--){
        if(arr[i]> currentMax){
            result.push_back(arr[i]);
            currentMax = arr[i];
        }
        else{
            result.push_back(currentMax);
        }
    }
    return result;
}

int getMin(int val1, int val2){
    return val1<val2? val1:val2;
}

int getRainWaterTrappedBetweenBuildings(int arr[], int size){
    int totalVolume=0;
    vector<int> maxLeft = getMaxLeft(arr,size);
    for( auto x: maxLeft){
        cout <<x<<",\t";
    }
    cout<<endl;
    vector<int> maxRight = getMaxRight(arr, size);
    for( auto x: maxRight){
        cout <<x<<",\t";
    }
    for( int i=0;i<size;i++){
        totalVolume+= getMin(maxLeft[i], maxRight[i]) - arr[i];
    }
    return totalVolume;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={3,0,0,2,0,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    for( auto x: arr){
        cout <<x<<",\t";
    }
    cout<<endl;
    int volume = getRainWaterTrappedBetweenBuildings(arr, size);
    cout <<"Volume of water is "<<volume;
    return 0;
}

