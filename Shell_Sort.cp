//insertion ranking method
#include <iostream>
using namespace std;
template<class T>
//void shell_sort(T array[], int length) {
//    int h = 1;
//    while (h < length / 3) {
//        h = 3 * h + 1;
//    }
//    while (h >= 1) {
//        for (int i = h; i < length; i++) {//和插入排序一样 只是1换成了h
//            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
//                swap(array[j], array[j - h]);
//            }
//        }
//        h = h / 3; //希尔增量
//    }
//}

void shell_sort(T arr[],int len)
{

    for(int Distance=len/2;Distance>0;Distance/=2){//增量序列为n/2,n/4....直到1
        for(int i=0;i<Distance;i++){
            for(int j=i+Distance;j<len;j+=Distance){//i=0时把第一组选出的元素给搞在一起，分别为a[i],a[i+distance],a[i+distance+distance]...
                //对每个分组进行插入排序
                if(arr[j]<arr[j-Distance]){//只有当前元素a[j]小于a[j-group](前面排好序的最右边的值)，才需要插值
                    T key=arr[j];//记录需要插入的值
                    int k=j-Distance;//标记需要插入的位置
                while (key<arr[k]&&k>0) {//找出需要插入的位置
                        arr[k+Distance]=arr[k];//把a[k]复制并且移动到下一位
                        k-=Distance;//如果满足插入条件，temp会不断的和前面的值比较，直到找到需要插入的位置k
                }
                arr[k+Distance]=key;//找到位置以后插入位置，因为while中多减去了一个group的值，所以插入的时候需要加上group
            }
            }}
    }
}
int main()
{
    int arr[]={1,51,6,2,8,2,564,1,65,6};
    float arr1[]={12.3,12.3,1.2,34.5,678.2,23.2};
    int len=(int) sizeof(arr)/sizeof(arr[0]);
    int len1=(int) sizeof(arr1)/sizeof(*arr1);
    shell_sort(arr,len);
    shell_sort(arr1, len1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=0;i<len1;i++){
            cout<<arr1[i]<<endl;
        }
       
    return 0;
    
}
