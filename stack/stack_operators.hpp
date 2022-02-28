#ifndef COLLECTIONS_STACK_OPERATORS_HPP
#define COLLECTIONS_STACK_OPERATORS_HPP

#include "stack_template.hpp"

namespace ft
{
	//TODO: maybe not need to use Eq and Lt???

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
