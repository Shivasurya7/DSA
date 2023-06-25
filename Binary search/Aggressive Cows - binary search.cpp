/*
Aggressive Cows

You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:
Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.

Example 2:
Input:
n=5 
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.

Your Task:
Complete the function int solve(), which takes integer n, k, and a vector stalls with n integers as input and returns the largest possible minimum distance between cows.

Expected Time Complexity: O(n*log(10^9)).
Expected Auxiliary Space: O(1).

Constraints:
2 <= n <= 10^5
2 <= k <= n
0 <= stalls[i] <= 10^9
*/

int isAns(vector<int>& p, int m,int g){
	int in = 1,prev = p[0];

	for(int i = 0; i < p.size(); i++){
		if(p[i] - prev >= g){
			prev = p[i];
			in++;
			if(in == m){
				return 1;
			}
		}
	}

	if(in < m){
		return 0;
	}
	else{
		return 1;
	}
}

int solve(int n, int m, vector<int> &position) {
	sort(position.begin(),position.end());
	int l = 1,h = position[position.size()-1]-1,mid,ans=0;

	while(l <= h){
		mid = (l+h)/2;
		if(isAns(position,m,mid)){
			l = mid + 1;
			ans = mid;
		}
		else{
			h = mid - 1;
		}
	}
	return ans;
}