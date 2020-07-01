#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//void Swap(int &a, int &b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}

//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度
// ?调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上?
//此时完全二叉树中，除去顶部这个元素之后，这个完全二叉树已经不满足堆的性质，所以要进行调整，此时的每次调整要从根节点（和创建堆不一样）开始进行调整，而且父节点和孩子节点交换后，要追踪到交换的孩子节点上。
//某个数在root位置，看看是否能往下沉
//不断和左右两个孩子比较
//较大的孩子如果大于当前的父，父节点往下沉，较大的孩子上来
void Heap_build(int a[],int root,int length)
{
    int lchild = root*2+1;//根节点的左子结点下标
    if(lchild < length)//左子结点下标不能超出数组的长度（还有左孩子）
    {
        int largest = lchild;//先假设做孩子为最大值----->largest保存左右节点中最大值的下标
        int rchild = lchild+1;//根节点的右子结点下标
        if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
        {
            if (a[rchild] > a[largest])//找出左右子结点中的最大值
            {
                largest = rchild;
            }
        }
        if (a[root] < a[largest])//父和较大孩比较，谁的值大，把下标给largest
        {
            //交换父结点和比父结点大的最大子节点
            swap(a[root],a[largest]);
            //从此次最大子节点的那个位置开始递归建堆
            Heap_build(a,largest,length);
        }
//        if(largest==root) break;//不用往下沉了
//        Swap(largest,root);
//        root = largest;
//        lchild=2*root+1;
    }
}
 
void Heap_sort(int a[],int len)
{
//1.构建大顶堆
    for (int i = (len-1)/2; i >= 0; --i)//从最后一个非叶子节点的父结点开始建堆
    {
        Heap_build(a,i,len);
    }
//2.调整堆结构+交换堆顶元素与末尾元素
    for (int j = len-1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
    {
        swap(a[0],a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
        //交换完以后需要重新对堆进行调整
        Heap_build(a,0,j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
    }
 
}
int main(int argc, char **argv)
{
    clock_t Start_time = clock();
    int a[10] = {12,45,748,12,56,3,89,4,48,2};
    Heap_sort(a,10);
     for (size_t i = 0; i != 10; ++i)
     {
         cout<<a[i]<<" ";
     }
    clock_t End_time = clock();
    cout<<endl;
    cout<<"Total running time is: "<<static_cast<double>(End_time-Start_time)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    cin.get();
    return 0;
}

