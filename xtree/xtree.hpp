#ifndef COLLECTIONS_XTREE_HPP
#define COLLECTIONS_XTREE_HPP

#include "xtree_prototypes.hpp"

namespace ft
{

///**
//=================================
//==   TEMPLATE CLASS Tree_node  ==
//=================================
//*/
//
//	template <class Tree_traits>
//	class Tree_node : public Tree_traits
//	{
//		protected:
//			typedef typename Tree_traits::allocator_type	allocator_type;
//			typedef typename Tree_traits::key_compare		key_compare;
//			typedef typename Tree_traits::value_type		value_type;
//
//			typedef typename allocator_type::template
//				rebind<void>::other::pointer GenPtr;
//
//			struct Node
//			{
//				GenPtr Left, Parent, Right;
//				value_type Value;
//				char Color, Isnil;
//			};
//
//			Tree_node(const key_compare &Parg, allocator_type Al)
//				: Tree_traits(Parg), Alnode(Al) {}
//
//			typename allocator_type::template
//				rebind<Node>::other Alnode;
//	};
//
///**
//=================================
//==   TEMPLATE CLASS Tree_ptr   ==
//=================================
//*/
//
//	template <class Tree_traits>
//	class Tree_ptr : public Tree_node<Tree_traits>
//	{
//		protected:
//			typedef typename Tree_node<Tree_traits>::Node	Node;
//			typedef typename Tree_traits::allocator_type	allocator_type;
//			typedef typename Tree_traits::key_compare		key_compare;
//
//			typedef typename allocator_type::template
//				rebind<Node>::other::pointer	nodePtr;
//
//			Tree_ptr(const key_compare &Parg, allocator_type Alloc)
//				: Tree_node<Tree_traits>(Parg, Alloc), Alptr(Alloc) {}
//
//			typename allocator_type::template
//				rebind<nodePtr>::other Alptr;
//	};
//
///**
//=================================
//==   TEMPLATE CLASS Tree_val   ==
//=================================
//*/
//	template <class Tree_traits>
//	class Tree_val : public Tree_ptr<Tree_traits>
//	{
//		public:
//			typedef typename Tree_traits::allocator_type	allocator_type;
//			typedef typename Tree_traits::key_compare		key_compare;
//
//			Tree_val(const key_compare &Parg, allocator_type Alloc)
//				: Tree_ptr<Tree_traits>(Parg, Alloc), Alval(Alloc) {}
//
//		private:
//			allocator_type Alval;
//	};

/**
=================================
==     TEMPLATE CLASS Tree     ==
=================================
*/

//	template <class Tree_traits>
//	class Tree : public Tree_val<Tree_traits>
//	{

//		public:
//			typedef typename Tree_traits::key_type			key_type;
//			typedef typename Tree_traits::value_type		value_type;
//			typedef typename Tree_traits::key_compare		key_compare;
//			typedef typename Tree_traits::value_compare		value_compare;
//			typedef typename Tree_traits::allocator_type	allocator_type;
//
//		private:
//			typedef typename allocator_type::difference_type		Dift;
//			typedef typename allocator_type::template
//				rebind<value_type>::other::pointer					Tptr;
//			typedef typename Tree_node<Tree_traits>::Node			Node;
//			typedef typename allocator_type::template
//				rebind<Node>::other::pointer						NodePtr;
//			typedef typename allocator_type::template
//				rebind<value_type>::other::const_pointer			Ctptr;
//			typedef typename allocator_type::template
//				rebind<value_type>::other::reference				Reft;

//			typedef Bidit<value_type, Dift, Ctptr, const_refrence>	BaseIter;

//		public:
//			typedef typename allocator_type::size_type			size_type;
//			typedef Dift	difference_type;
//			typedef Tptr	pointer;
//			typedef Ctptr	const_pointer;
//			typedef Reft	reference;
//			typedef typename allocator_type::template
//				rebind<value_type>::other::const_reference		const_reference;

//			explicit Tree(const key_compare &Parg, const allocator_type &Al)
//				: Tree_val<Tree_traits>(Parg, Al)
//			{
//				Init();
//			}
}

#endif