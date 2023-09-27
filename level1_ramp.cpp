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
        
    }
    
}

int main()
{
    std::vector<std::vector<std::string>> queries = {
    {"ADD_FILE", "/dir1/dir2/file.txt", "10"},
    {"ADD_FILE", "/dir1/dir2/file.txt", "5"},
    {"GET_FILE_SIZE", "/dir1/dir2/file.txt"},
    {"DELETE_FILE", "/non-existing.file"},
    {"DELETE_FILE", "/dir1/dir2/file.txt"},
    {"GET_FILE_SIZE", "/non-existing.file"}
        
    };
    solution(queries);
    
    for(auto it:ans){
        cout << it << endl;
    }

    return 0;
}
