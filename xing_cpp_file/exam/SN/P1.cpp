#include<iostream>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
using namespace std; 
int n;
map<string,string>libr;
unordered_map<string,bool>tag;
void add(string key,string val){
    libr[key]=val;
    tag[key]=false;
}
void pop(string key){
    libr.erase(key);
    tag.erase(key);
}
bool check(char x){
    if(x>='a'&&x<='z')return true;
    if(x>='A'&&x<='Z')return true; 
    if(x>='0'&&x<='9')return true;
    if(x=='_')return true;
    return false;
}
string execute(string val){
    string sub="",re="";val+=' ';
    int size=val.size();
    for(int i=0;i<size;i++){
        if(check(val[i]))sub+=val[i];
        else {
            if(libr.count(sub)==1){
                if(tag[sub]==false){
                    tag[sub]=true;
                    string tmp=execute(libr[sub]);
                    tag[sub]=false;
                    sub=tmp;
                }
            }
            re+=(sub+val[i]);
            sub="";
        }
    }
    if(re[re.size()-1]==' ')re=re.substr(0,re.size()-1);
    return re;
}
void divide(int x,string ori){
    string def="chushihua",macro="chushihua",val;
    int st=0,len=0,flag=0;
    for(int i=0;i<ori.size();i++){
        if(flag>1||ori[0]!='#')break;     
        if(ori[i]!=' ') len++;  
        else if(ori[i]==' '){
            if(flag==0){
                def=ori.substr(st,len);
                if(def!="#define"&&def!="#undef")break;
                else st=i+1,flag++,len=0;                
            }else if(flag==1){
                macro=ori.substr(st,len);
                st=i+1;
                flag++;
            }            
        } 
    }
    ori=ori.substr(0,ori.size()-1);
    if(st<ori.size())val=ori.substr(st);
    if(def=="#define"){
        add(macro,val);
    }else if(def=="#undef"){
        pop(macro);
    }else{
        cout<<execute(val);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;string tmp;
    getline(cin,tmp);
    for(int i=1;i<=n;i++){        
        getline(cin,tmp);
        tmp+=' ';
        divide(i,tmp);
    }
    return 0;
}