/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
    //Isolate a survivor(who complies with the conditions) who could be a potential celebrity
        int survivor = 0;
        for(int i = 0; i < n; i++)
        {
            if(knows(survivor, i))
                survivor = i;
        }
        
        //Validate the survivor from above
        for(int i = 0; i < n; i++)
        {
            if(i != survivor)
                if(knows(survivor, i) || !knows(i, survivor))
                    return -1;
        }
        return survivor;
    }
};