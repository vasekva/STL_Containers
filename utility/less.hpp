#ifndef LESS_HPP
#define LESS_HPP

namespace ft
{
	template<class T1, class T2, class result>
	struct binary_function
	{
		typedef T1		first_argument_type;
		typedef T2		second_argument_type;
		typedef result	result_type;
	};

	template <class T>
	struct less : public binary_function<T, T, bool>
	{
		bool operator()(const T &X, const T &Y) const
		{
			return (X < Y);
		}
	};

}

#endif