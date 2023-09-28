#include <bits/stdc++.h>
using namespace std;
unordered_map<string , string> umap;
vector<string> ans;
unordered_map<string, unordered_map<string, string>> userFiles;
unordered_map<string, unordered_map<string, string>> backup_Files;
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
            string mem;
            for(auto userEntry : userFiles){
                if(userEntry.second.find(dir) != userEntry.second.end()){
                    mem = userEntry.second[dir];
                    ans.push_back(mem);
                }
                else{
                    ans.push_back("SPACE");
                }
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
        
        if(task == "ADD_USER"){
            string memory = it[2];
            if(umap.find(dir) != umap.end()){
                ans.push_back("false");
            }
            else{
                umap[dir] = memory;
                ans.push_back("true");
            }
        }
        
        if(task == "ADD_FILE_BY"){
            string file_name = it[2];
            string memory = it[3];
            userFiles[dir][file_name] = memory;

            int mem = stoi(umap[dir]);
            //cout << mem << endl;
            int remain = mem - stoi(memory);
            if(remain >= 0){
                ans.push_back(to_string(remain));
                umap[dir] = to_string(remain);
            }
            else{
                ans.push_back(" ");
            }
        }
        if(task == "RESTOR_FILE"){
            if(backup_Files.find(dir) == backup_Files.end()){
            
                ans.push_back("0");
                int s = stoi(umap[dir]);
                for(auto userEntry : userFiles){
                  for(auto fileEntry : userEntry.second){
                      s += stoi(fileEntry.second);
                    }
                }
                umap[dir] = to_string(s);
                userFiles.clear();
                //cout << "Final Value " << endl;
                //cout << umap[dir] << endl;
                
            }
            else{
                userFiles = backup_Files;
            }
        }
        if(task == "BACKUP_USER"){
            backup_Files = userFiles;
            int sz = 0;
            //cout << userFiles.size() << endl;
            
            
           for(const auto& userEntry : userFiles) {
             //cout << "User: " << userEntry.first << endl;
             //int sz = userEntry.second.size();
             for(const auto& fileEntry : userEntry.second) {
                 ++sz;
                 //cout << "File: " << fileEntry.first << ", Size: " << fileEntry.second << endl;
                   
             }
                
            }
            ans.push_back(to_string(sz));
            
            if(backup_Files.find(dir) == backup_Files.end()){
                int s = stoi(umap[dir]);
                //ans.push_back("0");
                for(auto userEntry : userFiles){
                    for(auto fileEntry : userEntry.second){
                        s += stoi(fileEntry.second);
                    }
                }
                umap[dir] = s;
          //      ans.push_back("0");
                
            }
            //else{
                
            //}
            backup_Files = userFiles;
            
        
        }
        
        
    }
    
}

int main()
{
    std::vector<std::vector<std::string>> queries = {
        {"ADD_USER" , "user" , "100"},
        //{"ADD_USER" , "user" , "100"},
        {"ADD_FILE_BY" , "user" , "/dir/file" , "50"},
        {"ADD_FILE_BY" , "user" , "/file2.txt" , "30"},
        {"RESTOR_FILE" , "user"},
        {"ADD_FILE_BY" , "user" , "/file3.mp4" , "60"},
        {"ADD_FILE_BY" , "user" , "/file4.txt" , "10"},
        {"BACKUP_USER" , "user"},
        {"DELETE_FILE" , "/file3.mp4"},
        {"DELETE_FILE" , "/file4.txt"},
        {"ADD_FILE" , "/file3.mp4" , "140"},
        {"ADD_FILE_BY" , "user" , "/dir/file5.new" , "20"}
        

    };
    
    solution(queries);
    
    for(auto it:ans){
        cout << it << endl;
    }

    return 0;
