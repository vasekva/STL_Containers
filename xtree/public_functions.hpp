#ifndef COLLECTIONS_PUBLIC_FUNCTIONS_HPP
#define COLLECTIONS_PUBLIC_FUNCTIONS_HPP

#include "xtree_prototypes.hpp"
#include "../algorithm/swap.hpp"

namespace ft
{

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::erase(iterator P)
	{
		if (Isnil(P.GetNode()))
			throw std::out_of_range("map/set<T> iterator");
		Nodeptr X, XPar;
		Nodeptr Y = (P++).GetNode();
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
			//Tree<Tr> &X
			ft::swap(Color(Y), Color(Z));
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
		Destval(&Value(Z));
		Freenode(Z);
		if (0 < Size)
			--Size;
		return (P);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::erase(iterator First, iterator Last)
	{
		std::cout << "ERASE FUUUUUCK" << std::endl;
		if (size() == 0 || First != begin() || Last != end())
		{
			while (First != Last)
			{
//			        	First.Inc();
				erase(First++);
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

	template <class Tree_traits>
	typename Tree<Tree_traits>::size_type Tree<Tree_traits>::erase(const key_type &X)
	{
		PairIterIter P = equal_range(X);
		size_type N = 0;
		Distance(P.first, P.second, N);
		erase(P.first, P.second);
		return (N);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::erase(const key_type *First, const key_type *Last)
	{
		while (First != Last)
			erase(*First++);
	}

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

#endif
