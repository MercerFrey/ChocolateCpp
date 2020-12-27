#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]){
    auto start = std::chrono::system_clock::now();
    ofstream fcout;
    ifstream fcin;
    fcin.open(argv[1]);
    fcout.open(argv[2]);
    long long  n,m;
    fcin >> n;
    fcin >> m;
    vector <long long > arr;
    vector<long long> result;
    long long a;
    for (int i=0; i < n; i++){
        fcin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(),arr.end());
    cout << endl;

   result.push_back(arr[0]);
   for (int i=1;i<n;i++){
       if ( i < m){
           result.push_back(arr[i]+result[i-1]);
       }
       else if ( i== m){
            result.push_back(arr[i]+result[i-1]+result[0]);
       }
       else {
           result.push_back(arr[i]+result[i-1]+result[i-m]-result[i-m-1]);
       }
   }

    for (int i=0; i<result.size();i++){
        fcout << result[i]<< " ";
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    printf("Time = %lld ms\n", static_cast<long long int>(elapsed.count()));
    return 0;
}
