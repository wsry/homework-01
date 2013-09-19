//����������һά����һά����
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
	int element_num=-1;                //����Ԫ�ظ���
	int max_index=0;                         //���ֵ����
	char tmp;
	ifstream my_cin;
	int *src_arr;                      //������������
	int *max_arr;                      //���浱ǰ���ֵ������
	int *max_startindex_arr;           //�������ֵ��Χ����ʼ����
	if(argc!=2){
		cout<<"�����и�ʽ����";
		return 0;
	}else{
		my_cin.open(argv[1]);
	}
	if(!my_cin.is_open()){
		cout<<"�������ļ�ʧ�ܣ�";
		return 0;
	}else{
		if(!(my_cin >> element_num)){
			cout<<"�ļ���ʽ�����޷�ȷ���������ݸ�����";
			my_cin.close();
			return 0;
		}
		if(element_num==0){
			cout<<"ԭʼ���ݸ���Ϊ0��";
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
				cout<<"�ļ���ʽ����";
				my_cin.close();
				return 0;
			}
		}
		my_cin.close();
		max_arr[0]=src_arr[0];
		max_startindex_arr[0]=0;
	}

	max_index = find_max(src_arr,max_arr,max_startindex_arr,element_num);

	cout<<"���ֵ��"<<max_arr[max_index]<<endl;
	cout<<"�״γ��ַ�Χ��"<<max_startindex_arr[max_index]<<" -- "<<max_index<<endl;

	return 0;
}