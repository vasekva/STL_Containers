#ifndef UTILITY
#define UTILITY

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;



		pair() : first(T1()), second(T2()) {}
		pair(const T1 &V1, const T2 &V2)
			: first(V1), second (V2) {}
		template <class U1, class U2>
		pair(const pair<U1, U2> &X)
				: first(X.first), second(X.second) {}

		T1 first;
		T2 second;
	};

	/**
=======================================
==         TEMPLATES FOR PAIR        ==
=======================================
*/
		template <class Type1, class Type2>
		bool operator==(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return (X.first == Y.first && X.second == Y.second);
		}

		template <class Type1, class Type2>
		bool operator!=(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return !(X == Y);
		}

		template <class Type1, class Type2>
		bool operator<(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return (X.first < Y.first || (!(Y.first < X.first) && X.second < Y.second));
		}

		template <class Type1, class Type2>
		bool operator>(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return (Y < X);
		}

		template <class Type1, class Type2>
		bool operator<=(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return !(Y < X);
		}

		template <class Type1, class Type2>
		bool operator>=(const pair<Type1, Type2> &X, const pair<Type1, Type2> &Y)
		{
			return !(X < Y);
		}

		template <class Type1, class Type2> inline
		pair<Type1, Type2> make_pair(const Type1 &X, const Type2 &Y)
		{
			return (pair<Type1, Type2>(X, Y));
		}

/**
=======================================
==             TEMPLATES             ==
=======================================
*/

}

#endif
