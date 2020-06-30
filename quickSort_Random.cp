#include <iostream>
using namespace std;
//与快速排序一样
int partition(int array[],int p,int r)//R为最右的数，P为最左边的数
{
    int x=array[r];//最右边的数
    int i=p-1; //p=0，i=-1
    for(int j=p;j<r;++j)
    {
        if(array[j]<=x)
        {
            ++i;    //i一直代表小于x元素的最后一个索引，当发现有比x小的array[j]时候，i+1 后交换
            swap(array[j],array[i]);//c++自带交换函数
        }
    }
    swap(array[r],array[i+1]);//将x切换到中间来，左边是小于x的，右边是大于x的值
    return i+1;//返回划分元素的最终位置
}
 
int partitionRandom(int array[],int p,int r)
{
   // int randNum=p+rand()%(r-p);//随机选取一个元素作为主元 rand()%MAX   MAX为最大值，其随机域为0~MAX-1
     int randNum=rand()%(r-p+1);
    swap(array[randNum],array[p]);
    return partition(array,p,r);
}
void quickSortRandom(int array[],int p,int r)
{
    if(p<r)
    {
        int q=partitionRandom(array,p,r);//返回划分元素的最终位置
        quickSortRandom(array,p,q-1);//划分左边递归
        quickSortRandom(array,q+1,r);//划分右边递归
    }
}
 
int main()
{
    int Array[8]={2,8,7,1,3,5,6,4};
    cout<<"原始数组顺序为："<<endl;
    for(int i=0;i<8;++i)
        cout<<Array[i]<<" ";
    quickSortRandom(Array,0,7);
    cout<<endl<<"经过快速排序随机化后数组顺序为："<<endl;
    for(int i=0;i<8;++i)
        cout<<Array[i]<<" ";
    return 0;
}
 
