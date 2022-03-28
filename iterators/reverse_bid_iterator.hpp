#ifndef FT_REVERSE_BIG_ITERATOR_HPP
#define FT_REVERSE_BIG_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
    template<class BidIt>
    class reverse_bid_iterator : public iterator<
        typename ft::iterator_traits<BidIt>::iterator_category,
        typename ft::iterator_traits<BidIt>::value_type,
		typename ft::iterator_traits<BidIt>::difference_type,
        typename ft::iterator_traits<BidIt>::pointer,
        typename ft::iterator_traits<BidIt>::reference>
    {
        public:
            typedef reverse_iterator<BidIt> 							Myt;
            typedef typename iterator_traits<BidIt>::difference_type	difference_type;
            typedef typename iterator_traits<BidIt>::pointer			pointer;
            typedef typename iterator_traits<BidIt>::reference			reference;
            typedef BidIt 												iterator_type;

            reverse_bid_iterator() {}
            explicit reverse_bid_iterator(BidIt X)
                : current(X) {}

            BidIt base() const { return (current); }
			reverse_bid_iterator	&operator=(const reverse_bid_iterator &obj)
			{
				if (this != &obj)
					this->current = obj.current;
				return (*this);
			}
			reference	operator*() const { BidIt tmp = current; return (*--tmp); }
			pointer		operator->() const { reference tmp = **this; return (&tmp); }
            Myt			&operator++() { --current; return (*this); }
            Myt			&operator--() { ++current; return (*this); }
            Myt			operator++(int) { Myt Tmp = *this; --current; return (Tmp); }
            Myt			operator--(int) { Myt Tmp = *this; ++current; return (Tmp); }
            bool		operator==(const Myt &Y) const { return (current == Y.current); }
            bool		operator!=(const Myt &Y) const { return (!(*this == Y)); }
		protected:
    		BidIt current;
    };
}

#endif
