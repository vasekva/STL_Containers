#ifndef COLLECTIONS_PUBLIC_FUNCTIONS_HPP
#define COLLECTIONS_PUBLIC_FUNCTIONS_HPP

#include "xtree_prototypes.hpp"
#include "../algorithm/swap.hpp"

namespace ft
{
	template <class Tree_traits>
	typename Tree<Tree_traits>::allocator_type  Tree<Tree_traits>::get_allocator() const
	{
		return (this->Alval);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::size_type Tree<Tree_traits>::size() const
	{
		return (Size);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::size_type Tree<Tree_traits>::max_size() const
	{
		return (this->Alval.max_size());
	}

	template <class Tree_traits>
	bool  Tree<Tree_traits>::empty() const
	{
		return (size() == 0);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::swap(Tree<Tree_traits> &X)
	{
		if (get_allocator() == X.get_allocator())
		{
			ft::swap(Tree_traits::comp, X.comp);
			ft::swap(Head, X.Head);
			ft::swap(Size, X.Size);
		}
		else
		{
			Tree<Tree_traits> tmp = *this; *this = X, X = tmp;
		}
	}
}

#include "public_functions/insert.hpp"
#include "public_functions/erase.hpp"

#endif
