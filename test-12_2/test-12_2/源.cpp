#include <windows.h>

void TestWC(size_t n)
{
	Person* p;
	WashRoom wc;
	for (size_t i = 0; i < n; ++i)
	{
		if (rand() % 2)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->GoToWC(wc);
		delete p;

		Sleep(3000);
	}
}

int main()
{
	// Person p; // �����಻��ʵ��������
	//Man m;

	TestWC(10);
	return 0;
}
#endif

#if 0
class Base
{
public:
	// 	Base()
	// 	{}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}


	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}
public:
	int _d;
};




// ����ָ�����
//void (*PVFT)();

// ����ָ������
typedef void(*PVFT)();

int main()
{
	cout << sizeof(Base) << endl;

	cout << sizeof(Derived) << endl;

	Base b;
	b._b = 1;


	Derived d;
	d._b = 1;
	d._d = 2;

	// ��Ҫ��ȡ���ĵ�ַ������ǰ4���ֽ�
	//&d;  // ������׵�ַ
	//(int*)(&d)  // ����ָ��--->ָ������ǰ4���ֽ�
	// *(int*)(&d)--->������ǰ4���ֽ��е�����ȡ��--->�������ݡ�===������ַ--�����������
	PVFT* pVFT = (PVFT*)(*(int*)(&d));
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}

	return 0;
}
#endif
