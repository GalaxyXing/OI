#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int coloum[11]={0,4,3,5,2,4,6,1,3,5,7};
bool co[15];
int main(){
    std::string s;
    cin>>s;
    s='0'+s;
    if(s[1]=='1'){
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=10;i++)s[i]-='0',co[i]=true;
    if(s[7]==0)co[coloum[7]]=false;
    if(s[4]==0)co[coloum[4]]=false;
    if(s[2]==0&&s[8]==0)co[coloum[8]]=false;
    if(s[5]==0)co[coloum[5]]=false;
    if(s[9]==0&&s[3]==0)co[coloum[3]]=false;
    if(s[6]==0)co[coloum[6]]=false;
    if(s[10]==0)co[coloum[10]]=false;
    if(!co[2]&&(co[1])&&(co[3]||co[4]||co[5]||co[6||co[7]]))return cout<<"Yes",0;
    if(!co[3]&&(co[1]||co[2])&&(co[4]||co[5]||co[6]||co[7]))return cout<<"Yes",0;
    if(!co[4]&&(co[1]||co[2]||co[3])&&(co[5]||co[6]||co[7]))return cout<<"Yes",0;
    if(!co[5]&&(co[1]||co[2]||co[3||co[4]])&&(co[6]||co[7]))return cout<<"Yes",0;
    if(!co[6]&&(co[1]||co[2]||co[3]||co[4]||co[5])&&co[7])return cout<<"Yes",0;
    cout<<"No";
    return 0;
}