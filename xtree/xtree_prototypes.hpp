#ifndef COLLECTIONS_XTREE_PROTOTYPES_HPP
#define COLLECTIONS_XTREE_PROTOTYPES_HPP

#include "../algorithm/lexicographical_compare.hpp"
#include "../utility/pair.hpp"
#include "../iterators/iterator.hpp"

namespace ft
{

//	template <class tree_traits>
//	class iterator_pointers;

//	template <class tree_traits>
//	class iterator_tree;

//	template <class tree_traits>
//	class const_iterator_tree;

/**
=================================
==   TEMPLATE CLASS Tree_nod   ==
=================================
*/
	template <class Tree_traits>
	class Tree_node : public Tree_traits
	{
		protected:
			typedef typename Tree_traits::allocator_type	allocator_type;
			typedef typename Tree_traits::key_compare		key_compare;
			typedef typename Tree_traits::value_type		value_type;

			typedef typename allocator_type::template
			rebind<void>::other::pointer Genptr;

			struct Node
			{
				Genptr Left, Parent, Right;
				value_type Value;
				char Color, Isnil;
			};

			Tree_node(const key_compare &Parg, allocator_type Al)
					: Tree_traits(Parg), Alnod(Al) {}

			typename allocator_type::template
			rebind<Node>::other Alnod;
	};

/**
=================================
==   TEMPLATE CLASS Tree_ptr   ==
=================================
*/
	template <class Tree_traits>
	class Tree_ptr : public Tree_node<Tree_traits>
	{
		protected:
			typedef typename Tree_node<Tree_traits>::Node	Node;
			typedef typename Tree_traits::allocator_type	allocator_type;
			typedef typename Tree_traits::key_compare		key_compare;

			typedef typename allocator_type::template
				rebind<Node>::other::pointer	nodePtr;

			Tree_ptr(const key_compare &Parg, allocator_type Alloc)
					: Tree_node<Tree_traits>(Parg, Alloc), Alptr(Alloc) {}
			typename allocator_type::template
				rebind<nodePtr>::other Alptr;
	};

/**
=================================
==   TEMPLATE CLASS Tree_val   ==
=================================
*/
	template <class Tree_traits>
	class Tree_val : public Tree_ptr<Tree_traits>
	{
		public:
			typedef typename Tree_traits::allocator_type	allocator_type;
			typedef typename Tree_traits::key_compare		key_compare;

			Tree_val(const key_compare &Parg, allocator_type Alloc)
					: Tree_ptr<Tree_traits>(Parg, Alloc), Alval(Alloc) {}

			allocator_type Alval;
	};
/**
=================================
==     TEMPLATE CLASS Tree     ==
=================================
*/
	template <class Tree_traits>
	class Tree : public Tree_val<Tree_traits>
	{
		public:
			typedef typename Tree_traits::key_type			key_type;
			typedef typename Tree_traits::value_type		value_type;
			typedef typename Tree_traits::key_compare		key_compare;
			typedef typename Tree_traits::value_compare		value_compare;
			typedef typename Tree_traits::allocator_type	allocator_type;

		private:
			typedef Tree<Tree_traits>	Myt;
			typedef Tree_val<Tree_traits>	Mybase;

			typedef typename allocator_type::difference_type	Dift;
			typedef typename allocator_type::template
				rebind<value_type>::other::pointer				Tptr;
			typedef typename Tree_node<Tree_traits>::Node		Node;
		public:
			typedef typename allocator_type::template
				rebind<Node>::other::pointer					Nodeptr;
			typedef typename allocator_type::template
				rebind<Node>::other::const_pointer				NodeptrConst;
		private:
			typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer		Ctptr;
			typedef typename allocator_type::template
				rebind<value_type>::other::reference			Reft;

		public:
			typedef typename allocator_type::size_type			size_type;
			typedef Dift	difference_type;
			typedef Tptr	pointer;
			typedef Ctptr	const_pointer;
			typedef Reft	reference;
			typedef typename allocator_type::template
			rebind<value_type>::other::const_reference		const_reference;
//			typedef iterator_tree<Tree_traits>				iterator;
//			typedef const_iterator_tree<Tree_traits>		const_iterator;





			explicit Tree(const key_compare &Parg, const allocator_type &Al);
			Tree(const value_type *First, const value_type *Last,
				 const key_compare &Parg, const allocator_type &Al);
			Tree(const Myt &X);
			~Tree();

			Myt &operator=(const Myt &X)
			{
				if (this != &X)
				{
					erase(begin(), end());
					Tree_traits::comp = X.comp;
					Copy(X);
				}
				return (*this);
			}

