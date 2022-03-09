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

	template <class Tree_traits>
	void Tree<Tree_traits>::clear()
	{
		erase(begin(), end());
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::key_compare Tree<Tree_traits>::key_comp() const
	{
		return (Tree_traits::comp);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::value_compare Tree<Tree_traits>::value_comp() const
	{
		return (value_compare(key_comp()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::find(const key_type &Kv)
	{
		iterator P = lower_bound(Kv);
		return (P == end() || Tree_traits::comp(Kv, Key(P.Mynode())) ? end() : P);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_iterator Tree<Tree_traits>::find(const key_type &Kv) const
	{
		const_iterator P = lower_bound(Kv);
		return (P == end() || Tree_traits::comp(Kv, Key(P.Mynode())) ? end() : P);
	}

	//TODO: count always return 0
	template <class Tree_traits>
	typename Tree<Tree_traits>::size_type Tree<Tree_traits>::count(const key_type &Kv) const
	{
		PairConstIter Ans = equal_range(Kv);
		size_type N = 0;
		Distance(Ans.first, Ans.second, N);
		return (N);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::lower_bound(const key_type &Kv)
	{
		return (iterator(Lbound(Kv)));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_iterator Tree<Tree_traits>::lower_bound(const key_type &Kv) const
	{
		return (const_iterator(Lbound(Kv)));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::upper_bound(const key_type &Kv)
	{
		return (iterator(Ubound(Kv)));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_iterator Tree<Tree_traits>::upper_bound(const key_type &Kv) const
	{
		return (iterator(Ubound(Kv)));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::PairIterIter Tree<Tree_traits>::equal_range(const key_type &Kv)
	{
		return (PairIterIter(lower_bound(Kv), upper_bound(Kv)));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::PairConstIter Tree<Tree_traits>::equal_range(const key_type &Kv) const
	{
		return (PairConstIter(lower_bound(Kv), upper_bound(Kv)));
	}
}

#include "public_functions/insert.hpp"
#include "public_functions/erase.hpp"

#endif
