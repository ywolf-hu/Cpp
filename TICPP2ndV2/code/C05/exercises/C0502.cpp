#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;
template <typename T> class myVector
{
public:
	//customized datatype, pay attention to typename keyword
	typedef typename vector<T>::size_type size_type_t;
	void push(T p_element);
	T pop();
	size_type_t size();
	T top();
	T bottom();

private:
	vector<T> v;
};

template<typename T> void myVector<T>::push(T p_element)
{
	v.push_back(p_element);
	return;
}

template<typename T> typename myVector<T>::size_type_t myVector<T>::size()
{
	return v.size();
}

template<typename T> T myVector<T>::pop()
{
	T l_retVal = v.back();
	v.pop_back();
	return l_retVal;
}

template<typename T> T myVector<T>::top()
{
	return v.back();
}

template<typename T> T myVector<T>::bottom()
{
	return v.front();
}

int main()
{
	myVector<int> l_myVector;
	for (auto i = 0; i < 10; i++)
	{
		l_myVector.push(i);
		cout << "push " << i << " into stack" << endl;
	}
	auto l_size = l_myVector.size();
	cout << "l_size type: " << typeid(l_size).name() << endl;
	cout << "stack size: " << l_size << endl;
	cout << "stack top: " << l_myVector.top() << endl;
	cout << "stack top: " << l_myVector.bottom() << endl;

	for (auto i = l_size; i>0; i--)
	{
		cout << "pop value: " << l_myVector.pop() << endl;
	}
	cout << "after pop, size: " << l_myVector.size() << endl;
	return 0;
}