


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
string s[20],last_cahracter,sum;
int n,maxLength,used[20]={0};
void dfs(string lastword){
    if(lastword.size()==1) {sum=lastword;}
    bool ans=0;//表示接下来是否有符合要求的单词
                                for(int i=0;i<n;i++){

                                    if(used[i]<2){  //检查这个数组是否用过两次
                                        int Nr_sameCharacter=0;
                                        for(int j=lastword.size()-1;j>=0;j--){
                                            if(lastword[j]==s[i][0]){//当该字母与当前单词首字母相同时
                                                 Nr_sameCharacter=1;
                                                 ans=1;
                                             while(lastword[j+Nr_sameCharacter]==s[i][Nr_sameCharacter])
                                                    Nr_sameCharacter++; //记录相同字母数量
                                            }
                                            if(ans&&j+Nr_sameCharacter==lastword.size()){break;}//
                                           else{ans=0;}
                                              if(ans){
                                                   int len=sum.size();
                                                sum+=s[i].substr(Nr_sameCharacter,s[i].size()-Nr_sameCharacter);
                                                used[i]++;
                                                dfs(s[i]);
                                                ans=0; //恢复
                                                used[i]--;
                                            sum.erase(len,s[i].size()-Nr_sameCharacter); //删去sum中len位置起的s[i].size()-m个字符(恢复原单词)
                                                        }
                                        }
                                                 }
                                }
 
    
    
    
    //记录最大长度
   if(!ans&&sum.size()>maxLength){//ans表示接下来是否有符合要求的单词
       maxLength=sum.size();
   }
    return;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>last_cahracter;
    dfs(last_cahracter);
    cout<<maxLength<<endl;
    return 0;
}
