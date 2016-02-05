#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;
template <typename T, template<typename U, typename=allocator<U> > class container=vector > class myStack
{
public:
	//customized datatype, pay attention to typename keyword
	typedef typename container<T>::size_type size_type_t;
	void push(T p_element)
	{
		v.push_back(p_element);
		return;
	}
/*	T pop();
	size_type_t size();
	T top();
	T bottom();
*/
private:
	container<T> v;
};

/*template<typename T> typename myStack<T>::size_type_t myStack<T>::size()
{
	return v.size();
}

template<typename T> T myStack<T>::pop()
{
	T l_retVal = v.back();
	v.pop_back();
	return l_retVal;
}

template<typename T> T myStack<T>::top()
{
	return v.back();
}

template<typename T> T myStack<T>::bottom()
{
	return v.front();
}
*/
int main()
{
	// myStack<int, vector> l_myStack;
	myStack<int> l_myStack;
	for (auto i = 0; i < 10; i++)
	{
		l_myStack.push(i);
		cout << "push " << i << " into stack" << endl;
	}
/*	auto l_size = l_myStack.size();
	cout << "l_size type: " << typeid(l_size).name() << endl;
	cout << "stack size: " << l_size << endl;
	cout << "stack top: " << l_myStack.top() << endl;
	cout << "stack top: " << l_myStack.bottom() << endl;

	for (auto i = l_size; i>0; i--)
	{
		cout << "pop value: " << l_myStack.pop() << endl;
	}
	cout << "after pop, size: " << l_myStack.size() << endl;
*/	return 0;
}