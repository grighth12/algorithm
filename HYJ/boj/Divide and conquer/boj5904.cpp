#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 30;
vector<int> s(SIZE, 0);

char solution(int n, int index) {
    if (index == 1) {
        if (n == 1) return 'm';
        else if (n == 2) return 'o';
        else if (n == 3) return 'o';
    }
    else {
        if (n <= s[index - 1])
        {
            //cout << "첫번째 분기" << n<< "\n";
            return solution(n, index - 1);
        }
        else if (n <= (s[index - 1] + index + 2)) {
            //cout << "두번째 분기" <<n - s[index-1] <<"\n";
            return solution(n - s[index - 1], index - 1);
        }
        else {
            //cout << "세번째 분기" <<n - (s[index-1] + index+ 2) <<"\n";
            return solution(n - (s[index - 1] + index + 2), index - 1);
        }
    }
}


int main()
{

    s[1] = 3;
    for (int i = 2; i < SIZE; i++) {
        s[i] = 2 * s[i - 1] + (i + 2);
    }

    int n;
    cin >> n;

    int max_index = 1;
    while (n >= s[max_index]) {
        max_index++;
    }
    /*
    for(int i = 1; i < SIZE ; i++){
        cout << s[i] << " ";
    }
    cout <<"\n";

    cout << max_index;
    */
    cout << solution(n, max_index);

    return 0;
}
