#ifndef FT_FILL
# define FT_FILL

namespace ft
{
	template <class FwdIt, class T> inline
	void fill(FwdIt First, FwdIt Last, const T &X)
	{

		for (; First != Last ; ++First)
			*First = X;
	}

	template <class OutIt, class Sz, class T> inline
	void fill_n(OutIt First, Sz N, const T &X)
	{

		for (; 0 < N ; --N, ++First)
			*First = X;
	}
}

#endif 