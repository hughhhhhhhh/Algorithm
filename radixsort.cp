#include <iostream>
#include <vector>
using namespace std;
int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];              ///先假设第0位为最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i]) maxData = data[i];
    }
    int radix = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        radix++;
    }
    return radix;
/*    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;*/
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器，因为都是是十进制的数，所以count是有十位
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数，先从最高位数开始
            count[k]++;
        }
        for(j = 1; j < 10; j++) //count数组变为小于等于这个位置的有几个数
            count[j] += count[j - 1]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //从右往左遍历，将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;//先从最高位数开始比
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;//先从最高位数开始比
    }
    delete []tmp;
    delete []count;
}
int main()
{
    int arr[] = { 1,5,3,73,642,2,48,9,3424,3,3 };
    radixsort(arr,11);
    for (int i=0;i<11;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

