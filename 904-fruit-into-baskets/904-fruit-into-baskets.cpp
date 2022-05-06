class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxTrees = 0;
        unordered_map<int, int> basket;
        int left = 0;
        
        for(int right = 0; right < fruits.size(); right++)
        {
            if(basket.count(fruits[right]))
                basket[fruits[right]]++;
            else
                basket[fruits[right]]  = 1;
            
            while(left <= right && basket.size() > 2)
            {
                basket[fruits[left]]--;
                if(basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            maxTrees = max(maxTrees, right-left+1);
        }
        return maxTrees;
    }
};