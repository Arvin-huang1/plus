#include "plus.h"
#include "stdio.h"
#include "linkedlist.h"
#include "iostream"
#include<python.h>
#include "opencv.hpp"
#include "new.h"
#include "set"
#include "effectiveCpp.h"
using namespace cv;
using namespace std;

void getMap(Mat &ok_ng, const string &save_path);

void main(){
	float rate = 0.2;
	int w = 1000;
	w = w*rate;
	cout << w << endl;;
	//printf_s("%d",sizeof(a));
	//letterCombinations("234");
	//getAllParentheses(4, result, current);

	//cout << parenthesesValid("))()()")<<endl;
	//fourSum(nums, target);
	//cout << threeSumClosest(nums, target) << endl;
	//cout << intToRoman(i) << endl;
	//threeSum(nums);
	//cout << myAtoi("-91283472332") << endl;
	//lengthOfLongestSubstring("abcabcbb");
	/*
	vector<int> nums1{ 1,2 };
	vector<int> nums2{ 3,4 };
	for (int i = 0; i < nums2.size(); i++)
	{
		nums1.push_back(nums2[i]);
	}
	sort(nums1.begin(), nums1.end());
	if (nums1.size() % 2 == 0)
	{
		double tt =  (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
		cout << tt<<endl;
	}
	else {
		double ttt= nums1[nums1.size() / 2];
		cout << ttt << endl;
	}*/
	/*
	char a[200];//aֻ��ָ��malloc�����ڴ���׵�ַ
	//char *b = "asd";
	int f[3] = { 1,2,3 };
	int g(33);
	vector<int> b(f, f + 4);
	vector<int>::iterator c = b.begin();
	for (int i = 0; i < 4 ; i++)
	{
		cout << b[i] << endl;
	}
	cout << g << endl;
*/	
	/*	string c = "asdasd";
	sort(c.begin(),c.end());
	ListNode ff(4.5, nullptr);
	
	ListNode *second2 = new ListNode(2.5, nullptr);
	ListNode *head = second2;
	head->value = 1.2;
	head->next = nullptr;
	ListNode *second = new ListNode(2.5,nullptr);
	head->next = second;
	second->next = &ff;
	cout << head->next->next->value << endl;
	cout << listLength(head)<< ' '<< listLength(second) << endl;
	printf("%d", my_plus(3,4));*/
	
	system("pause");
}

void getMap(Mat &ok_ng, const string &save_path)
{
	Py_SetPythonHome(L"C:\\Users\\FabXLab\\AppData\\Local\\Continuum\\anaconda3");
	Py_Initialize();//ʹ��python֮ǰ��Ҫ����Py_Initialize();����������г�ʼ��
	if (!Py_IsInitialized())
	{
		printf("��ʼ��ʧ�ܣ�");
	}


	// ����ϵ�в���
	PyObject  *pModule, *pDict;

	// ����pythonģ��.
	pModule = PyImport_ImportModule("map");

	// ģ�����ݴ���dict.
	pDict = PyModule_GetDict(pModule);

	// ��ȡpython����.
	PyObject *pFunc_map_init = PyDict_GetItemString(pDict, "map_init");
	PyObject *pFunc_map_write = PyDict_GetItemString(pDict, "map_write");
	PyObject *pFunc_map_save = PyDict_GetItemString(pDict, "map_save");

	// ������������
	PyObject *pFunc_map_init_args = PyTuple_New(2);
	PyObject *pFunc_map_write_args = PyTuple_New(4);
	PyObject *pFunc_map_save_args = PyTuple_New(1);


	// Convert 2 to a Python integer.
	PyObject *pValue_rows = PyLong_FromLong(ok_ng.rows);
	PyObject *pValue_cols = PyLong_FromLong(ok_ng.cols);

	// Set the Python int as the first and second arguments to the method.
	PyTuple_SetItem(pFunc_map_init_args, 0, pValue_rows);
	PyTuple_SetItem(pFunc_map_init_args, 1, pValue_cols);
	PyObject *pValue_row = nullptr;
	PyObject *pValue_col = nullptr;
	PyObject *pValue_val = nullptr;
	PyObject* pyList_row = PyList_New(0);           //��ʼ��һ���б�
	PyObject* pyList_col = PyList_New(0);           //��ʼ��һ���б�
	PyObject* pyList_val = PyList_New(0);           //��ʼ��һ���б�
	// ���ú���.
	PyObject_CallObject(pFunc_map_init, pFunc_map_init_args);
	int index = 0;
	for (int i = 0; i < ok_ng.rows; i++)
	{
		for (int j = 0; j < ok_ng.cols; j++)
		{
			//cout << index++ << endl;
			PyList_Append(pyList_row, Py_BuildValue("i", i+1));
			PyList_Append(pyList_col, Py_BuildValue("i", j+1));
			PyList_Append(pyList_val, Py_BuildValue("i", int(ok_ng.at<uchar>(i, j))));
		}
	}
	PyTuple_SetItem(pFunc_map_write_args, 0, pValue_rows);// ������ʽת����python��ʽ
	PyTuple_SetItem(pFunc_map_write_args, 1, pyList_row);// ������ʽת����python��ʽ
	PyTuple_SetItem(pFunc_map_write_args, 2, pyList_col);// ������ʽת����python��ʽ
	PyTuple_SetItem(pFunc_map_write_args, 3, pyList_val);// ������ʽת����python��ʽ
	PyObject_CallObject(pFunc_map_write, pFunc_map_write_args);

	PyObject *pValue_str = Py_BuildValue("s","map.xlsx");  //һ���ַ�������

	PyTuple_SetItem(pFunc_map_save_args, 0, pValue_str);
	PyObject_CallObject(pFunc_map_save, pFunc_map_save_args);
	cout << save_path<< "����ɹ���" << endl;
	// Destroy the Python interpreter.
	Py_Finalize();
}

