#include <iostream>

int main()
{
    int scores[5] = {50, 60, 70, 80, 100};

    // int size_array = sizeof(scores) / sizeof(scores[0]);
    int size_array = std::size(scores);
    
    int sum = 0;
    for (int i = 0; i < size_array; i++) {
        sum += scores[i];
    }

    float mean = (float)sum / size_array;

    std::cout << "Mean score : " << mean << std::endl;
}