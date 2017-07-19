#include <windows.h>
#include <cstdlib>
#include <iostream>
#include "MyDll.h"

// using pfGetInst = MyDllBase* (*)()
// pfGetInst 是一个指针，指向一个函数，这个函数返回 MyDllBase 的指针
typedef MyDllBase* (*pfGetInst)();

int main()
{
	HMODULE hMod = LoadLibrary("MyDll.dll");
	if (hMod) {
		pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
		if (pfGetInstance) {
			// 通过基类指针指向了派生类的对象
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