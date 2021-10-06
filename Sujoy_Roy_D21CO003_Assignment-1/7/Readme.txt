This program is performed on Windows.
To compile the program type:- gcc Q7.cpp -o Q7
To run the program type:- ./Q7.out

Asymptotic Analysis:-

Code 1
The for loop runs O(n) time as i goes from 1-n. In the nested for loop j goes from 1-i
So, when i=1 j=1-1 when i=2 j=1-2 when i=3 j=1-3...
when i=n j=1-n As loop goes 1+2+3+.....+n(n+1)/2 Thus this cost O(n^2)
Time Complexity for Code:1 = O(n^2).

Code 2
The first loop is a while loop which goes till j>=1 The nested for loop goes from 1-j
and we are initializing j=n/2 as j is always n/2 and value of n never changes, until
n=1 the function falls into an infinite loop.
Algorithm does not terminate. Hence, we cannot calculate the time complexity.

Code 3
The for loop runs O(n) time as i goes from 1-n. In the nested for loop j goes from 1-i
So, when i=1 j=1-1 when i=2 j=1-2 when i=3 j=1-3...
when i=n j=1-n In the nested for loop k goes from 1-i So, when i=1 j=1-1 when i=2 j=1
k=1 when i=2 j=2 k=1 when i=2 j=2 k=2...
when i=n j=1-n k=1-n As loop goes 1^2+2^2+3^2+.....+n^2 which is sum of square of
series having value as n(n+1)(2n+1)/6.
Thus this cost O(n^3).

Code 4
The while loop terminates for i < 1. The nested for loop runs O(n) time as i goes from
1-n. As in the while loop i= i/2 so it goes till i/2^k = 1 k=log i where i=n, therefor
k = log n, where k = number of time while loop execute. So, the total time complexity
is O(n)*O(log n)=O(nlogn)
Thus this cost O(n^2).

For value of n=10000
Code 1
Time taken by function=86186019 nanosecond.
Code 2
Time taken by function=12831 nanosecond; we are terminating manually as it goes in an
infinite loop.
Code 3
Time taken by function=437051158265 nanosecond.
Code 4
Time taken by function=176790 nanosecond.
