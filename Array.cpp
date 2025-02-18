#include <iostream>
#include <vector>
using namespace std;

vector<int> beautifulArray(int n) {
    if (n == 1) return {1};

    vector<int> odd = beautifulArray((n + 1) / 2);  
    vector<int> even = beautifulArray(n / 2);       
    
    vector<int> result;
    for (int x : odd) result.push_back(2 * x - 1);  
    for (int x : even) result.push_back(2 * x);     
    
    return result;
}

int main() {
    int n = 5;
    vector<int> result = beautifulArray(n);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
