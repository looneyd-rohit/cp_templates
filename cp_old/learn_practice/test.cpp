// // #include <bits/stdc++.h>
// // using namespace std;







// // int main()
// // {
// //     // cout << "Hello World!!!" << endl;
// //     // cout << (69420 + 42068) % 69420 << endl;
// //     // cout << 42068 % (69420 + 42068) << endl;
// //     // char c = 'a';
// //     // int x = 5;
// //     // int &y = x;
// //     // cout << "size of x= " << sizeof(x) << endl;
// //     // cout << "size of y= " << sizeof(y) << endl;
// //     // vector<int> v;
// //     // v.push_back(1);
// //     // v.push_back(2);
// //     // v.push_back(3);
// //     // v.push_back(4);
// //     // // for(auto i = v.rbegin(); i!=v.rend(); i++)
// //     // // cout<<*i<<" ";
// //     // cout<<*(v.end());
// //     // cout<<endl;

// //     // multimap<char,int> mmap;
// //     // mmap.insert(pair<char,int>('a',2));
// //     // mmap.insert(pair<char,int>('a',1));
// //     // mmap.insert(make_pair('a',3));
// //     // // for(auto &e:mmap){
// //     // //     cout<<e.first<<" "<<e.second<<endl;
// //     // // }
// //     // auto it = mmap.upper_bound('c');
// //     // cout<<it->first<<" "<<it->second<<endl;

// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// bool isSame(int *a,int *b, int size){
//     for(int i=0; i<size; i++){
//         if(a[i]!=b[i])
//         return false;
//     }
//     return true;
// }
// int main(){
//     int arr[]{3,1,3,3,4,3};
//     int size = sizeof(arr)/sizeof(int);
//     int barr[size];
//     for(int i=0; i<size; i++)
//     barr[i]=arr[i];
//     sort(barr,barr+size);

//     int start =0, end = size-1;
//     int cost=0;
//     while(start!=size-1){
//         int diff = end - start;
//         while(diff--){
//             sort(arr+start,arr+end);
//             if()
//         }
//     }

//     return 0;
// }