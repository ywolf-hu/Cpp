#include <iostream>
#include <typeinfo>

using namespace std;
template <typename T> T sum(T p_array[], int p_startIndex, int p_endIndex, T p_initVal=T())
{
	auto l_sum = p_initVal;
	cout << "l_sum: " << l_sum << endl;
	for (auto i=p_startIndex; i<=p_endIndex; i++)
	{
		l_sum += p_array[i];
	}
	return l_sum;
}

int main()
{
	int l_itestArray[10] = {1,2,3};
	auto l_isum = sum(l_itestArray, 0, 100000, 5);
	cout << "int array: " << l_isum << endl;

	float l_ftestArray[3] = {1.0,2.0,3.0};
	auto l_initVal = 5.0;
	cout << "l_initVal is: " << typeid(l_initVal).name() << endl;
	auto l_fsum = sum(l_ftestArray, 0, 3, (float)l_initVal);
	cout << "l_fsum is: " << typeid(l_fsum).name() << endl;
	cout << "float array: " << l_fsum << endl;
}