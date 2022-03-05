#ifndef COLLECTIONS_PROTECTED_FUNCITONS_HPP
#define COLLECTIONS_PROTECTED_FUNCITONS_HPP

#include "xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	void Tree<Tree_traits>::Init()
	{
		std::cout << "ok" << std::endl;
		// TODO: need to finish this function
		Head = Buynode(0, Black);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr Tree<Tree_traits>::Buynode(Nodeptr Parg, char Carg)
	{
		std::cout << "ok" << std::endl;
		Nodeptr S = this->Alnod.allocate(1, (void *)0);
		Left(S);
		// TODO: need to finish this line
//		this->Alptr.construct(&Left(S), 0);
	}

	template <class Tree_traits>
	void Tree<Tree_traits>::Freenode(Nodeptr S)
	{
		this->Alptr.destroy(&Parent(S));
		this->Alptr.destroy(&Right(S));
		this->Alptr.destroy(&Left(S));
		this->Alnod.deallocate(S, 1);
		std::cout << "Freenode ok" << std::endl;
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Charref Tree<Tree_traits>::Isnil(Nodeptr P)
	{
		std::cout << "Isnil ok" << std::endl;
		// returns Genptr Node.Left
		return ((Charref)(*P).Isnil);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Left(Nodeptr P)
	{
		std::cout << "Left ok" << std::endl;
		// returns Genptr Node.Left
		return ((Nodepref)(*P).Left);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Right(Nodeptr P)
	{
		std::cout << "Right ok" << std::endl;
		// returns Genptr Node.Left
		return ((Nodepref)(*P).Right);
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodepref Tree<Tree_traits>::Parent(Nodeptr P)
	{
		std::cout << "Parent ok" << std::endl;
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
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Lmost()
	{
		return (Left(Head));
	}

	template <class Tree_traits>
	typename Tree<Tree_traits>::Nodeptr &Tree<Tree_traits>::Rmost()
	{
		return (Right(Head));
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
}

#endif
