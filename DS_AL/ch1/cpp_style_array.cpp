#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> scores = {50, 60, 70, 80, 90};

    int sum = 0;
    for (int i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }

    float mean = (float) sum / scores.size();

    std::cout << "Mean score : " << mean << std::endl;
}