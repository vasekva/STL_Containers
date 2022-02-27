#ifndef FT_lexicographical_compare
# define FT_lexicographical_compare

namespace ft
{
	template<class InIt1, class InIt2> inline
	bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2)
	{
		for (; F1 != L1 && F2 != L2; ++F1, ++F2)
			if (*F1 < *F2)
				return (true);
			else if (*F2 < *F1)
				return (false);
		return (F1 == L1 && F2 != L2);
	}

	template<class InIt1, class InIt2, class Pr> inline
	bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2, Pr P)
	{
		for (; F1 != L1 && F2 != L2; ++F1, ++F2)
			if (P(*F1, *F2))
				return (true);
			else if (P(*F2, *F1))
				return (false);
		return (F1 == L1 && F2 != L2);
	}
}

#endif