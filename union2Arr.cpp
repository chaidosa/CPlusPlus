#include <bits/stdc++.h>
using namespace std;

void find_union(vector<int> v1, int n1, vector<int> v2, int n2){

    std::map<int, int> m;

    for(int i = 0; i < n1; i++){
        if(m[v1[i]] == 0)
            m[v1[i]]++;
    }

    for(int i = 0; i < n2; i++){
        if(m[v2[i]] == 0){
            m[v2[i]]++;
        }
    }

    cout << m.size();

}

int main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
    #endif
    
    int n1, n2;
    cin >> n1 >>n2;

    std::vector<int> v1(n1);
    std::vector<int> v2(n2);    

    for(int i=0; i < n1; i++){
        int temp;
        cin >> temp;
        v1[i] = temp;
    }

    for(int i=0; i < n2; i++){
        int temp;
        cin >> temp;
        v2[i] = temp;
    }

    find_union(v1, n1, v2, n2);

    return 0;

}



