#ifndef COLLECTIONS_MAP_HPP
#define COLLECTIONS_MAP_HPP

#include <stdlib.h>
#include <memory>

#include "../utility/pair.hpp"
#include "../iterators/iterator.hpp"

using namespace std;

namespace ft
{
	template <class Key, class T, class Pred = std::less<Key>,
		class A = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key					key_type;
			typedef T					mapped_type;
			typedef Pred				key_compare;
			typedef A					allocator_type;
			typedef pair<const Key, T>	value_type;
			class value_compare;

//			typedef A::pointer			pointer;
//			typedef A::const_pointer	const_pointer;
//			typedef A::reference		reference;
//			typedef A::const_reference	const_reference;
			typedef size_t				size_type;
			typedef long int			difference_type;

			//TODO: add these iterators
//			typedef T0					iterator;
//			typedef T1					const_iterator;

//			typedef reverse_iterator<const_iterator>
//				const_reverse_iterator;
//			typedef reverse_iterator<iterator> reverse_iterator;

			map();
			explicit map(const Pred &comp);
			map(const Pred &comp, const A &al);
			map(const map &X);
			template <class InIt>
			map(InIt first, InIt last);
			template <class InIt>
			map(InIt first, InIt last, const Pred &comp);
			template <class InIt>
			map(InIt first, InIt last, const Pred &comp, const A &al);

//			iterator				begin();
//			const_iterator			begin() const;
//			iterator				end();
//			const_iterator			end() const;
//			reverse_iterator		rbegin();
//			const_reverse_iterator	rbegin() const;
//			reverse_iterator		rend();
//			const_reverse_iterator	rend() const;
			size_type				size() const;
			size_type				max_size() const;
			bool					empty() const;
			A						get_allocator() const;
			mapped_type	operator[](const Key &key);
//			pair<iterator, bool>	insert(const value_type &X);
//			iterator				insert(iterator it, const value_type &X);
			template <class InIt>
			void					insert(InIt first, InIt last);
//			iterator				erase(iterator it);
//			iterator				erase(iterator first, iterator last);
			size_type				erase(const Key &key);
			void					clear();
			void					swap(map &X);
			key_compare				key_comp() const;
			value_compare			value_comp() const;
//			iterator				find(const Key &key);
//			const_iterator			find(const Key &key) const;
			size_type				count(const Key &key) const;
//			iterator				lower_bound(const Key &key);
//			const_iterator			lower_bound(const Key &key) const;
//			iterator				upper_bound(const Key &key);
//			const_iterator			upper_bound(const Key &key) const;
//			pair<iterator, iterator>				equal_range(const Key &key);
//			pair<const_iterator, const_iterator>	equal_range(const Key &key) const;
	};
}

#endif