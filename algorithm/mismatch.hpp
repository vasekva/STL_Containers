#ifndef FT_MISMATCH_HPP
# define FT_MISMATCH_HPP

# include "algorithm.hpp"

namespace ft
{
	template <class InIt1, class InIt2> inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X)
	{
		for (; F != L && *F == *X; ++F, ++X)
			;
		return (ft::pair<InIt1, InIt2>(F, X));
	}
	
	template <class InIt1, class InIt2, class Pr> inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P)
	{
		for (; F != L && P(*F, *X); ++F, ++X)
			;
		return (ft::pair<InIt1, InIt2>(F, X));
	}

};

#endif