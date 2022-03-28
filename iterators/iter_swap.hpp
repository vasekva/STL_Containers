#ifndef FT_ITER_SWAP_HPP
# define FT_ITER_SWAP_HPP

namespace ft
{
	template <class FwdIt1, class FwdIt2, class T> inline
	void Iter_swap(FwdIt1 X, FwdIt2 Y, T *)
	{
		T tmp = *X;
		*X = *Y;
		*Y = tmp;
	}
	
	template <class FwdIt1, class FwdIt2> inline
	void iter_swap(FwdIt1 X, FwdIt2 Y)
	{
		Iter_swap(X, Y, Val_type(X));
	}

}

#endif