#include <iostream>
using namespace std;
template <class T>
int partition(T arr[], int left, int right)//R为最右的数，P为最左边的数
{
    int i=left-1;
    T switchValue=arr[right];
    for(int j=left;j<=right;j++){
        if(arr[j] < switchValue){
            i++;  //i一直代表小于switchValue元素的最后一个索引，当发现有比switchValue小的arr[j]时候，i+1 后交换
            swap(arr[j],arr[i] );
        }
    }
    swap(arr[right], arr[i+1]);//将keswitchValuey切换到中间来，左边是小于switchValue的，右边是大于switchValue的值。
    return i+1;//返回划分元素的最终位置
    
    
}
template <class T>
int partitionRandom(T array[],int left,int right)
{
    int key=rand()%(right-left+1);//随机选取一个元素作为主元 rand()%MAX   MAX为最大值，其随机域为0~MAX-1
    swap(array[key], array[right]);
    return partition(array, left, right);
}

template <class T>
void quickSortRandom(T array[],int left,int right)
{
    if(left<right){
    int PartitionIndex = partition(array,left,right);//返回划分元素的最终位置
    quickSortRandom(array,left,PartitionIndex-1);//划分左边递归
    quickSortRandom(array,PartitionIndex+1,right);//划分右边递归
    }
}
 
int main()
{
    int arr[]={1,51,6,2,8,2,564,1,65,6};
    float arr1[]={12.3,12.3,1.2,34.5,678.2,23.2};
    int len=(int) sizeof(arr)/sizeof(arr[0]);
    int len1=(int) sizeof(arr1)/sizeof(*arr1);
    quickSortRandom(arr,0,len-1);
    quickSortRandom(arr1,0,len1-1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=0;i<len1;i++){
            cout<<arr1[i]<<endl;
        }
       
    return 0;

}
