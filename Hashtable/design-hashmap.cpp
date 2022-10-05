class MyHashMap {
public:
    MyHashMap() {
        
    }
    vector<pair<int,int>> bucket[100]; //bucket is an array whose each element is a vector of pair
    
    void put(int key, int value) {
        int index = key%100;
        for(int i=0 ; i<bucket[index].size(); i++){
            if(bucket[index][i].first==key){
               bucket[index][i].second=value;
               return;
            }
        }
        bucket[index].push_back({key,value});
     }   
    
    int get(int key) {
        int index = key%100;
        for(int i=0 ; i<bucket[index].size(); i++){
            if(bucket[index][i].first==key)
                return bucket[index][i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key%100;
        for(int i=0 ; i<bucket[index].size(); i++){
            if(bucket[index][i].first==key){
                bucket[index].erase(bucket[index].begin() + i);
                return;
            }
        }
    }
};
