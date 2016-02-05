#include <iostream>

using namespace std;

template <typename U> class Friendly;
template <typename U> class Pickey;

template<typename T> class Bob
{
public:
	template<typename U> void print(Friendly<U>& p_friendly)
	{
		cout << p_friendly.i << endl;
	}

	void print(Pickey<T>& p_pickey)
	{
		cout << p_pickey.i << endl;
	}
};

template<typename T> class Friendly
{
	T i;
	template<typename U> friend class Bob;
public:
	Friendly(T p_args)
	{
		i = p_args;
	}
};

template<typename T> class Pickey
{
	T i;
	friend class Bob<T>;
public:
	Pickey(T p_args)
	{
		i = p_args;
	}
};

int main()
{
	Bob<int> l_Bob;
	Friendly<char> l_friendly('L');
	l_Bob.print(l_friendly);

	Pickey<int> l_pickey(99);
	l_Bob.print(l_pickey);

	return 0;
}