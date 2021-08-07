class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // 슬라이딩 윈도우 , 투 포인터를 사용하면 시간 복잡도를 O(N), 공간 복잡도를 O(N)으로 줄일 수가 있다.
        set<char> charSet;
        // 왼쪽 포인터
        int left = 0;

        int m = 0;
        // 오른쪽 포인터를 이동하면서 윈도를 증가시킨다.
        for(int right = 0; right < s.length(); right++){
            // 존재한다면
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(charSet.find(s[left]));
                left++;
            }
            charSet.insert(s[right]);
            int res = right - left + 1;

            m = max(m, res);
        }
        return m;
    }
};
