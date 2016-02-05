#include <iostream>

using namespace std;

template<typename T, typename U> class testClass
{
	T i;
	U j;
public:
	testClass(T p_Arg1, U p_Arg2)
	{
		i = p_Arg1;
		j = p_Arg2;
	}
	friend ostream& operator<<(ostream& p_os, testClass<T,U>& p_testClass)
	{
		return p_os << "testClass" << endl << p_testClass.i << endl << p_testClass.j << endl;
	}
};

template<typename U> class testClass<int, U>
{
	int i;
	U j;
	int k;
public:
	testClass(int p_Arg1, U p_Arg2):k(11)
	{
		i = p_Arg1;
		j = p_Arg2;
	}
	friend ostream& operator<<(ostream& p_os, testClass<int,U>& p_testClass)
	{
		return p_os << "testClass1stSpec" << endl << p_testClass.i << endl << p_testClass.j << endl\
		 << p_testClass.k << endl;
	}
};

template<typename T> class testClass<T, char>
{
	T i;
	char j;
	int k;
public:
	testClass(T p_Arg1, char p_Arg2):k(22)
	{
		i = p_Arg1;
		j = p_Arg2;
	}
	friend ostream& operator<<(ostream & p_os, testClass<T, char>& p_testClass)
	{
		return p_os << "testClass2ndSpec" << endl << p_testClass.i << endl << p_testClass.j << endl\
		 << p_testClass.k << endl;
	}
};

int main()
{
	testClass<double, int> l_testClass = testClass<double, int>(1, 2);
	cout << l_testClass;

	testClass<int, int> l_testClass1 = testClass<int, int>(1, 2);
	cout << l_testClass1;

	testClass<char, char> l_testClass2 = testClass<char, char>('1', 'a');
	cout << l_testClass2;

	return 0;
}