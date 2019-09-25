#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> result;
        int len_a = A.size();
        int len_b = B.size();
        int i = 0, j=0;
        while(i<len_a && j< len_b){
            result.push_back(A[i]<=B[j]?A[i++]:B[j++]);
        }
        while(i<len_a)
            result.push_back(A[i++]);
        while(j<len_b)
            result.push_back(B[j++]);
        return result;
}

int main(){
    // this defination is wrong, for b is not declared
    //int a=b=0;
    vector<int> a= {1,3,5}, b = {2,4,6};
    vector<int> a_merge_b = mergeSortedArray(a,b);
    for(int i =0;i<a_merge_b.size();i++)
        cout<<a_merge_b[i]<<" ";
    return 0;
}
