#include <iostream>
#include <vector>
using namespace std;
template<class T>
void selection_sort(vector<T> &vec){
    for(int i=0;i<vec.size()-1;i++){//总共要经过 N-1 轮比较

        int min=i;
        for(int j=i+1;j<vec.size();j++){//每轮需要比较的次数 N-i

            if(vec[j]<vec[min]){
                min=j;
            }
        }
        swap(vec[i],vec[min]);
    }
}


int main()
{
    int a[10] = {2,5,6,3,1,4,8,7,9,0};
    vector<int> vec(a,a+10);
    float b[6]={12.3,12.3,1.2,34.5,678.2,23.2};
    vector<float> vec1;
    for(int i=0; i<(int)sizeof(b)/sizeof(b[0]);i++){ //把数组pushback到vec中
        vec1.push_back(b[i]);
    }
    selection_sort(vec);
    selection_sort(vec1);
    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){ //使用迭代器将容器中数据输出

        cout<<*it<<" ";
    }
    cout<<endl;
    for(int i=0;i<vec1.size();i++){
           cout<<vec1[i]<<endl;
       }
       
    return 0;
    
}
