#ifndef COLLECTIONS_XTREE_HPP
#define COLLECTIONS_XTREE_HPP

#include <functional>
#include <memory>
#include <stdexcept>

#include "../iterators/iterator.hpp"
#include "../utility/pair.hpp"
#include "../algorithm/lexicographical_compare.hpp"

//TODO: implement Biderectional iterator

namespace ft
{

/**
=================================
==   TEMPLATE CLASS Tree_nod   ==
=================================
*/

	template <class Tr>
	class Tree_nod : public Tr
	{
		protected:
			typedef typename Tr::allocator_type	allocator_type;
			typedef typename Tr::key_compare	key_compare;
			typedef typename Tr::value_type		value_type;

			typedef typename allocator_type
				::template rebind<void>::other::pointer Genptr;

			struct			Node;
			friend struct	Node;

			struct Node
			{
				Genptr Left, Parent, Right;
				value_type Value;
				char Color, Isnil;
			};

			Tree_nod(const key_compare &Parg, allocator_type Al)
				: Tr(Parg), Alnod(Al) {}
			typename allocator_type
				::template rebind<Node>::other Alnod;
	};

/**
=================================
==   TEMPLATE CLASS Tree_ptr   ==
=================================
*/
	template <class Tr>
	class Tree_ptr : public Tree_nod<Tr>
	{
		protected:
			typedef typename Tree_nod<Tr>::Node 		Node;
			typedef typename Tr::allocator_type 		allocator_type;
			typedef typename Tr::key_compare			key_compare;

			typedef typename allocator_type
				::template rebind<Node>::other::pointer	Nodeptr;

			Tree_ptr(const key_compare &Parg, allocator_type Al)
				: Tree_nod<Tr>(Parg, Al), Alptr(Al) {}

			typename allocator_type
				::template rebind<Nodeptr>::other Alptr;
	};

/**
=================================
==   TEMPLATE CLASS Tree_val   ==
=================================
*/
	template <class Tr>
	class Tree_val : public Tree_ptr<Tr>
	{
		protected:
			typedef typename Tr::allocator_type	allocator_type;
			typedef typename Tr::key_compare	key_compare;

			Tree_val(const key_compare Parg, allocator_type Al)
				: Tree_ptr<Tr>(Parg, Al), Alval(Al) {}

			allocator_type Alval;
	};
/**
=================================
==     TEMPLATE CLASS Tree     ==
=================================
*/
	template <class Tr>
	class Tree : public Tree_val<Tr>
	{
		public:
			typedef Tree<Tr> Myt;
			typedef Tree_val<Tr> MyBase;
			typedef typename Tr::key_type		key_type;
			typedef typename Tr::key_compare	key_compare;
			typedef typename Tr::value_compare	value_compare;
			typedef typename Tr::value_type		value_type;
			typedef typename Tr::allocator_type	allocator_type;
		protected:
			typedef typename Tree_nod<Tr>::Genptr	Genptr;
			typedef typename Tree_nod<Tr>::Node		Node;
			enum Redbl {Red, Black};
			typedef typename allocator_type::template
					rebind<Node>::other::pointer				Nodeptr;
			typedef typename allocator_type::template
					rebind<Nodeptr>::other::reference			Nodepref;
			typedef typename allocator_type::template
					rebind<key_type>::other::const_reference	Keyref;
			typedef typename allocator_type::template
					rebind<char>::other::reference				Charref;
			typedef typename allocator_type::template
					rebind<value_type>::other::reference		Vref;

			static Charref	Color(Nodeptr P)	{ return ((Charref)(*P).Color); }
			static Charref	Isnil(Nodeptr P) 	{ return ((Charref)(*P).Isnil); }
			static Keyref	Key(Nodeptr P)		{ return (Tr::Kfn()(Value(P))); }
//			static Keyref	Key(Nodeptr P)		{ return (Tr::GetKey(Value(P))); }
			static Nodepref Left(Nodeptr P)		{ return ((Nodepref)(*P).Left); }
			static Nodepref Parent(Nodeptr P)	{ return ((Nodepref)(*P).Parent); }
			static Nodepref Right(Nodeptr P)	{ return ((Nodepref)(*P).Right); }
			static Vref		Value(Nodeptr P)	{ return ((Vref)(*P).Value); }
		public:
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	Dift;
			typedef Dift										difference_type;
			typedef typename allocator_type::template
				rebind<value_type>::other::pointer			    Tptr;
			typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer		Ctptr;
			typedef typename allocator_type::template
				rebind<value_type>::other::reference			Reft;
			typedef Tptr										pointer;
			typedef Ctptr										const_pointer;
			typedef Reft										reference;
			typedef typename allocator_type::template
				rebind<value_type>::other::const_reference		const_reference;

