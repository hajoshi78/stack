/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 15, 2020, 5:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> getStockSpan(int arr[], int size){
    vector<pair<int,int>> nearestGreaterToLeft;
    stack<pair<int,int>> st;
    
    for(int i=0;i<size;i++){
        if(st.empty()){
            nearestGreaterToLeft.push_back(make_pair(-1,-1));
        }
        else{
            if(st.top().first > arr[i]){
                nearestGreaterToLeft.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top().first<arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nearestGreaterToLeft.push_back(make_pair(-1,-1));
                }
                else{
                    nearestGreaterToLeft.push_back(st.top());
                }
            }
        }
        st.push(make_pair(arr[i],i));
    }
    vector<int> span;
    int i=0;
    for( int i=0;i<size;i++){
        span.push_back(i- nearestGreaterToLeft[i].second);
    }
    return span;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int price[] = { 10, 4, 5, 90, 120, 80 };  
    int size = sizeof(price) / sizeof(price[0]);  
    
    vector<int> stockSpan = getStockSpan(price,size);
    
    for( auto x :stockSpan){
        cout << x<<",\t";
    }
    
    return 0;
}