	protected:
			enum NodeColors {Red, Black};
//			typedef typename Tree_node<Tr>::Genptr	Genptr;
//			enum Redbl { Red, Black };
			typedef typename allocator_type::template
				rebind<Nodeptr>::other::reference			Nodepref;
			typedef typename allocator_type::template
				rebind<key_type>::other::const_reference	Keyref;
			typedef typename allocator_type::template
				rebind<char>::other::reference				Charref;
			typedef typename allocator_type::template
				rebind<value_type>::other::reference		Vref;

			static Charref	Color(Nodeptr P);
			static Charref	Isnil(Nodeptr P);
			static Keyref	Key(Nodeptr P);
			static Nodepref Left(Nodeptr P);
			static Nodepref Right(Nodeptr P);
			static Nodepref Parent(Nodeptr P);
			static Vref		Value(Nodeptr P);

	public:
			/**
			=================================
			==        Class Iterator       ==
			=================================
			*/

//			class iterator_tree;
//			friend class iterator_tree;
			class iterator;
			friend class iterator;
			class iterator : public Bidit<value_type, Dift, Tptr, Reft>
			{
				public:
					typedef Bidit<value_type, Dift, Tptr, Reft> MyBase;
					typedef typename MyBase::iterator_category	iterator_category;
					typedef typename MyBase::difference_type	difference_type;
					typedef typename MyBase::pointer			pointer;
					typedef typename MyBase::reference			reference;
					iterator() : Ptr(0) {}
					iterator(Nodeptr P) : Ptr(P) {}
					reference	operator*() const { return (Value(Ptr)); }
					Tptr		operator->() const { return (&**this); }
					// TODO: check output value
					iterator	&operator++() { Inc(); return (*this); }
					iterator	&operator--() { Dec(); return (*this); }
					iterator	operator--(int) { iterator tmp = *this; --*this; return (tmp); }
					iterator	operator++(int) { iterator tmp = *this; ++*this; return (tmp); }
//					iterator	operator*(int) { iterator tmp = *this; ++*this; return (tmp); }
					bool		operator==(const iterator X) const { return (Ptr == X.Ptr); }
					bool		operator!=(const iterator X) const { return (!(*this == X)); }
					void Dec()
					{
						if (Isnil(Ptr))
							Ptr = Right(Ptr);
						else if (!Isnil(Left(Ptr)))
							Ptr = Max(Left(Ptr));
						else
						{
							Nodeptr P;
							while (!Isnil(P = Parent(Ptr)) && Ptr == Left(P))
								Ptr = P;
							if (!Isnil(P))
								Ptr = P;
						}
					}
					void Inc()
					{
						if (Isnil(Ptr))
							;
						else if (!Isnil(Right(Ptr)))
							Ptr = Min(Right(Ptr));
						else
						{
							Nodeptr P;
							while (!Isnil(P = Parent(Ptr)) && Ptr == Right(P))
								Ptr = P;
							Ptr = P;
						}
					}
					Nodeptr Mynode() const
					{
						return (Ptr);
					}
				protected:
					Nodeptr Ptr;
			};

			/**
			=================================
			==    Class Const_Iterator     ==
			=================================
			*/
//			class const_iterator_tree;
//			friend class const_iterator_tree;
			class const_iterator;
			friend class const_iterator;
			class const_iterator : public Bidit<value_type, Dift, Ctptr, const_reference>
			{
				public:
					typedef Bidit<value_type, Dift, Ctptr, const_reference> MyBase;
					typedef typename MyBase::iterator_category	iterator_category;
					typedef typename MyBase::value_type			value_type;
					typedef typename MyBase::difference_type	difference_type;
					const_iterator() : Ptr(0) {}
					const_iterator(Nodeptr P) : Ptr(P) {}
					const_iterator(const typename Tree<Tree_traits>::iterator X)
							: Ptr(X.Mynode()) {}
					const_reference operator*() const { return (Value(Ptr)); }
					Ctptr operator->() const { return (&**this); }
					const_iterator &operator++() { Inc(); return (*this); }
					const_iterator &operator--() { Dec(); return (*this); }
					const_iterator operator++(int) { const_iterator tmp = *this; ++*this; return (tmp); }
					const_iterator operator--(int) { const_iterator tmp = *this; --*this; return (tmp); }
					bool operator==(const const_iterator &X) const { return (Ptr == X.Ptr); }
					bool operator!=(const const_iterator &X) const { return (!(*this == X)); }
					void Dec()
					{
						if (Isnil(Ptr))
							Ptr = Right(Ptr);
						else if (!Isnil(Left(Ptr)))
							Ptr = Max(Left(Ptr));
						else
						{
							Nodeptr P;
							while (!Isnil(P = Parent(Ptr)) && Ptr == Left(P))
								Ptr = P;
							if (!Isnil(P))
								Ptr = P;
						}
					}
					void Inc()
					{
						if (Isnil(Ptr))
							;
						else if (!Isnil(Right(Ptr)))
							Ptr = Min(Right(Ptr));
						else
						{
							Nodeptr P;
							while (!Isnil(P = Parent(Ptr)) && Ptr == Right(P))
								Ptr = P;
							Ptr = P;
						}
					}
					Nodeptr Mynode() const
					{
						return (Ptr);
					}
				protected:
					Nodeptr Ptr;
			};

			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef pair<iterator, bool>					PairIterBool;
			typedef pair<iterator, iterator>				PairIterIter;
			typedef pair<const_iterator, const_iterator>	PairConstIter;

