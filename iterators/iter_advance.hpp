#ifndef FT_ITER_ADVANCE
# define FT_ITER_ADVANCE

namespace ft
{
	template <class InIt, class D> inline
	void advance(InIt &I, D N)
	{
		Advance(I, N, Iter_cat(I));
	}
		
	template <class InIt, class D> inline
	void Advance(InIt &I, D N, input_iterator_tag)
	{
		for (; 0 < N; --N)
			++I;
	}
		
	template <class FwdIt, class D> inline
	void Advance(FwdIt &I, D N, forward_iterator_tag)
	{
		for (; 0 < N; --N)
			++I;
	}
		
	template <class BidIt, class D> inline
	void Advance(BidIt &I, D N, bidirectional_iterator_tag)
	{
		for (; 0 < N; --N)
			++I;
		for (; N < 0; ++N)
			--I;
	}
	
	template <class RanIt, class D> inline
	void Advance(RanIt &I, D N, random_access_iterator_tag)
	{
		I += N;
	}
}

#endif