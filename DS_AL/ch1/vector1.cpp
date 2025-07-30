/*
    operator [] : return the specific index element ref : O(1)
    front() : return the first element ref : O(1)
    back() : return the last element ref : O(1)
    push_back() : add the element to back side in array : O(1)
    emplace_back() : add the element to back side in array (not duplication/move ~ more efficiently) : O(1)
    pop_back() : delete the last element in array (not return) : O(1)
    insert() : put the element in specific spot or place : O(N)
    erase() : delete the elements in specific spot or place : O(N)
    clear() : remove all elements : O(1)
    size() : return to the number of elements : O(1)
    capacity() : return to the capacity of array : O(1)
    empty() : if it's empty, return the True : O(1)
    begin() / end() : iterator
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 1); 
    vector<int> v4 {10, 20, 30, 40, 50};

    vector<int> v5 = v4; // v5(v4)
    vector<int> v6(v4.begin(), v4.begin() + 3); //v4[0] ~ v[2]

    vector<vector<int>> mat1(2, vector<int>(3, 1)); // make a 2_Dim vector & initalized to 2x3
    
    vector<vector<int>> mat2 { 
        {1, 2, 3}, 
        {4, 5, 6} 
    };

    for (auto x : mat2) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
   
}