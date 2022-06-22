/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) 
    {
        int celeb = 0;
        for(int i = 0; i < n; i++)
            if(knows(i, celeb) == false) celeb = i;
        for(int i = 0 ; i < n; i++)
        {
            if(i == celeb) continue;
            if(knows(i, celeb) == false or knows(celeb, i) == true) return -1;
        }
        return celeb;
    }
};