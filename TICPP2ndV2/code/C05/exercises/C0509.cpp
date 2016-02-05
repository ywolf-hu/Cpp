#include <iostream>

using namespace std;

template <typename T> class testClass
{
	T member;
public:
	testClass(T p_value){
		member = p_value;
	}
	friend ostream& operator<<(ostream& p_os, testClass<T>& p_testClass)
	{
		p_os << "T" << endl;
		return p_os << p_testClass.member << endl;
	}
};

template <typename T> class testClass<T*>
{
	T* member;
public:
	testClass(T* p_value){
		member = p_value;
	}
	friend ostream& operator<<(ostream& p_os, testClass<T*>& p_testClass)
	{
		p_os << "T*" << endl;
		return p_os << *p_testClass.member << endl;
	}
};

class sampleClass
{
public:
	static int i;
	static int func(int p_arg);
};

int sampleClass::func(int p_arg)
{
	return p_arg;
}

int sampleClass::i = 1;

template<typename T, typename U> class testClassS
{
	U* member;
public:
	testClassS(U* p_value){
		member = p_value;
	}
	friend ostream& operator<<(ostream& p_os, testClassS<T, U>& p_testClass)
	{
		p_os << "T::U*" << endl;
		return p_os << *p_testClass.member << endl;
	}
};

template<typename R, typename A> class testClassF
{
	// R(T::*member)(A);
	R(*member)(A);
	A arg;
public:
	testClassF(R(*f)(A), A p_arg){
		member = f;
		arg = p_arg;
	}

	A getArg()
	{
		return arg;
	}

	friend ostream& operator<<(ostream& p_os, testClassF<R, A>& p_testClass)
	{
		p_os << "R(*f)(A)" << endl;
		return p_os << (*p_testClass.member)(p_testClass.getArg()) << endl;
	}
};

int main()
{
	testClass<int> l_testClass = testClass<int>(1);
	cout << l_testClass;

	int l_testInt = 2;
	testClass<int*> l_testClassP = testClass<int*>(&l_testInt);
	cout << l_testClassP;

	testClassS<sampleClass, int> l_testClassS = testClassS<sampleClass, int>(&sampleClass::i);
	cout << l_testClassS;

	// sampleClass l_sampleClass = sampleClass();
	testClassF<int, int> l_testClassF = testClassF<int, int>(sampleClass::func, 10);
	cout << l_testClassF;
	return 0;
}