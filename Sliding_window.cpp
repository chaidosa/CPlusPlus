/**
 * @file Sliding_window.cpp
 * @author Pritesh Verma (pritesh0797@gmail.com)
 * @brief  Following program calculates the maximum element of the current window in the sliding window
 * @version 0.1
 * @date 2021-12-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<bits/stdc++.h>

using namespace std;

vector<int> find_max_of_the_window(vector<int>&V, int win_size){
    vector<int>result;

    if(V.size()==0 || win_size > V.size())
        return result;   
    

    std::deque<int> window;

    //finding max in the first window
    for(int i=0;i<win_size; ++i){
        while(!window.empty() && V[i]>=V[window.back()])
            window.pop_back();

        window.push_back(i);
    }
    result.push_back(V[window.front()]);


    for(int i = win_size; i < V.size(); ++i){
        //if current front is out of window
        while(!window.empty() && window.front() < i-win_size)
            window.pop_front();
        
        //if back element is less than current
        while(!window.empty() && V[i]>=V[window.back()])
            window.pop_back();
        
        window.push_back(i);
        result.push_back(V[window.front()]);
    }

return result;

}

int main(int argc, const char *argv[]){
    vector<int>V;
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        V.push_back(temp);
    }
    int window_size;
    cin>>window_size;
    auto result = find_max_of_the_window(V,window_size);

    if(result.size()==0){
        cout<<"Enter valid values";
        return 0;
    }

    for(int i=0;i<result.size();++i){
        cout<<result[i]<<" ";
    }

    return 0;
}