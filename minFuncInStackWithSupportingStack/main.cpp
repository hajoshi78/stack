/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 16, 2020, 8:54 PM
 */

#include <cstdlib>
#include <stack>
#include <iostream>

using namespace std;

class StackWithMinFunc{
private:
    stack<int> supportingStack;
    stack<int> mainStack;
public:
    int top(){
        return mainStack.top();
    }
    void push(int value){
        mainStack.push(value);
        if(supportingStack.empty()|| value<supportingStack.top()){
            supportingStack.push(value);
        }
    }
    void pop(){
        if(mainStack.top()== supportingStack.top()){
            supportingStack.pop();
        }
        mainStack.pop();
        
    }
    int min(){
        if(!supportingStack.empty()){
            return supportingStack.top();
        }
        else{
            return -1;
        }
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    StackWithMinFunc stackWithMin;
    stackWithMin.push(10);
    cout <<"After Inserting 10 Min value is "<< stackWithMin.min()<<endl;
    stackWithMin.push(20);
    cout <<"After Inserting 20 Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.push(5);
    cout <<"After Inserting 5 Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.push(30);
    cout <<"After Inserting 30 Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.pop();
    cout <<"After Popping 30  Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.pop();
    cout <<"After popping 5 Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.pop();
    cout <<"After popping 20 Min value is "<< stackWithMin.min()<<endl;
    
    stackWithMin.pop();
    cout <<"After popping 10 Min value is "<< stackWithMin.min()<<endl;
    
    
    
    return 0;
}

