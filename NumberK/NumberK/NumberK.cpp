#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> sort(vector<int> temp) {
    vector<int> sorted = temp;
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sorted[j] < sorted[i]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    for (int k = 0; k < sorted.size(); k++) {
        std::cout << sorted[k] << " ";
    }
    std::cout << "\n";

    return sorted;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            temp.push_back(array[j]);
        }
        temp = sort(temp);
        answer.push_back(temp[commands[i][2] - 1]);
    }

    return answer;
}

void main() {

    int nums[] = {1, 5, 2, 6, 3, 7, 4};
    vector<int> array;
    for (int i = 0; i < 7; i++) {
        array.push_back(nums[i]);
    }

    vector<vector<int>> commands = { {2, 5, 3} };
    vector<int> answer = solution(array, commands);

    std::cout << "answer : " << answer[0];

}