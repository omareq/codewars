#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <int> Pendulum (vector <int> values)
{
    // Your Code is Here .. Enjoy !!

    int middleIndex;
    bool sizeIsOdd = values.size() % 2;
    if(sizeIsOdd) {
        middleIndex = (values.size() + 1)/2 - 1;
    } else {
        middleIndex = values.size()/2 - 1;
    }
    cout << "Size(): " << values.size() << " Middle Index: " << middleIndex;
    cout << "\n";

    vector<int> answer = values;
    sort(values.begin(), values.end());

    bool goingRight = true;
    int leftIndex = middleIndex - 1;
    int rightIndex = middleIndex + 1;

    answer[middleIndex] = values[0];
    for(int i = 1; i < values.size(); i++) {
        // cpu should be able to predict alternating pattern for large vectors
        if(goingRight) {
            answer[rightIndex] = values[i];
            rightIndex++;
        } else{
            answer[leftIndex] = values[i];
            leftIndex--;
        }
        goingRight = !goingRight;
    }

    return answer;
}

int main(int argc, char** argv) {
    vector<int> answer = Pendulum(vector<int>{4, 10, 9});

    cout << "Expected (10, 4, 9)\n";
    cout << "(";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ", ";
    }
    cout << ")\n";

    answer = Pendulum(vector<int>{8, 7, 10, 3});
    cout << "Expected (8, 3, 7, 10)\n";
    cout << "(";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ", ";
    }
    cout << ")\n";
}