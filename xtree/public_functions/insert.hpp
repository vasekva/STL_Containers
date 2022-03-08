#ifndef FT_INSERT
#define FT_INSERT

#include "../xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	typename Tree<Tree_traits>::PairIterBool Tree<Tree_traits>::insert(const value_type &V)
	{
		Nodeptr X = Root();
		Nodeptr Y = Head;
		bool AddLeft = true;
		while (!Isnil(X))
		{
			Y = X;
			AddLeft = Tree_traits::comp(Tree_traits::GetKey(V), Key(X));
			X = AddLeft ? Left(X) : Right(X);
		}
		if (Tree_traits::Multi)
			return (PairIterBool(Insert(AddLeft, Y, V), true));
		else
		{
			iterator P = iterator(Y); //  TODO: <-- there's an error!!!!
			if (!AddLeft)
				;
			else if (P == begin())
			{
				return (PairIterBool(Insert(true, Y, V), true));
			}
			else
				--P;
			if (Tree_traits::comp(Key(P.Mynode()), Tree_traits::GetKey(V)))
				return (PairIterBool(Insert(AddLeft, Y, V), true));
			else
				return (PairIterBool(P, false));
		}
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::insert(iterator P, const value_type &V)
	{
		if (size() == 0)
			return (Insert(true, Head, V));
		else if (P == begin())
		{
			if (Tree_traits::comp(Tree_traits::GetKey(V), Key(P.Mynode())))
				return (Insert(true, P.Mynode(), V));
		}
		else if (P == end())
		{
			if (Tree_traits::comp(Key(Rmost()), Tree_traits::GetKey(V)))
				return (Insert(false, Rmost(), V));
		}
		else
		{
			iterator Pb = P;
			//TODO: might be error! comp(Key((--Pb) - Mynode()
			if (Tree_traits::comp(Key((--Pb).Mynode()),
					 Tree_traits::GetKey(V)) && Tree_traits::comp(Tree_traits::GetKey(V), Key(P.Mynode())))
			{
				if (Isnil(Right(Pb.Mynode())))
					return (Insert(false, Pb.Mynode(), V));
				else
					return (Insert(true, P.Mynode(), V));
			}
		}
		return (insert(V).first);
	}

	template <class Tree_traits>
	template <class It>
	void Tree<Tree_traits>::insert(It F, It L)
	{
		for (; F != L; ++F)
			insert(*F);
	}
}

#endif