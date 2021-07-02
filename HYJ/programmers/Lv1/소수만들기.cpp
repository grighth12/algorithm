#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    // 소수를 미리 구해놓는다.
    vector<bool> prime_numbers(50000, false);
    vector<bool> counted(200, false);

    for(int i = 2 ; i < 50000; i++){
        if(!prime_numbers[i]){
            int index = 2;
            while(index * i < 50000){
                prime_numbers[index * i] = true;
                index++;
            }
        }
    }

    //  벡터 완전 탐색

    for(int i = 0 ; i < nums.size() -2; i++){
        for(int j = i+1 ; j < nums.size() -1 ; j++){
            for(int k = j+1 ; k < nums.size() ; k++){
                if(i == j || i == k || j == k) continue;
                int sum = nums[i] + nums[j] + nums[k];
                if(!prime_numbers[sum]){
                    answer++;
                }
            }
        }
    }

    return answer;
}
