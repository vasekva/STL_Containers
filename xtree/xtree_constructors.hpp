#ifndef COLLECTIONS_XTREE_CONSTRUCTORS_HPP
#define COLLECTIONS_XTREE_CONSTRUCTORS_HPP

#include "xtree_prototypes.hpp"

namespace ft
{

	template <class Tree_traits>
	Tree<Tree_traits>::Tree(const key_compare &Parg, const allocator_type &Al)
			: Mybase(Parg, Al)
	{
		std::cout << "xtree_constructors_Tree" << std::endl;
		Init();
	}

//	template <class Tree_traits>
//	Tree<Tree_traits>::Tree(const value_type *F, const value_type *L,
//		const key_compare &Parg, const allocator_type &Al) : _baseTree(Parg, Al)
//	{
//			Init();
//			insert(F, L);
//	}

//	template <class Tree_traits>
//	Tree<Tree_traits>::Tree(const Myt &X)
//		: _baseTree(X.key_comp(), X.get_allocator())
//	{
//		init();
//		Copy(X);
//	}
//
	template <class Tree_traits>
	Tree<Tree_traits>::~Tree()
	{
		erase(begin(), end());
		Freenode(Head);
		Head = 0, Size = 0;
	}
}

#endif
