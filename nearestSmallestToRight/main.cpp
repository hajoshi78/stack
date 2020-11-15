/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 15, 2020, 12:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <valarray>

using namespace std;

vector<pair<int,int>> getNearestSmallestToRight(int arr[], int size){
    stack<pair<int,int>> st; //first-> value, second-> index
    vector<pair<int,int>> result;//first-> value, second-> index
    
    for(int i= size-1; i>=0; i--){
      if(st.empty()){
          result.push_back(make_pair(-1,size));
      }  
      else{
          if(st.top().first <arr[i]){
              result.push_back(st.top());
          }
          else{
              while(!st.empty()&& st.top().first> arr[i]){
                  st.pop();
              }
              if(st.empty()){
                  result.push_back(make_pair(-1,size));
              }
              else{
                  result.push_back(st.top());
              }
          }
      }
      st.push(make_pair(arr[i],i));
    }
    reverse(result.begin(), result.end());
    return result; 
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,3,2,4,6,5,7,3};
    vector<pair<int,int>> result = getNearestSmallestToRight(arr,8);
    for( auto x: result){
        cout <<"["<<x.first<<","<<x.second<<"]"<<"\t";
        //cout <<"["<<x.first<<"]"<<"\t";
    }
    return 0;
}

