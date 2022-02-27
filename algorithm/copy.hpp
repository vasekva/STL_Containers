#ifndef FT_COPY
# define FT_COPY

namespace ft
{
	template <class InIt, class OutIt> inline
	OutIt copy(InIt First, InIt Last, OutIt X)
	{
		for (; First != Last; ++X, ++First)
		{
			*X = *First;
		}
		return (X);
	}

	template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward(BidIt1 First, BidIt1 Last, BidIt2 X)
	{
		while (First != Last)
		{
			*--X = *--Last;
		}
		return (X);
	}
}

#endif