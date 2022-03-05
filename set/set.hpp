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

			key_type GetKey(const value_type &V) const
			{
				return (V);
			}

			key_compare	comp;
	};

	template <class K,
		class Pr = std::less<K>,
		class A = std::allocator<K> >
	class set : Tree<Tset_traits<K, Pr, A, false> >
	{
		private:
			typedef Tree<Tset_traits<K, Pr, A, false> >	_base;
			typedef set<K, Pr, A>						container_type;
		public:
			typedef K	key_type;
			typedef Pr	key_compare;
			typedef typename _base::value_compare	value_compare;
			typedef typename _base::allocator_type	allocator_type;
			typedef typename _base::size_type		size_type;
			typedef typename _base::value_type		value_type;
			typedef typename _base::difference_type	difference_type;
			typedef typename _base::pointer			pointer;
			typedef typename _base::const_pointer	const_pointer;
			typedef typename _base::reference		reference;
			typedef typename _base::const_reference	const_reference;
//
//			typedef typename _base::iterator		iterator;
//			typedef typename _base::const_iterator	const_iterator;
//
//			typedef typename _base::const_reverse_iterator	reverse_iterator;
//			typedef typename _base::const_reverse_iterator	const_reverse_iterator;

			set() : _base(key_compare(), allocator_type()) {}

	};
}

#endif
