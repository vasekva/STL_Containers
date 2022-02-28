#ifndef COLLECTIONS_STACK_REALIZATION_HPP
#define COLLECTIONS_STACK_REALIZATION_HPP

#include "stack_template.hpp"

namespace ft
{
	template <class Type, class Container>
	stack<Type, Container>::stack() : container() {}

	template <class Type, class Container>
	stack<Type, Container>::stack(const Container &Cont)
		: container(Cont)
	{}

	template <class Type, class Container>
	bool stack<Type, Container>::empty() const
	{
		return (container.empty());
	}

	template <class Type, class Container>
	typename stack<Type, Container>::size_type stack<Type, Container>::size() const
	{
		return (container.size());
	}

	template <class Type, class Container>
	typename stack<Type, Container>::reference stack<Type, Container>::top()
	{
		return (container.back());
	}

	template <class Type, class Container>
	typename stack<Type, Container>::const_reference stack<Type, Container>::top() const
	{
		return (container.back());
	}

	template <class Type, class Container>
	void stack<Type, Container>::push(const value_type &X)
	{
		container.push_back(X);
	}

	template <class Type, class Container>
	void stack<Type, Container>::pop()
	{
		container.pop_back();
	}

	//TODO:: is this correct??
	template <class Type, class Container>
	void stack<Type, Container>::swap(stack<Type, Container> &another_one)
	{
		container.swap(another_one.container);
	}

	template <class Type, class Container>
	bool stack<Type, Container>::Eq(const stack<Type, Container> &X) const
	{
		return (container == X.container);
	}

	template <class Type, class Container>
	bool stack<Type, Container>::Lt(const stack<Type, Container> &X) const
	{
		return (container < X.container);
	}
}

#include "stack_operators.hpp"

#endif
