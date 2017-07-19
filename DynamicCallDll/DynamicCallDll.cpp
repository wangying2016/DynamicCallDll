#include <windows.h>
#include <cstdlib>
#include <iostream>
#include "MyDll.h"

// using pfGetInst = MyDllBase* (*)()
// pfGetInst ��һ��ָ�룬ָ��һ������������������� MyDllBase ��ָ��
typedef MyDllBase* (*pfGetInst)();

int main()
{
	HMODULE hMod = LoadLibrary("MyDll.dll");
	if (hMod) {
		pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
		if (pfGetInstance) {
			// ͨ������ָ��ָ����������Ķ���
			MyDllBase* pInst = pfGetInstance();
			if (NULL != pInst) {
				pInst->hello();
			}
			if (NULL == pInst) {
				std::cout << "Dinamic call MyDll failed T_T" << std::endl;
				delete pInst;
			}
		}
	}
	system("pause");
	return 0;
}