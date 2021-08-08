#include <iostream>


using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long now_price = price;
    long long sum = 0;

    for(int i = 1 ; i <= count ; i++){
        now_price = price * i;
        sum += now_price;
    }

    answer=  sum - money;
    if(answer <= 0 ){
        answer = 0;
    }

    return answer;
}
