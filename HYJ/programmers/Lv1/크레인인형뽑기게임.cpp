#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> s;



    for(int i = 0 ; i < moves.size() ; i++){
        for(int j = 0 ; j < board.size() ; j++){
            int temp = board[j][moves[i]-1];
            if(temp != 0){
                if(!s.empty() && s.top() == temp){
                    s.pop();
                    answer += 2;
                }else {
                    s.push(temp);
                }

                cout<< "행  : "  << j << "열 : " << moves[i] - 1 << "\n";
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }

    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < board[i].size() ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }


    return answer;
}
