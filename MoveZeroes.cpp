#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int st,int mid,int end){   // Merge function
    vector<int>temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i] >= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
      }

      while(i<=mid){          // If any elements are left in the right half
        temp.push_back(arr[i]);
            i++;
      }

      while(j<=end){           // If any elements are left in the right half  
        temp.push_back(arr[j]); 
        j++;
      }

      for(int idx=0;idx<temp.size();idx++){     // Copy the sorted elements from temp back to the original array
        arr[st+idx]=temp[idx];
      }

    }
void mergeSort(vector<int> &arr,int st,int end){
    int mid=st+(end-st)/2;
    if(st<end){
       mergeSort(arr,st,mid); //left half
       mergeSort(arr,mid+1,end); //right half

       merge(arr,st,mid,end);
    }
}

int main(){
    vector<int> arr = {1,0,2,0,3,0};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int val:arr) {
        cout << val<< " ";
    }
    cout << endl;

    return 0;
}
