class Solution {
public:
    bool canPlaceFlowers(vector<int>& flo, int n) 
    {    
        if(n == 0)
            return true;
        if(flo.size() == 1)
        {
            if(n>1 || flo[0] == 1)
                return false;
            return true;
        }
        
        if(flo[0] == 0 && flo[1] == 0)
        {
            flo[0] = 1;
            n--;
        }
        if(flo[flo.size()-1] == 0 && flo[flo.size()-2] == 0)
        {
            flo[flo.size()-1] = 1;
            n--;
        }
        
        for(int i = 1; i < flo.size()-1; i++)
        {
           if(flo[i] == 0 && flo[i-1] == 0 && flo[i+1] == 0)
           {
                n--;
                flo[i] = 1;
                if(n<1)
                        return true;
           }
        }
        
        return n<1;
    }
};