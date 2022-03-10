#ifndef COLLECTIONS_SET_HPP
#define COLLECTIONS_SET_HPP

#include <memory>
#include "../xtree/xtree_prototypes.hpp"

namespace ft
{
	template <class K, class Pr, class Ax, bool Mfl>
	class Tset_traits
	{
		public:
			typedef K	key_type;
			typedef K	value_type;
			typedef Pr	key_compare;

			typedef typename Ax::template rebind<value_type>::other
				allocator_type;

			enum { Multi = Mfl };

			// default constructor with a call to key_compare constructor(Pr = less<K>)
			Tset_traits() : comp() {}
			// constructor with an instance of a class std::less<K>
			Tset_traits(Pr Parg) : comp(Parg) {}

			typedef key_compare	value_compare;

			const static K &GetKey(const value_type &V)
			{
				return (V);
			}

			key_compare	comp;
	};

	template <class K,
		class Pr = std::less<K>,
		class A = std::allocator<K> >
	class set : public Tree<Tset_traits<K, Pr, A, false> >
	{
		private:
			typedef Tree<Tset_traits<K, Pr, A, false> >	Mybase;
			typedef set<K, Pr, A>						container_type;
		public:
			typedef K	key_type;
			typedef Pr	key_compare;
			typedef typename Mybase::value_compare		value_compare;
			typedef typename Mybase::allocator_type		allocator_type;
			typedef typename Mybase::size_type			size_type;
			typedef typename Mybase::value_type			value_type;
			typedef typename Mybase::difference_type	difference_type;
			typedef typename Mybase::pointer			pointer;
			typedef typename Mybase::const_pointer		const_pointer;
			typedef typename Mybase::reference			reference;
			typedef typename Mybase::const_reference	const_reference;
//
			typedef typename Mybase::iterator		iterator;
			typedef typename Mybase::const_iterator	const_iterator;

			typedef typename Mybase::const_reverse_iterator	reverse_iterator;
			typedef typename Mybase::const_reverse_iterator	const_reverse_iterator;

			set();
			explicit set(const key_compare &Pred);
			set(const key_compare &Pred, const allocator_type &Al);
			template <class It>
			set(It F, It L);
			template <class It>
			set(It F, It L, const key_compare &Pred);
			template <class It>
			set(It F, It L, const key_compare &Pred, const allocator_type &Al);
	};
}

#include "set_constructors.hpp"

#endif
