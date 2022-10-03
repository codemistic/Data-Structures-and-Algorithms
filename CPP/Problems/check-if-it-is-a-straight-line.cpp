class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool flag=true;
        
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        int m1=y2-y1;
        int m2=x2-x1;
        int curdx=0;
        int curdy=0;
       for(int i=2;i<coordinates.size();i++)
       {
           curdx=coordinates[i][0]-coordinates[i-1][0];
           curdy=coordinates[i][1]-coordinates[i-1][1];
           
           if(curdx*m1!=curdy*m2)
               return false;
       }
        return true;
      
    }
};
