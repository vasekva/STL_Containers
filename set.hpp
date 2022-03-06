#ifndef COLLECTIONS_SET_HPP
#define COLLECTIONS_SET_HPP

#include "xtree/xtree_old.hpp"
#include <memory>

namespace ft
{
	template <class K, class Pr, class Ax, bool Mfl>
	class Tset_traits
	{
		public:
			typedef K   key_type;
			typedef K   value_type;
			typedef Pr  key_compare;
			typedef typename Ax::template rebind<value_type>::other
					allocator_type;
			enum { Multi = Mfl };
			Tset_traits() : comp() {}
			Tset_traits(Pr Parg) : comp(Parg) {}
			typedef key_compare value_compare;

//			const key_type GetKey(const value_type &value) const
//			{
//				return (value);
//			}
			struct Kfn
			{
				const K &operator()(const value_type &X) const
				{
					return (X);
				}
			};

			Pr comp;
	};

	//TODO: maybe ft:less??
	//TODO: rename 'Set' to 'set'
	template <class K, class Pr = std::less<K>, class A = std::allocator<K> >
    class Set : public ft::Tree<Tset_traits<K, Pr, A, false> >
	{
		public:
	        typedef Set<K, Pr, A> Myt;
			typedef Tree<Tset_traits<K, Pr, A, false> > MyBase;
			typedef K key_type;
			typedef Pr key_compare;
			typedef typename MyBase::value_compare      value_compare;
			typedef typename MyBase::allocator_type     allocator_type;
			typedef typename MyBase::size_type		    size_type;
			typedef typename MyBase::difference_type	difference_type;
			typedef typename MyBase::pointer			pointer;
			typedef typename MyBase::const_pointer		const_pointer;
			typedef typename MyBase::iterator			iterator;
			typedef typename MyBase::const_iterator		const_iterator;
			typedef typename MyBase::reverse_iterator	reverse_iterator;
			typedef typename MyBase::const_reverse_iterator	const_reverse_iterator;
			typedef typename MyBase::value_type			value_type;
			Set() : MyBase(key_compare(), allocator_type()) {}
			explicit Set(const key_compare &Pred) : MyBase(Pred, allocator_type()) {}
			Set(const key_compare &Pred, const allocator_type &Al) : MyBase(Pred, Al) {}
			template <class It>
			Set(It F, It L) : MyBase(key_compare(), allocator_type())
			{
				for (; F != L; ++F)
					this->insert(*F);
			}
			template <class It>
			Set(It F, It L, const key_compare Pred) : MyBase(Pred, allocator_type())
			{
				for (; F != L; ++F)
					this->insert(*F);
			}
			template <class It>
			Set(It F, It L, const key_compare &Pred, const allocator_type &Al) : MyBase(Pred, Al)
			{
				for (; F != L; ++F)
					this->insert(*F);
			}
	};
}

#endif
