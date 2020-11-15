/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 15, 2020, 3:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int,int>> getNearestSmallestToLeft(int arr[], int size){
    vector<pair<int,int>> result;
    stack<pair<int,int>> st;
    for(int i=0;i<size;i++){
        if(st.empty()){
            result.push_back(make_pair(-1,-1));
        }
        else{
            if(st.top().first< arr[i]){
                result.push_back(st.top());
            }
            else{
                while(!st.empty()&& st.top().first>arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    result.push_back(make_pair(-1,-1));
                }
                else if(st.top().first< arr[i]){
                    result.push_back(st.top());                    
                }
            }
        }
        st.push(make_pair(arr[i],i));
    }
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,3,2,4,6,5,7,3};
    vector<pair<int,int>> result = getNearestSmallestToLeft(arr,8);
    for( auto x: result){
        cout <<"["<<x.first<<","<<x.second<<"]"<<"\t";
    }
    return 0;
}

