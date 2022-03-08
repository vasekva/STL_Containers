#ifndef COLLECTIONS_PROTECTED_FUNCITONS_HPP
#define COLLECTIONS_PROTECTED_FUNCITONS_HPP

#include "xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	void Tree<Tree_traits>::Copy(const Myt &X)
	{
		Root() = Copy(X.Root(), Head);
		Size = X.size();
		if (!Isnil(Root()))
		{
			Lmost() = Min(Root());
			Rmost() = Max(Root());
		}
		else
			Lmost() = Head, Rmost() = Head;
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Copy(Nodeptr X, Nodeptr P)
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
				Freenode(Y);
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

	template <class Tree_traits>
	void Tree<Tree_traits>::Init()
	{
		Head = Buynode(0, Black);
		Isnil(Head) = true;
		Root() = Head;
		Lmost() = Head, Rmost() = Head;
		Size = 0;
	}

	//TODO: there might have an error because
	// the book doesn't have brackets under 'for' cycle
	template <class Tree_traits>
	typename Tree<Tree_traits>::iterator Tree<Tree_traits>::Insert(bool Addleft, Nodeptr Y, const value_type &V)
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
			Freenode(Z);
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
		}
		Color(Root()) = Black;
		return (iterator(Z));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Buynode(Nodeptr Parg, char Carg)
	{
		Nodeptr S = this->Alnod.allocate(1, (void *)0);
		// TODO: second construct parameters were equal 0
		this->Alptr.construct(&Left(S), nullptr);
		this->Alptr.construct(&Right(S), nullptr);
		this->Alptr.construct(&Parent(S), Parg);
		Color(S) = Carg;
		Isnil(S) = false;
		return (S);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Freenode(Nodeptr S)
	{
		this->Alptr.destroy(&Parent(S));
		this->Alptr.destroy(&Right(S));
		this->Alptr.destroy(&Left(S));
		this->Alnod.deallocate(S, 1);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Charref Tree<Tree_traits>::Isnil(Nodeptr P)
	{
		// returns Genptr Node.Left
		return ((Charref)(*P).Isnil);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Keyref Tree<Tree_traits>::Key(Nodeptr P)
	{
		return (Tree_traits::GetKey(Value(P)));
	}


	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Left(Nodeptr P)
	{
		// returns Genptr Node.Left
		return ((Nodepref)(*P).Left);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Right(Nodeptr P)
	{
		// returns Genptr Node.Left
		return ((Nodepref)(*P).Right);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Parent(Nodeptr P)
	{
		// returns Genptr Node.Left
		return ((Nodepref)(*P).Parent);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Vref Tree<Tree_traits>::Value(Nodeptr P)
	{
		return ((Vref)(*P).Value);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Charref	Tree<Tree_traits>::Color(Nodeptr P)
	{
		return ((Charref)(*P).Color);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Consval(Tptr P, const value_type &V)
	{
		this->Alval.construct(P, V);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Max(Nodeptr P)
	{
		while (!Isnil(Right(P)))
			P = Right(P);
		return (P);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Min(Nodeptr P)
	{
		while (!Isnil(Left(P)))
			P = Left(P);
		return (P);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Lbound(const key_type &Kv) const
	{
		Nodeptr X = Root();
		Nodeptr Y = Head;
		while (!(Isnil(X)))
		{
			if (Tree_traits::comp(Key(X), Kv))
				X = Right(X);
			else
				Y = X, X = Left(X);
		}
		return (Y);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Lmost()
	{
		return (Left(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Lmost() const
	{
		return (Left(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Rmost() const
	{
		return (Right(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Rmost()
	{
		return (Right(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Root() const
	{
		return (Parent(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Root()
	{
		return (Parent(Head));
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Erase(Nodeptr X)
	{
		for (Nodeptr Y = X; !Isnil(Y); X = Y)
		{
			Erase(Right(Y));
			Y = Left(Y);
			Destval(&Value(X));
			Freenode(X);
		}
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Destval(Tptr P)
	{
		this->Alval.destroy(P);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Lrotate(Nodeptr X)
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

	template <class Tree_traits>
	void Tree<Tree_traits>::Rrotate(Nodeptr X)
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
	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Ubound(const key_type &Kv) const
	{
		Nodeptr X = Root();
		Nodeptr Y = Head;
		while (!Isnil(X))
		{
			if (Tree_traits::comp(Kv, Key(X)))
				Y = X, X = Left(X);
			else
				X = Right(X);
		}
		return (Y);
	}
}

#endif
