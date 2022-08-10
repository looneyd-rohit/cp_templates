/*
Problem link:
https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/
#include<bits/stdc++.h>
using namespace std;

int waysToFindNthStep(int index){
    if(index==0) return 1;
    if(index<0) return 0;
    int left = waysToFindNthStep(index-1);

    int right = waysToFindNthStep(index-2);

    return (left+right);
}

int main(){
    // man can only take one/two step from 0-th stair, find no of ways in which
    // he can reach the N-th stair
    int n;
    cin>>n;
    cout<<waysToFindNthStep(n)<<endl;
    return 0;
}