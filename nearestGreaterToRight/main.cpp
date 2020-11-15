/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 14, 2020, 9:30 PM
 */

#include <cstdlib>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

vector< pair <int,int> >  getNearestGreaterToRight(int arr[], int sizeOfArray){
    vector<pair<int,int> > vect;  // first -> value and  second-> index
    
    stack<pair<int,int> > s; // first -> value ,  second ->index
    
    for( int i= sizeOfArray -1;i>=0;i--){
        if(s.empty()== true){
            vect.push_back(make_pair(-1,sizeOfArray));
        }
        else if(s.empty()== false){
            if(arr[i]<=s.top().first){
                vect.push_back(s.top());
            }
            else{
                while(s.empty()== false && arr[i]>=s.top().first){
                    s.pop();
                }
                if(s.empty() == true){
                    vect.push_back(make_pair(-1,sizeOfArray));
                }
                else{
                    vect.push_back(s.top());
                }
            }
        }
        s.push(make_pair(arr[i],i));
    }
    reverse(vect.begin(), vect.end());
    return vect;
}

int main(int argc, char** argv) {

    int arr[]={1,3,2,4,6,5,7,3};
    vector<pair<int,int>> result = getNearestGreaterToRight(arr,8);
    for( auto x: result){
        cout <<"["<<x.first<<","<<x.second<<"]"<<"\t";
    }
    return 0;
}

