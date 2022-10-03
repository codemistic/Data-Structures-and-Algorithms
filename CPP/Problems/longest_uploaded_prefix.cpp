class LUPrefix {
public:
    int p;
    map<int,int>hash;
    LUPrefix(int n) {
     p=0;
    }
    
    void upload(int video) {
        
      hash[video]++;
        while(hash[p+1]>0)p++;
    }
    
    int longest() {
       return p;
    }
};