			/**
			=================================
			==        Class Iterator       ==
			=================================
			*/
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
					iterator	operator++() { Inc(); return (*this); }
					iterator	operator-() { Dec(); return (*this); }
					iterator	operator--(int) { iterator tmp = *this; --*this; return (tmp); }
					iterator	operator*(int) { iterator tmp = *this; ++*this; return (tmp); }
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
					const_iterator(const typename Tree<Tr>::iterator X)
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
					Nodeptr MyNode() const
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

			explicit Tree(const key_compare &Parg, const allocator_type &Al)
				: MyBase(Parg, Al)
			{
				Init();
			}

			Tree(const value_type *First, const value_type *Last,
				 const key_compare &Parg, const allocator_type &Al)
				 : MyBase(Parg, Al)
			{
				Init();
				insert(First, Last);
			}

			Tree(const Myt &X)
				: MyBase(X.key_camp(), X.get_allocator())
			{
				Init();
				Copy(X);
			}

			~Tree()
			{
				erase(begin(), end());
				FreeNode(Head);
				Head = 0, Size = 0;
			}

			Myt &operator=(const Myt &X)
			{
				if (this != &X)
				{
					erase(begin(), end());
					Tr::comp = X.comp();
					Copy(X);
				}
				return (*this);
			}

			iterator begin()
			{
				return (iterator(Lmost()));
			}

			const_iterator begin() const
			{
				return (const_iterator(Lmost()));
			}

			iterator end()
			{
				return (iterator(Head));
			}

