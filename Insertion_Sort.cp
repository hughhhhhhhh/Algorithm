//insertion ranking method
#include <iostream>
using namespace std;
template<class T>
void insertion_sort(T arr[],int len){
        for(int i=1;i<len;i++){ // 从下标为1的元素开始选择合适的位置插入，因为下标为0的只有一个元素，默认是有序的
                T key=arr[i];// 记录要插入的数据
                // 从已经排序的序列最右边的开始比较，找到比其小的数
                int j=i-1;
                while((j>=0) && (key<arr[j])){
                        arr[j+1]=arr[j];
                        j--;
                }
                arr[j+1]=key;  // 存在比其小的数，插入
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
