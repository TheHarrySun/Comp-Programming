/* ----------------------------------------------------- */
/* KokoEatingBananas.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Koko Eating Bananas */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // first find the largest pile in the vector
        int largest = 0;
        for (int pile : piles)
        {
            largest = max(pile, largest);
        }

        /* perform binary search between 1 and the largest, to find which time is most optimal */
        int bottom = 1;

        // we will store the optimal time in k
        int k;

        while (bottom <= largest)
        {
            // define a speed as the avg btwn the bottom and largest
            int speed = (bottom + largest) / 2;
            int time = 0;

            // go through each pile and add up the time it takes to eat the pile
            for (int pile : piles)
            {
                time += pile / speed;
                if (pile % speed != 0)
                {
                    time++;
                }
            }

            // if the time is less than h, then that is a viable speed, so we store k and then adjust largest
            if (time < h)
            {
                k = speed;
                largest = speed - 1;
            }

            // if the time is greater than h, we must adjust bottom
            if (time > h)
            {
                bottom = speed + 1;
            }

            // if it equals h, then it's a viable time, but there may be a smaller rate so we decrement larger
            if (time == h)
            {
                k = speed;
                largest--;
            }
        }
        return k;
    }
};

int main()
{
    Solution obj;
    vector<int> piles = {1, 4, 3, 2};
    int h = 9;
    cout << obj.minEatingSpeed(piles, h) << endl;

    piles = {25, 10, 23, 4};
    h = 4;
    cout << obj.minEatingSpeed(piles, h) << endl;
}