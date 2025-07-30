#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec1 {1, 2, 3, 4};
    cout << "Capa : " << vec1.capacity() << " | Size : " << vec1.size() << endl;

    vec1.push_back(5);
    cout << "Capa : " << vec1.capacity() << " | Size : " << vec1.size() << endl;

    vec1.push_back(6);
    cout << "Capa : " << vec1.capacity() << " | Size : " << vec1.size() << endl;
     
    vec1.insert(vec1.begin(), 0);
    cout << "Capa : " << vec1.capacity() << " | Size : " << vec1.size() << endl;

    vec1.erase(vec1.begin() + 1, vec1.begin() + 3);
    cout << "Capa : " << vec1.capacity() << " | Size : " << vec1.size() << endl;

    for (auto x : vec1) {
        cout << x << ", ";
    }
}