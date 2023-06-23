/*
1011. Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1 

Constraints:
1 <= days <= weights.length <= 5 * 10^4
1 <= weights[i] <= 500
*/

int isShipped(vector<int>& w, int d,int c){
	int sc = 0,s = 0;
	for(int i = 0; i < w.size()-1; i++){
		sc += w[i];
		if(sc + w[i+1] > c){
			s++;
			if(s == d){
				return 0;
			}
			sc = 0;
		}
	}
   if(sc + w[w.size()-1] <= c){
		s++;
		if(s <= d){
			return 1;
		}
		else{
			return  0;
		}
	}
	else{
		return 0;
	} 
}
int shipWithinDays(vector<int>& weights, int days) {
	int l = weights[0], h = 0,mid,ans;
	for(int i = 0; i < weights.size(); i++){
		if(l < weights[i]){
			l = weights[i];
		}
		h += weights[i];
	}

	while(l <= h){
		mid = (l+h)/2;

		if(isShipped(weights, days,mid)){
			h = mid - 1;
			ans = mid;
		}
		else{
			l = mid + 1;
		}
	}
	return ans;
}