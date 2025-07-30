#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> odds() {
    return { 1, 3, 5, 7, 9 };
} //list initialization func

//Auto data type
auto a1 = 10;
auto a2 = 3.14f;
auto a3 = "hello";
auto a4 = "hello"s;
auto a5 = sqrt(2.0);
auto a6 = odds();
auto a7 = a6.begin();
auto lamda = [](int x) { return x * 2; };

// using type_definition
using uchar = unsigned char;
using da10 = double[10];
using func = void(*)(int);
using pis = pair<int, string>;

template <typename T>
using matrix1d = vector<T>;

struct Person
{
    string name;
    int age;
};


int main()
{
    //chrono library
    auto start = chrono::system_clock::now();
    
    // Range-Based for function
    vector<int> numbers {10, 20, 30};
    for (int n : numbers)
        cout << n << endl; //deep copy in n
    for (auto& n : numbers)
        cout << n << endl; // ref to numbers element
    string strs[] {"I", "love", "you"};
    for (const auto& s : strs)
        cout << s << " ";


    //Lamda Expression
    auto square = [] (double a) { return a * a; };
    cout << "square : (1.414) = " << square(1.414) << endl;

    vector<Person> students;
    students.push_back({"Kim", 20});
    students.push_back({"Lee", 30});
    students.push_back({"Park", 24});
    students.push_back({"Choi", 40});

    sort(students.begin(), students.end(), [] (const Person& p1, const Person& p2) {
        return p1.age < p2.age;
    });

    for (const auto& p : students)
        cout << p.name << " : " << p.age << endl;

    

    //chrono library
    auto end = chrono::system_clock::now();
    auto mesc = chrono::duration<double>(end - start).count() * 1000;
    cout << "Elapsed time : " << mesc << "ms." << endl;
}