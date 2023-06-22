/*
Median in a row-wise sorted Matrix

Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)

Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000
*/

int median(vector<vector<int>> &arr, int r, int c){
	   int mx = arr[0][0],mn = arr[0][0],mid,co;
	   
	   for(int i = 0; i < r; i++){
		   mx = max(mx,arr[i][c-1]);
		   mn = min(mn,arr[i][0]);
	   }
	   
	   while(mn <= mx){
		   co = 0;
		   mid = (mn+mx)/2;
		   
		   for(int i = 0; i < r; i++){
			   co += upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
		   }
		   
		   if(co <= (c*r)/2){
			   mn = mid + 1;
		   }
		   else{
			   mx = mid-1;
		   }
	   }
	return mn;
}