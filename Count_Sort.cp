#include <iostream>
#include <vector>
using namespace std;
 
void CountSort(vector<int> &arr, int maxVal) { //Vector作为函数的参数或者返回值时，&不能少！
    int len = arr.size();
    if (len < 1)
        return;
    vector<int> count(maxVal+1, 0);//被初始化为包含（maxVal+1）个值为0的int
    vector<int> tmp(arr);//tmp 初始化为arr 的拷贝，tmp必须与arr 类型相同，也就是同为int的vector类型，tmp将具有和arr相同的容量和元素
    for (int i : arr)//循环arr中的元素，记录每个数字出现的次数
        count[i]++;
    for (int i = 1; i <= maxVal; ++i)
        count[i] += count[i - 1];//通过相加计算确定有多少元素是小于等于i的
    for (int i = len - 1; i >= 0; --i) {
        arr[count[tmp[i]] - 1] = tmp[i];//找到原数组中i位置的数，对应count中count[tep[i]-1]表示比tmp[i]小的数的个数，也是表示了他的位置
        count[tmp[i]]--;                //注意这里要减1
    }
}
 
int main()
{
    vector<int> arr = { 1,5,3,7,6,2,8,9,4,3,3 };
    int maxVal = 9;
    CountSort(arr,maxVal);
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}

