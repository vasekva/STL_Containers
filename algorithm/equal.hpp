#ifndef FT_EQUAL
# define FT_EQUAL

namespace ft
{
	template <class InIt1, class InIt2> inline
	bool equal(InIt1 F, InIt1 L, InIt2 X)
	{
		return (ft::mismatch(F, L, X).first == L);
	}

	template <class InIt1, class InIt2, class Pr> inline
	bool equal(InIt1 F, InIt1 L, InIt2 X, Pr P)
	{
		return (ft::mismatch(F, L, X, P).first == L);
	}
}

#endif