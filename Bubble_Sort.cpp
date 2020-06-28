#include <iostream>
using namespace std;
template <class T>
void bubble(T arr[],int len )
{
    int i,j;
    for (i=0;i<len-1;i++){
        for(j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[]={1,3,4,2,54,23};
    float arr1[]={12.3,12.3,1.2,34.5,678.2,23.2};
    int len=(int) sizeof(arr)/sizeof(arr[0]);
    int len1=(int) sizeof(arr1)/sizeof(*arr1);
    bubble(arr,len);
    bubble(arr1, len1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<endl;
    }
    for(int i=0;i<len1;i++){
           cout<<arr1[i]<<endl;
       }
       
    return 0;
    
}

