class Vector{
    int *arr;
    int ms;
    int cs;
    public:
    Vector(int size=1){
        cs=0;
        ms=size;
        arr= new int[ms];
    }
    void push_back(int d){
        if(cs==ms){
            int *oldArr=arr;
            ms*=2;
            arr= new int[ms];
            //copy the old items to the new array of double size
            for (int i = 0; i < cs; i++) {
                arr[i]=oldArr[i];
            }
            delete []oldArr;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back(){
        if(cs>=0){
            cs--;
        }

    }
    bool isEmpty(){
        return cs==0;
    }
    int Front(){
        return arr[0];

    }
    int back(){
        return arr[cs-1];
    }
    int at(int i){
        return arr[i];
    }
    int size(){
        return cs;
    }
    int capacity(){
        return ms;
    }
    int operator[](const int i) const{
        return arr[i];
    }


};







