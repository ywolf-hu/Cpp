/*******************************************************************************
* @file
* @version
* @date                  2016
* @author                linhu (hlf0312@gmail.com)
*
* @module
*******************************************************************************/
#include <iostream>
#include <typeinfo>

using namespace std;
template <typename T> void unaryFunction(T p_Para)
{
	cout << "Template version for function" << endl;
	cout << "T is type of " << typeid(T).name() << endl;
	cout << p_Para << endl;
	return;
}

template <> void unaryFunction<int>(int p_Para)
{
	cout << "Specilation version for function" << endl;
	cout << p_Para << endl;
}

void unaryFunction(int p_Para)
{
	cout << "Normal version for function" << endl;
	cout << p_Para << endl;
}


int main()
{
	unaryFunction(1);
	unaryFunction<>(1);
	unaryFunction<>(2.0);
	return 0;
}