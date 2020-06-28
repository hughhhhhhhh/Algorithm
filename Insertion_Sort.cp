//insertion ranking method
//关键点是把比较以后大的数，往右边复制+移一位
#include <iostream>
using namespace std;
template<class T>
void insertion_sort(T arr[],int len){
    for(int i=1;i<len;i++){
        T key=arr[i];//key为要插入的值
        int j=i-1;//j为排序好的最右边的一位
        while((key<arr[j])&&(j>=0)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key; //key>arr[j],所以吧key放在arr[j+1]的位置
    }
}
int main()
{
    int arr[]={1,3,4,2,54,23};
    float arr1[]={12.3,12.3,1.2,34.5,678.2,23.2};
    int len=(int) sizeof(arr)/sizeof(arr[0]);
    int len1=(int) sizeof(arr1)/sizeof(*arr1);
    insertion_sort(arr,len);
    insertion_sort(arr1, len1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=0;i<len1;i++){
           cout<<arr1[i]<<endl;
       }
       
    return 0;
    
}
