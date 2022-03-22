class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(heights.size(), 0);
        //Stack is used to hold all visible people
        stack<int> s;
        for(int i = heights.size() - 1; i >= 0; i--)
        {
            int count = 0;
            //When a taller person is found, he/she hides everyone else to the right.
            //So remove all the shorter heights from the stack so that they are not available to the persons furthers to the left
            //At the same time, all those shorter people in the stack are visible to the current person at i. So, that's his result
            while(!s.empty() && heights[i] > s.top())
            {
                count++;
                s.pop();
            }
            //After removing all shorter people, there could be people taller than i. So, i would be able to see that tall person
            if(!s.empty())
                count++;
            result[i] = count;
            s.push(heights[i]);
        }
        return result;
    }
};