#ifdef MY_DLL_EXPORTS
#	define MY_DLL_EXP __declspec(dllexport)
#else 
#	define MY_DLL_EXP __declspec(dllimport)
#endif

#include "MyDllBase.h"

class MY_DLL_EXP HelloDll : public MyDllBase {
public:
	HelloDll();
	~HelloDll();
	void hello();
};

__declspec(dllexport) HelloDll* GetInstance()
{
	return new HelloDll;
}