			const_iterator end() const
			{
				return (const_iterator(Head));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const
			{
				return  (const_reverse_iterator(end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			size_type size() const
			{
				return (Size);
			}

			size_type max_size() const
			{
				return (Tree::Alval.max_size());
			}

			bool empty() const
			{
				return (size() == 0);
			}

			allocator_type get_allocator() const
			{
				return (Tree::Alval);
			}

			key_compare key_comp() const
			{
				return (Tr::comp);
			}

			value_compare value_comp() const
			{
				return (value_compare(key_comp()));
			}

			PairIterBool insert(const value_type &value)
			{
				Nodeptr X = Root();
				Nodeptr Y = Head;
				bool AddLeft = true;
				while (!Isnil(X))
				{
					Y = X;
					AddLeft = Tr::comp(Tr::Kfn()(value), Key(X));
					X = AddLeft ? Left(X) : Right(X);
				}
				if (Tr::Multi)
					return (PairIterBool(Insert(AddLeft, Y, value), true));
				else
				{
					iterator P = iterator(Y);
					if (!AddLeft)
						;
					else if (P == begin())
						return (PairIterBool(Insert(true, Y, value), true));
					else
						P.Dec();
//						--P; TODO: --P iterator
					if (Tr::comp(Key(P.Mynode()), Tr::Kfn()(value)))
						return (PairIterBool(Insert(AddLeft, Y, value), true));
					else
						return (PairIterBool(P, false));
				}
			}

			iterator insert(iterator P, const value_type &value)
			{
				if (size() == 0)
					return (Insert(true, Head, value));
				else if (P == begin())
				{
					if (comp(Tr::Kfn()(value), Key(P.Mynode())))
						return (Insert(true, P.Mynode(), value));
				}
				else if (P == end())
				{
					if (comp(Key(Rmost()), Tr::Kfn()(value)))
						return (Insert(false, Rmost(), value));
				}
				else
				{
					iterator Pb = P;
					if (comp(Key((--Pb) - Tr::Mynode()),
						Tr::Kfn()(value)) && comp(Tr::Kfn()(value), Key(P.Mynode())))
					{
						if (Isnil(Right(Pb.Mynode())))
							return (Insert(false, Pb.Mynode(), value));
						else
							return (Insert(true, P.Mynode(), value));
					}
					return (insert(value).first);
				}
			}

			template <class It>
			void insert(It F, It L)
			{
				for (; F != L; ++F)
					insert(*F);
			}

			iterator erase(iterator P)
			{
				if (Isnil(P.Mynode()))
					throw std::out_of_range("map/set<T> iterator");
				Nodeptr X, XPar;
				Nodeptr Y = (P++).Mynode();
				Nodeptr Z = Y;
				if (Isnil(Left(Y)))
					X = Right(Y);
				else if (Isnil(Right(Y)))
					X = Left(Y);
				else
					Y = Min(Right(Y)), X = Right(Y);
				if (Y == Z)
				{
					XPar = Parent(Z);
					if (!Isnil(X))
						Parent(X) = XPar;

					if (Root() == Z)
						Root() = X;
					else if (Left(XPar) == Z)
						Left(XPar) = X;
					else
						Right(XPar) = X;

					if (Lmost() != Z)
						;
					else if (Isnil(Right(Z)))
						Lmost() = XPar;
					else
						Lmost() = Min(X);

					if (Rmost() != Z)
						;
					else if (Isnil(Left(Z)))
						Rmost() = XPar;
					else
						Rmost() = Max(X);
				}
				else
				{
					Parent(Left(Z)) = Y;
					Left(Y) = Left(Z);
					if (Y == Right(Z))
						XPar = Y;
					else
					{
						XPar = Parent(Y);
						if (!Isnil(X))
							Parent(X) = XPar;
						Left(XPar) = X;
						Right(Y) = Right(Z);
						Parent(Right(Z)) = Y;
					}
					if (Root() == Z)
						Root() = Y;
					else if (Left(Parent(Z)) == Z)
						Left(Parent(Z)) = Y;
					else
						Right(Parent(Z)) = Y;
					Parent(Y) = Parent(Z);
					swap(Color(Y), Color(Z));
				}
				if (Color(Z) == Black)
				{
					for (; X != Root() && Color(X) == Black; XPar = Parent(X))
						if (X == Left(XPar))
						{
							Nodeptr W = Right(XPar);
							if (Color(W) == Red)
							{
								Color(W) = Black;
								Color(XPar) = Red;
								Lrotate(XPar);
								W = Right(XPar);
							}
							if (Isnil(W))
								X = XPar;
							// shouldn't happen
							else if (Color(Left(W)) == Black && Color(Right(W)) == Black)
							{
								Color(W) = Red;
								X = XPar;
							}
							else
							{
								if (Color(Right(W)) == Black)
								{
									Color(Left(W)) = Black;
									Color(W) = Red;
									Rrotate(W);
									W = Right(XPar);
								}
								Color(W) = Color(XPar);
								Color(XPar) = Black;
								Color(Right(W)) = Black;
								Lrotate(XPar);
								break;
								}
							}
						else
						{
							Nodeptr W = Left(XPar);
							if (Color(W) == Red)
							{
								Color(W) = Black;
								Color(XPar) = Red;
								Rrotate(XPar);
								W = Left(XPar);
							}
							if (Isnil(W))
								X = XPar;
							// shouldn't happen
							else if (Color(Right(W)) == Black && Color(Left(W)) == Black)
							{
								Color(W) = Red;
								X = XPar;
							}
							else
							{
								if (Color(Left(W)) == Black)
								{
									Color(Right(W)) = Black;
									Color(W) = Red;
									Lrotate(W);
									W = Left(XPar);
								}
								Color(W) = Color(XPar);
								Color(XPar) = Black;
								Color(Left(W)) = Black;
								Rrotate(XPar);
								break;
							}
						}
						Color(X) = Black;
				}
				Destval(&value(Z));
				FreeNode(Z);
				if (0 < Size)
					--Size;
				return (P);
			}

			//TODO: check line 600
			iterator erase(iterator First, iterator Last)
			{
			    if (size() == 0 || First != begin() || Last != end())
				{
			        while (First != Last)
			        {
			        	First.Inc();
//			        	erase(First++);
			        }
			        return (First);
				}
				else
				{
					Erase(Root());
					Root() = Head, Size = 0;
					Lmost() = Head, Rmost() = Head;
					return (begin());
				}
			}

			// TODO:: function always return 0
			size_type erase(const key_type &X)
			{
				PairIterIter P = equal_range(X);
				size_type N = 0;
				Distance(P.first, P.second, N);
				erase(P.first, P.second);
				return (N);
			}

			void erase(const key_type *First, const key_type *Last)
			{
			    while (First != Last)
			        erase(*First++);
			}

			void clear()
			{
				erase(begin(), end());
			}

			iterator find(const key_type &Kv)
			{
				iterator P = lower_bound(Kv);
				return (P == end() || comp(Kv, Key(P.Mynode())) ? end() : P);
			}

			const_iterator find(const key_type &Kv) const
			{
				const_iterator P = lower_bound(Kv);
				return (P == end() || comp(Kv, Key(P.MyNode())) ? end() : P);
			}

			//TODO: count always return 0
			size_type count(const key_type &Kv) const
			{
				PairConstIter Ans = equal_range(Kv);
				size_type N = 0;
				Distance(Ans.first, Ans.second, N);
				return (N);
			}

			iterator lower_bound(const key_type &Kv)
			{
				return (iterator(Lbound(Kv)));
			}

			const_iterator lower_bound(const key_type &Kv) const
			{
				return (const_iterator(Lbound(Kv)));
			}

			iterator upper_bound(const key_type &Kv)
			{
				return (iterator(Ubound(Kv)));
			}

			const_iterator upper_bound(const key_type &Kv) const
			{
				return (iterator(Ubound(Kv)));
			}

			PairIterIter equal_range(const key_type &Kv)
			{
				return (PairIterIter(lower_bound(Kv), upper_bound(Kv)));
			}

			PairConstIter equal_range(const key_type &Kv) const
			{
				return (PairConstIter(lower_bound(Kv), upper_bound(Kv)));
			}

			void swap(Myt &X)
			{
				if (get_allocator() == X.get_allocator())
				{
					swap(Tr::comp, X.comp);
					swap(Head, X.Head);
					swap(Size, X.Size);
				}
				else
				{
					Myt tmp = *this; *this = X, X = tmp;
				}
			}

		protected:
			void Copy(const Myt &X)
			{
				Root() = Copy(X.Root(), Head);
				Size = X.size();
				if (!Isnil(Tr::Root))
				{
					Lmost() = Min(Root());
					Rmost() = Max(Root());
				}
				else
					Lmost() = Head, Rmost() = Head;
			}

			Nodeptr Copy(Nodeptr X, Nodeptr P)
			{
				Nodeptr R = Head;
				if (!Isnil(X))
				{
					Nodeptr Y = Buynode(P, Color(X));
					try
					{
						Consval(&Value(Y), Value(X));
					}
					catch (...)
					{
						FreeNode(Y);
						Erase(R);
						throw;
					}
					Left(Y) = Head, Right(Y) = Head;
					if (Isnil(R))
						R = Y;
					try
					{
						Left(Y) = Copy(Left(X), Y);
						Right(Y) = Copy(Right(X), Y);
					}
					catch (...)
					{
						Erase(R);
						throw;
					}
				}
				return (R);
			}

			void Erase(Nodeptr X)
			{
				for (Nodeptr Y = X; !Isnil(Y); X = Y)
				{
					Erase(Right(Y));
					Y = Left(Y);
					Destval(&Value(X));
					FreeNode(X);
				}
			}

			void Init()
			{
				Head = Buynode(0, Black);
				Isnil(Head) = true;
				Root() = Head;
				Lmost() = Head, Rmost() = Head;
				Size = 0;
			}

			iterator Insert(bool Addleft, Nodeptr Y, const value_type &V)
			{
				if (max_size() - 1 <= Size)
					throw std::length_error("map/set<T> too long");
				Nodeptr Z = Buynode(Y, Red);
				Left(Z) = Head, Right(Z) = Head;
				try
				{
					Consval(&Value(Z), V);
				}
				catch (...)
				{
					FreeNode(Z);
					throw;
				}
				++Size;
				if (Y == Head)
				{
					Root() = Z;
					Lmost() = Z, Rmost() = Z;
				}
				else if (Addleft)
				{
					Left(Y) = Z;
					if (Y == Lmost())
						Lmost() = Z;
				}
				else
				{
					Right(Y) = Z;
					if (Y == Rmost())
						Rmost() = Z;
				}
				for (Nodeptr X = Z; Color(Parent(X)) == Red; )
				{
					if (Parent(X) == Left(Parent(Parent(X))))
					{
						Y = Right(Parent(Parent(X)));
						if (Color(Y) == Red)
						{
							Color(Parent(X)) = Black;
							Color(Y) = Black;
							Color(Parent(Parent(X))) = Red;
							X = Parent(Parent(X));
						}
						else
						{
							if (X == Right(Parent(X)))
							{
								X = Parent(X);
								Lrotate(X);
							}
							Color(Parent(X)) = Black;
							Color(Parent(Parent(X))) = Red;
							Rrotate(Parent(Parent(X)));
						}
					}
					else
					{
						Y = Left(Parent(Parent(X)));
						if (Color(Y) == Red)
						{
							Color(Parent(X)) = Black;
							Color(Y) = Black;
							Color(Parent(Parent(X))) = Red;
							X = Parent(Parent(X));
						}
						else
						{
							if (X == Left(Parent(X)))
							{
								X = Parent(X);
								Rrotate(X);
							}
							Color(Parent(X)) = Black;
							Color(Parent(Parent(X))) = Red;
							Lrotate(Parent(Parent(X)));
						}
					}
					Color(Root()) = Black;
					return (iterator(Z));
				}
			}

			Nodeptr Lbound(const key_type &Kv) const
			{
				Nodeptr X = Root();
				Nodeptr Y = Head;
				while (!(Isnil(X)))
				{
					if (comp(Key(X), Kv))
						X = Right();
					else
						Y = X, X = Left(X);
				}
				return (Y);
			}

			Nodeptr &Lmost()
			{
				return (Left(Head));
			}

			//TODO: maybe Nodeptr *???
//			Nodeptr &Lmost() const
//			{
//				return (Left(Head));
//			}

			void Lrotate(Nodeptr X)
			{
				Nodeptr Y = Right(X);
				Right(X) = Left(Y);
				if (!Isnil(Left(Y)))
					Parent(Left(Y)) = X;
				Parent(Y) = Parent(X);
				if (X == Root())
					Root() = Y;
				else if (X == Left(Parent(X)))
					Left(Parent(X)) = Y;
				else
					Right(Parent(X)) = Y;
				Left(Y) = X;
				Parent(X) = Y;
			}

			static Nodeptr Max(Nodeptr P)
			{
				while (!Isnil(Right(P)))
					P = Right(P);
				return (P);
			}

			static Nodeptr Min(Nodeptr P)
			{
				while (!Isnil(Left(P)))
					P = Left(P);
				return (P);
			}

			Nodeptr &Rmost()
			{
				return (Right(Head));
			}

			//TODO: maybe Nodeptr *???
//			Nodeptr &Rmost() const
//			{
//				return (Right(Head));
//			}

			Nodeptr &Root() const
			{
				return (Parent(Head));
			}

			//TODO: maybe Nodeptr *???
//			Nodeptr &Root() const
//			{
//				return (Parent(Head));
//			}

			void Rrotate(Nodeptr X)
			{
				Nodeptr Y = Left(X);
				Left(X) = Right(Y);
				if (!Isnil(Right(Y)))
					Parent(Right(Y)) = X;
				Parent(Y) = Parent(X);
				if (X == Root())
					Root() = Y;
				else if (X == Right(Parent(X)))
					Right(Parent(X)) = Y;
				else
					Left(Parent(X)) = Y;
				Right(Y) = X;
				Parent(X) = Y;
			}

			Nodeptr Ubound(const key_type &Kv) const
			{
				Nodeptr X = Root();
				Nodeptr Y = Head;
				while (!Isnil(X))
				{
					if (comp(Kv, Key(X)))
						Y = X, X = Left(X);
					else
						X = Right(X);
				}
				return (Y);
			}

			Nodeptr Buynode(Nodeptr Parg, char Carg)
			{
			    //TODO: which size_t value do i need to put with first parm in allocate??
			    Nodeptr S = Tree::Alnod.allocate(1, (void *)0);
			    //TODO: construct had zero as second parameter
				Tree::Alptr.construct(&Left(S), nullptr);
				Tree::Alptr.construct(&Right(S), nullptr);
				Tree::Alptr.construct(&Parent(S), Parg);
				Color(S) = Carg;
				Isnil(S) = false;
				return (S);
			}

			void Consval(Tptr P, const value_type &V)
			{
			    Tree::Alval.construct(P, V);
			}

			void Destval(Tptr P)
			{
			    Tree::Alval.destroy(P);
			}

			void FreeNode(Nodeptr S)
			{
				Tree::Alptr.destroy(&Parent(S));
				Tree::Alptr.destroy(&Right(S));
				Tree::Alptr.destroy(&Left(S));
				Tree::Alnod.deallocate(S, 1);
			}

			Nodeptr Head;
			size_type Size;
	};

	template <class Tr> inline
	void swap(Tree<Tr> &X, Tree<Tr> &Y)
	{
		X.swap(Y);
	}

	template <class Tr> inline
	bool operator==(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (X.size() == Y.size() && equal(X.begin(), X.end(), Y.begin()));
	}

	template <class Tr> inline
	bool operator!=(const Tree<Tr> &X, const Tree<Tr> &Y)
	{
		return (!(X == Y));
	}

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

#endif
