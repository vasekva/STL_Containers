#ifndef FT_ITERATOR_PTR_TREE
#define FT_ITERATOR_PTR_TREE

#include "./xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	class iterator_pointers
	{
		public:
			typedef typename Tree<Tree_traits>::Nodeptr Nodeptr;
			typedef typename Tree<Tree_traits>::NodeptrConst NodeptrConst;
			typedef typename Tree<Tree_traits>::value_type value_type;

			iterator_pointers()
				:Ptr(0), End(0), Begin(0), Last(0){}
			iterator_pointers(Nodeptr P)
				:Ptr(P), End(0), Begin(0), Last(0){}
			iterator_pointers(NodeptrConst P)
				:Ptr((Nodeptr)P), End((Nodeptr)P), Begin(0), Last(0){}
			iterator_pointers(const iterator_pointers &N)
				:Ptr(N.Ptr), End(N.End), Begin(N.Begin), Last(N.Last){}
			// ~iterator_pointers(){}
		protected:
			Nodeptr End;
			Nodeptr Begin;
			Nodeptr Last;
			Nodeptr Ptr;

	};
}

#endif