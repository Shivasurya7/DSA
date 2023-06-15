/*
Given a sorted array with repeating integers. You need to find the first occurence , last occurence and count of a given key in the array. USE ONLY BINARY SEARCH. Your algorithm should run in LogN time.If element is not present print -1 -1 0.

Input Format

First line contains N , then N integers in next line , then key in the next line.

Constraints

N<=1000000

Output Format

3 space separated integers for lower bound , upper bound and count/frequency of that key.

Sample Input

6

1 2 2 2 3 4

2

Sample Output

1 3 3

Explanation

First occurence of 2 is at 1. Second Occurence of 2 is at 3. Count is 3.
*/

#include <iostream>
using namespace std;

int lowerBound(int a[],int s,int k){
  int l = 0,h = s-1,i = -1,mid;
  while(l <= h){
    mid = (l+h)/2;
    if(a[mid] >= k){
      h = mid-1;
      i = mid;
    }
    else{
      l = mid+1;
    }
  }
  return i;
}

int upperBound(int a[],int s,int k){
  int l = 0,h = s-1,i = -1,mid;
  while(l <= h){
    mid = (l+h)/2;
    if(a[mid] <= k){
      l = mid+1;
      i = mid;
    }
    else{
      h = mid-1;
    }
  }
  return i;
}

int main()
{
  int n,k,lb,ub;
  cin>>n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  cin>>k;
  ub = upperBound(a,n,k);
  lb = lowerBound(a,n,k);
    cout<<lb<<" "<<ub<<" ";
  
}


