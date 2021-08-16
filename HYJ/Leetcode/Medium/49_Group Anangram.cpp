class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> m;

        for(int i = 0 ; i < strs.size() ; i++){
            int nums_str[26] = {0};

            for(int j = 0 ; j < strs[i].length(); j++){
                int index = strs[i][j] -'a';
                nums_str[index]++;
            }
            /*
            for(int i = 0 ; i < 26; i++){
                cout <<nums_str[i] << " ";
            }*/

            // 문자열로 nums_str을 만들기.
            string str = "";
            for(int i = 0 ; i < 26 ; i++){
                str += to_string(nums_str[i]) + " " ;
            }
            //cout <<str<<"\n";

            if(m.find(str) == m.end()){
                m.insert(make_pair(str, vector<string>()));
                m[str].push_back(strs[i]);
                //cout << m[str].size() <<"\n";
            }else {
                m[str].push_back(strs[i]);
               // cout << m[str].size() <<"\n";
            }


        }
        // 맵 탐색하면서 정답 넣기!!
        int index = 0;
        for(auto iter : m){
            answer.push_back(vector<string>());
            for(int i = 0 ; i< iter.second.size(); i++){
                answer[index].push_back(iter.second[i]);
            }
            index++;
        }

        return answer;
    }
};
