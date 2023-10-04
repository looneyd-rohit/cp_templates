/*
Problem Link:
https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

#include<bits/stdc++.h>
using namespace std;

// ninja cannot perform same work for 2 consecutive days, we are given a 2D array
// of size N*3, of merit points, we are required to find the maximum merit points
// ninja can collect.
int func(int i, int indexTaken, vector<vector<int>>& points){
    // base case
    if(i<0) return 0;

    int sum = INT_MIN;
    // check
    // if(indexTaken!=0)
    // sum = max(sum, points[i][0] + func(i-1,0,points));

    // if(indexTaken!=1)
    // sum = max(sum, points[i][1] + func(i-1,1,points));

    // if(indexTaken!=2)
    // sum = max(sum, points[i][2] + func(i-1,2,points));

    // using for loop to solve the same as above
    for(int x=0; x<3; x++){
        if(x!=indexTaken){
            int p = points[i][x] + func(i-1,x,points);
            sum = max(sum,p);
        }
    }

    return sum;
}

// memoized version
// so the trick in this question is we need to use a 2D dp array to store the
// merits as we have two changing parameters: [index] and [indexTaken].
// We basically need a N*4 dp array because the range of index is [0,n-1] and
// the range of indexTaken is {0,1,2,-1}, where -1 signifies that none is selected.
int funcMemoized(int i, int indexTaken, vector<vector<int>>& points, vector<vector<int>>& dp){
    // base case
    if(i<0) return 0;

    // checking if value already present in dp array or not
    if(dp[i][indexTaken]!=INT_MIN) return dp[i][indexTaken];

    int sum = INT_MIN;
    // check
    // using for loop to solve the same as above
    for(int x=0; x<3; x++){
        if(x!=indexTaken){
            int p = points[i][x] + funcMemoized(i-1,x,points,dp);
            sum = max(sum,p);
        }
    }

    return dp[i][indexTaken]=sum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // below code gives tle, because we are simply using recursion where many
    // overlapping subproblems arise
    // cout<<func(points.size()-1,3,points)<<endl;

    // now we memoize this problem
    // we can memoize it only by using a dp array of size n*4.
    // vector<vector<int>> dp(n,vector<int>(4,INT_MIN));
    // cout<<funcMemoized(points.size()-1,3,points,dp)<<endl;;
    // for(auto&e:dp){
    //     for(auto&ee:e)
    //         cout<<ee<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    // now tabulate the problem
    vector<vector<int>> dp(n,vector<int>(4,INT_MIN));
    // to perform tabulation we have two changing parameters index and indexTaken
    // so we need two outer for loops and then we do the same as in recursion body

    // tabulation is a bottom up approach so at first we need to evaluate the
    // starting index
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    // range of index - [0,n-1] and range of indexTaken - [0,3]
    for(int i=0; i<n; i++){
        for(int indexTaken=0; indexTaken<4; indexTaken++){
            // now do the same as done in recursion body to evaluate dp array points

            int sum = INT_MIN;
            // check
            // using for loop to solve the same as above
            for(int x=0; x<3; x++){
                if(x!=indexTaken){
                    int p = points[i][x] + funcMemoized(i-1,x,points,dp);
                    sum = max(sum,p);
                }
            }

            dp[i][indexTaken]=sum;
        }
    }
    cout<<dp[n-1][3]<<endl;

    // space optimization
    // we reduce the space N*4 to only a 4 size array
    vector<int> dpPrev(4,0);
    dpPrev[0] = max(points[0][1],points[0][2]);
    dpPrev[1] = max(points[0][0],points[0][2]);
    dpPrev[2] = max(points[0][0],points[0][1]);
    dpPrev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    for(int i=0; i<n; i++){
        // for calculating the next 4 set of values we use the previous array
        vector<int> temp(4,0);
        
        for(int indexTaken=0; indexTaken<4; indexTaken++){
            int sum = INT_MIN;
            
            for(int x=0; x<3; x++){
                if(x!=indexTaken){
                    int p = points[i][x] + funcMemoized(i-1,x,points,dp);
                    sum = max(sum,p);
                }
            }

            temp[indexTaken]=sum;
        }
        // after temp is fully updated, change prev array
        dpPrev = temp;
    }
    cout<<dpPrev[3]<<endl;





}

int main(){
    int n;
    cin>>n;
    vector<int> v(3);
    vector<vector<int>> points;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
        cin>>v[j];
        points.push_back(v);
    }
    ninjaTraining(n,points);
    return 0;
}