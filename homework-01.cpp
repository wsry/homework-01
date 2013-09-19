//下面程序针对一维数组一维数组
#include<iostream>
#include<fstream>
using namespace std;

int find_max(int *src_arr,int *max_arr,int *max_startindex_arr,int len){
	int max_index=0;
	for (int i = 1; i < len; i++)
	{
		if (max_arr[i-1]>=0)
		{
			max_arr[i]=max_arr[i-1]+src_arr[i];
			max_startindex_arr[i]=max_startindex_arr[i-1];
			if (max_arr[i]>max_arr[max_index])
			{
				max_index=i;
			}
		}else
		{
			max_arr[i]=src_arr[i];
			max_startindex_arr[i]=i;
			if (max_arr[i]>max_arr[max_index])
			{
				max_index=i;
			}
		}
	}
	return max_index;
}
int main(int argc,char *argv[]){
	int element_num=-1;                //数组元素个数
	int max_index=0;                         //最大值索引
	char tmp;
	ifstream my_cin;
	int *src_arr;                      //输入数据数组
	int *max_arr;                      //保存当前最大值的数组
	int *max_startindex_arr;           //保存最大值范围的起始索引
	if(argc!=2){
		cout<<"命令行格式错误！";
		return 0;
	}else{
		my_cin.open(argv[1]);
	}
	if(!my_cin.is_open()){
		cout<<"打开输入文件失败！";
		return 0;
	}else{
		if(!(my_cin >> element_num)){
			cout<<"文件格式错误，无法确定输入数据个数！";
			my_cin.close();
			return 0;
		}
		if(element_num==0){
			cout<<"原始数据个数为0！";
			my_cin.close();
			return 0;
		}
		src_arr = new int[element_num];
		max_arr = new int[element_num];
		max_startindex_arr = new int[element_num];

		for (int i = 0; i < element_num; i++)
		{
			my_cin>>tmp;
			if (tmp!=','||!(my_cin>>src_arr[i]))
			{
				cout<<"文件格式错误！";
				my_cin.close();
				return 0;
			}
		}
		my_cin.close();
		max_arr[0]=src_arr[0];
		max_startindex_arr[0]=0;
	}

	max_index = find_max(src_arr,max_arr,max_startindex_arr,element_num);

	cout<<"最大值："<<max_arr[max_index]<<endl;
	cout<<"首次出现范围："<<max_startindex_arr[max_index]<<" -- "<<max_index<<endl;

	return 0;
}