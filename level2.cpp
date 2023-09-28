#include <bits/stdc++.h>
using namespace std;
unordered_map<string , string> umap;
vector<string> ans;

void solution(vector<vector<string>> queries){
    
    for(auto it : queries){
        string task = it[0];
        string dir = it[1];
        
        
        if(task == "ADD_FILE"){
            string store = it[2];
            if(umap.find(dir) != umap.end()){
                ans.push_back("false");
            }
            else{
                umap[dir] = store;
                ans.push_back("true");
            }
        }
        
        if(task == "GET_FILE_SIZE"){
            if(umap.find(dir) == umap.end()){
                ans.push_back("space");
            }
            else{
                ans.push_back(umap[dir]);
            }
        }
        
        if(task == "DELETE_FILE"){
            if(umap.find(dir) == umap.end()){
                ans.push_back("space");
            }
            
            else{
                ans.push_back(umap[dir]);
                umap.erase(dir);
            }
        }
        
        if(task == "GET_N_LARGEST"){
            vector<pair<string , string >> pairs;

            for(auto itr : umap){
                
                if(itr.first.compare(0 , dir.size() , dir) == 0){
                    
                    //cout << "found" << endl;
                    //cout << itr.first << endl;
                    pairs.push_back({itr.first , itr.second});
                    
                }
                
            }
            if(pairs.size() != 0){
                sort(pairs.begin(), pairs.end(), [](const pair<string, string>& left, const pair<string, string>& right){
                    if(stoi(left.second) == stoi(right.second)) {
                        return left.first < right.first;
                        
                    } else {
                        return stoi(left.second) > stoi(right.second);
                        
                    }
                    
                });
                int count = stoi(it[2]);
                if(count < pairs.size()){
                    pairs.resize(count);
                }
                for(auto iter : pairs){
                    ans.push_back(iter.first + "(" + iter.second + ")");
                    
                }
            }
            else{
                ans.push_back("");
            }
        }
        
    }
    
}

int main()
{
    std::vector<std::vector<std::string>> queries = {
    {"ADD_FILE", "/dir1/file.txt", "5"},
    {"ADD_FILE", "/dir1/file2.txt", "20"},
    {"ADD_FILE", "/dir1/deeper/file3.move", "9"},
    {"GET_N_LARGEST", "/dir1" , "2"},
    {"GET_N_LARGEST", "/dir1/file" , "3"},
    {"GET_N_LARGEST", "/another_dir" , "file.txt"},
    {"ADD_FILE", "/big_file.mp4", "20"},
    {"GET_N_LARGEST", "/" , "2"}
    };
    
    solution(queries);
    
    for(auto it:ans){
        cout << it << endl;
    }

    return 0;
}
