#ifndef FT_STACK_OPERATORS_HPP
#define FT_STACK_OPERATORS_HPP

#include "stack_template.hpp"

namespace ft
{
	template <class Type, class Container> inline
	bool operator==(const ft::stack<Type, Container> &X,
			const ft::stack<Type, Container> &Y)
	{
		return (X.Eq(Y));
	}

	template <class Type, class Container> inline
	bool operator!=(const ft::stack<Type, Container> &X,
					const ft::stack<Type, Container> &Y)
	{
		return (!(X == Y));
	}

	template <class Type, class Container> inline
	bool operator<(const ft::stack<Type, Container> &X,
					const ft::stack<Type, Container> &Y)
	{
		return (X.Lt(Y));
	}

	template <class Type, class Container> inline
	bool operator>(const ft::stack<Type, Container> &X,
				   const ft::stack<Type, Container> &Y)
	{
		return (Y < X);
	}

	template <class Type, class Container> inline
	bool operator<=(const ft::stack<Type, Container> &X,
				   const ft::stack<Type, Container> &Y)
	{
		return (!(Y < X));
	}

	template <class Type, class Container> inline
	bool operator>=(const ft::stack<Type, Container> &X,
				   const ft::stack<Type, Container> &Y)
	{
		return (!(X < Y));
	}
}

#endif
