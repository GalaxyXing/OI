#include<bits/stdc++.h>
#include<windows.h>
int main(){
	int lim=2,ok=0;
	//system("cmd");
	//system("echo QAQ");
	//system("pause");
	for(int i=1;;i++){
		printf("%d\n",i);
		system("E:\\code\\xing_cpp_file\\Data.exe");
		double begin=clock();
		system("E:\\code\\xing_cpp_file\\class\\P2519.exe");
		double end=clock();
		double ytime=end-begin;
		begin=clock();
		system("E:\\code\\xing_cpp_file\\test\\P2519.exe");
		end=clock();
		double stdtime=end-begin;
		if(system("fc dp.out dp.ans")){
			printf("WA on #%d\t",i);
			system("pause");
		}else if(ytime>1000){
			printf("TLE on #%d\t",i);
		}else {
			printf("AC on #%d\t",i);
			ok++;
		}
		printf("std��ʱ:%.0lfms\t�����ʱ:%.0lfms\n",stdtime,ytime);
		Sleep(500);
	}
	printf("�ܹ�%d�� ��ȷ%d��.\n",lim,ok);
	return 0;
}