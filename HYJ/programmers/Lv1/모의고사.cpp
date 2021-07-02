#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> one_pattern{ 1,2,3,4,5 };
    vector<int> two_pattern{ 2,1,2,3,2,4,2,5 };
    vector<int> three_pattern{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> counts(3, 0);
    for (int i = 0; i < answers.size(); i++) {

        if (answers[i] == one_pattern[i % one_pattern.size()]) counts[0]++;
        if (answers[i] == two_pattern[i % two_pattern.size()]) counts[1]++;
        if (answers[i] == three_pattern[i % three_pattern.size()]) counts[2]++;
    }
    int m = 0;

    for (int i = 0; i < counts.size(); i++) {
        m = max(m, counts[i]);
    }

    for (int i = 0; i < counts.size(); i++) {
        if (m == counts[i]) answer.push_back(i + 1);
    }


    return answer;
}