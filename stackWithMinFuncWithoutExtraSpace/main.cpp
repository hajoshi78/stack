/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 17, 2020, 12:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;


//while pushing 
//    2X - ME
//While Popping
//   2ME - top 

class stackWithMinFuncWithoutExtraSpace{
private:
    int minElem;
    stack<int> dataStack;
public:
    stackWithMinFuncWithoutExtraSpace(){
        minElem=-1;
    }
    void push(int value){
        if(dataStack.empty()){
            dataStack.push(value);
            minElem = value;
        }
        else{
            if(value>= minElem){
                dataStack.push(value);
            }
            else{
                dataStack.push(2*value - minElem);
                minElem = value;
            }
        }
    }
    void pop(){     
        if(dataStack.empty()){
            minElem = -1;
        }
        else{
            if(dataStack.top()>= minElem){
                dataStack.pop();
            }
            else{
                minElem = 2*minElem - dataStack.top() ;
                dataStack.pop();
            }
            
            if(dataStack.empty()){
                minElem = -1;
            }
        }

    }
    int top(){
        if( dataStack.empty()){
            return -1;
        }
        else{
            if(dataStack.top()>=minElem){
                return dataStack.top();
            }
            else{
                return minElem;
            }
        }
    }
    int min(){
        return minElem;
    }
};


/*
 * 
 */
int main(int argc, char** argv) {
    stackWithMinFuncWithoutExtraSpace st;
    st.push(5);
    cout<<"Min Elem after pushing 5 into the stack is " <<st.min()<<endl;
    st.push(7);
    cout<<"Min Elem after pushing 7 into the stack is " <<st.min()<<endl;
    st.push(3);
    cout<<"Min Elem after pushing 3 into the stack is " <<st.min()<<endl;
    
    st.pop();
    cout<<"Min Elem after popping 3 from the stack is " <<st.min()<<endl;

    st.pop();
    cout<<"Min Elem after popping 7 from the stack is " <<st.min()<<endl;

    st.push(1);
    cout<<"Min Elem after pushing 1 into the stack is " <<st.min()<<endl;
    
    
    st.pop();
    cout<<"Min Elem after popping 1 from the stack is " <<st.min()<<endl;
    
    
    st.pop();
    cout<<"Min Elem after popping 5 from the stack is " <<st.min()<<endl;
    return 0;
}

