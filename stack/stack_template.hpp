#ifndef FT_STACK_TEMPLATE_HPP
#define FT_STACK_TEMPLATE_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <class Type, class Container = ft::vector<Type> >
	class stack
	{
		public:
			typedef Container						container_type;

			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			stack();
			explicit stack(const container_type &cont);
			~stack();
			bool				empty() const;
			size_type			size() const;
			reference 			top();
			const_reference 	top() const;
			void 				push(const value_type &X);
			void 				pop();
			void				swap(stack &another_one);
			bool	Eq(const stack<Type, Container> &X) const;
			bool	Lt(const stack<Type, Container> &X) const;
	protected:
			container_type container;
	};
}

#endif
