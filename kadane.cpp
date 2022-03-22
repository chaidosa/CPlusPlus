#include <bits/stdc++.h>
using namespace std;

/*
Kadane's Algorithm
    
    Initialize:
        max_so_far = INT_MIN
        max_ending_here = 0

    Loop for each element of the array
     (a) max_ending_here = max_ending_here + a[i]
     (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
     (c) if(max_ending_here < 0)
            max_ending_here = 0;
    return max_so_far;
*/
void find_MaxSum(vector<int> v1, int n1){

    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int i = 0; i < n1; i++){
        max_ending_here = max_ending_here + v1[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }

    cout << max_so_far;

}

int main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    
    int n1;
    cin >> n1;

    std::vector<int> v1(n1);  

    for(int i=0; i < n1; i++){
        int temp;
        cin >> temp;
        v1[i] = temp;
    }


    find_MaxSum(v1, n1);

    return 0;

}




