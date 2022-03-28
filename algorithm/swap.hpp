#ifndef FT_SWAP_HPP
# define FT_SWAP_HPP

namespace ft
{
	template <class T> inline
	void swap(T &X, T &Y)
	{
		T Tmp = X;
		X = Y, Y = Tmp;
	}
}

#endif