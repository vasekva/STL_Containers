#ifndef FT_ITER_DISTANCE_HPP
#define FT_ITER_DISTANCE_HPP

namespace ft
{
	template <class InIt> inline
	typename ft::iterator_traits<InIt>::difference_type distance(InIt F, InIt L)
	{
		typename ft::iterator_traits<InIt>::difference_type N = 0;
		Distance2(F, L, N, ft::Iter_cat(F));
		return (N);
	}

	template <class InIt, class D> inline
	void Distance(InIt F, InIt L, D &N)
	{
		Distance2(F, L, N, ft::Iter_cat(F));
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D &N, input_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D &N, forward_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D &N, bidirectional_iterator_tag)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D &N, random_access_iterator_tag)
	{
		N += L - F;
	}

	template <class InIt, class D> inline
	void Distance_Tree(InIt F, InIt L, D &N)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}
}

#endif