		/**
		=================================
		==         Constructors        ==
		=================================
		*/
		public:
			iterator		erase(iterator P);
			iterator		erase(iterator First, iterator Last);
			size_type		erase(const key_type &X);
			void			erase(const key_type *First, const key_type *Last);

			PairIterBool	insert(const value_type &value);
			iterator		insert(iterator P, const value_type &value);
			template <class It>
			void			insert(It F, It L);

//			~Tree();

			//TODO: move the implementation to a separate file
//			Myt &operator=(const Myt &X);
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			size_type size() const;
			size_type max_size() const;
			bool empty() const;
			allocator_type get_allocator() const;
//			key_compare key_comp() const;
//			value_compare value_comp() const;

			void clear();
//			iterator find(const key_type &Kv);
//			const_iterator find(const key_type &Kv) const;
//			size_type count(const key_type &Kv) const;
			iterator lower_bound(const key_type &Kv);
			const_iterator lower_bound(const key_type &Kv) const;
			iterator upper_bound(const key_type &Kv);
			const_iterator upper_bound(const key_type &Kv) const;
			PairIterIter equal_range(const key_type &Kv);
			PairConstIter equal_range(const key_type &Kv) const;
			void swap(Myt &X);

		protected:
			void Init();
			Nodeptr Buynode(Nodeptr Parg, char Carg);
			void Freenode(Nodeptr S);
			static Nodeptr Max(Nodeptr P);
			static Nodeptr Min(Nodeptr P);
			Nodeptr &Lmost();
			Nodeptr &Lmost() const;
			Nodeptr &Rmost() const;
			Nodeptr &Rmost();
			Nodeptr &Root() const;
			Nodeptr &Root();
			void Erase(Nodeptr X);
			void Destval(Tptr P);
			void Lrotate(Nodeptr X);
			void Rrotate(Nodeptr X);
			iterator Insert(bool Addleft, Nodeptr Y, const value_type &V);
			void Consval(Tptr P, const value_type &V);

			void Copy(const Myt &X);
			Nodeptr Copy(Nodeptr X, Nodeptr P);
			Nodeptr Lbound(const key_type &Kv) const;
			Nodeptr Ubound(const key_type &Kv) const;

			Nodeptr		Head;
			size_type	Size;
	};

	template <class Tree_traits> inline
	void swap(Tree<Tree_traits> &X, Tree<Tree_traits> &Y)
	{
		X.swap(Y);
	}

	template <class Tr> inline
	bool operator==(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (X.size() == Y.size() && equal(X.begin(), X.end(), Y.begin()));
	}

//	template <class It1, class It2>
//	bool operator==(const It1 &X, const It2 &Y)
//	{
//		return (X.Ptr == Y.Ptr);
//	}

	template <class Tr> inline
	bool operator!=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(X == Y));
	}

//	template <class It1, class It2>
//	bool operator!=(const It1& X, const It2& Y)
//	{
//		return (!(X == Y));
//	}

	template <class Tr> inline
	bool operator<(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end(), X.value_comp()));
	}

	template <class Tr> inline
	bool operator>(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (Y < X);
	}

	template <class Tr> inline
	bool operator<=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(Y < X));
	}

	template <class Tr> inline
	bool operator>=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(X < Y));
	}
}

//#include "iterator_pointers.hpp"
//#include "iterator_tree.hpp"
//#include "const_iterator_tree.hpp"

#include "xtree_constructors.hpp"
#include "protected_funcitons.hpp"
#include "public_functions.hpp"
#include "xtree_element_access.hpp"

//#include "xtree_constructors.hpp"

#endif
