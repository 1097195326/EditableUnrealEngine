// TestCPP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Reflect.h"
#include "G_Object.h"

#include <functional>


//class TestRR : public G_Object{};
//REGISTER(TestRR);

typedef function<void(char*)> CallBack;
class MakeFunc
{
public:
	template<typename T>
	static CallBack MakeCallBack(T * _obj, void(T::*_func)(char*))
	{
		CallBack cb = CallBack(std::bind(_func, _obj, std::placeholders::_1));
		return cb;
	}
};
class TestFunc
{
public:
	CallBack m_cb;
public:
	TestFunc()
	{
		m_cb = MakeFunc::MakeCallBack(this, &TestFunc::Show);
	}
	void Show(char * str)
	{
		printf("zhx : show : %s\n", str);
	}
};




int main()
{
	/*TestRR* a = (TestRR*)ReflectManager::Get()->GetClassByName("TestRR");
	a->ShowObjectIndex();
	TestRR* r = (TestRR*)ReflectManager::Get()->GetClassByName("TestRR");
	r->ShowObjectIndex();*/

	TestFunc tf;
	tf.m_cb("hello world");

    return 0;
}

