#ifndef COLLECTIONS_XTREE_ELEMENT_ACCESS_HPP
#define COLLECTIONS_XTREE_ELEMENT_ACCESS_HPP

#include "xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::begin()
	{
		return (iterator(Lmost()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_iterator Tree<Tree_traits>::begin() const
	{
		return (const_iterator(Lmost()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::end()
	{
		return (iterator(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_iterator Tree<Tree_traits>::end() const
	{
		return (const_iterator(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::reverse_iterator Tree<Tree_traits>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_reverse_iterator Tree<Tree_traits>::rbegin() const
	{
		return  (const_reverse_iterator(end()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::reverse_iterator Tree<Tree_traits>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::const_reverse_iterator Tree<Tree_traits>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}
}

#endif
