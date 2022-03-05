
#ifndef __CIT_TREE__
#define __CIT_TREE__

#include "./xtree_prototypes.hpp"

namespace ft
{

	template <class Tree_traits>
	class const_iterator_tree :	public Bidit<typename Tree<Tree_traits>::value_type,
		typename Tree<Tree_traits>::difference_type,
		typename Tree<Tree_traits>::pointer,
		typename Tree<Tree_traits>::const_reference>,
	public iterator_pointers<Tree_traits>
	{
		public:
			typedef Bidit<typename Tree<Tree_traits>::value_type,
						typename Tree<Tree_traits>::Dift,
						typename Tree<Tree_traits>::Ctptr,
						typename Tree<Tree_traits>::const_reference> Mybase;
			
			typedef typename Mybase::iterator_category	iterator_category;
			typedef typename Mybase::difference_type	difference_type;
			typedef typename Mybase::value_type			value_type;
			typedef typename Mybase::pointer			pointer;
			typedef typename Mybase::reference			reference;


			typedef typename Tree<Tree_traits>::nodeptr nodeptr;
			typedef typename Tree<Tree_traits>::const_nodeptr const_nodeptr;

		protected:
				value_type& Value(const nodeptr &node){
					return(node->Value);
				}
		public:
			const_iterator_tree()
				: iterator_pointers<Tree_traits>() {}

			const_iterator_tree(const iterator_tree<Tree_traits> & X)
				: iterator_pointers<Tree_traits>(X) {
				}

				const_iterator_tree(const const_iterator_tree& X)
				: iterator_pointers<Tree_traits>(X) {
				}
			
			const_iterator_tree(const nodeptr &P)
				: iterator_pointers<Tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}

			const_iterator_tree(const const_nodeptr &P)
				: iterator_pointers<Tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}

			nodeptr GetNode() const
			{
				return(this->End);
			}

			reference operator*() const
			{
				return (this->Ptr->Value);
			}
			typename Tree<Tree_traits>::Ctptr operator->() const
			{
				return (&**this);
			}

			template <class It1, class It2>
			friend bool operator==(const It1& X, const It2& Y);
			template <class It1, class It2>
			friend bool operator!=(const It1& X, const It2& Y);
			
			const_iterator_tree &operator++()
			{
				Inc();
				return (*this);
			}

			const_iterator_tree operator++(int)
			{
				const_iterator_tree Tmp = *this;
				++*this;
				return (Tmp);
			}

			const_iterator_tree &operator--()
			{
				Dec();
				return (*this);
			}

			const_iterator_tree operator--(int)
			{
				const_iterator_tree Tmp = *this;
				--*this;
				return (Tmp);
			}
		protected:


			nodeptr Left(const nodeptr& node)
			{
				return ((nodeptr)(node->Left));
			}

			nodeptr Right(const nodeptr& node)
			{
				return ((nodeptr)(node->Right));
			}

			nodeptr Parent(const nodeptr& node)
			{
				return ((nodeptr)(node->Parent));
			}

			void Inc() {
				if (this->Last->Right != this->End)
					ReCount((nodeptr)this->End->Right);
				if (this->Ptr == this->End) {
					char *ptr = NULL; // Намеренная сега, чтобы пользователь знал, что мы выходим за this->End;
					*ptr = 0;
				}
				else if (Right(this->Ptr) != this->End) {
					this->Ptr = Right(this->Ptr);
					while ((nodeptr)this->Ptr->Left != this->End)
						this->Ptr = (nodeptr)(this->Ptr->Left);
				} else {
					nodeptr P;
					while ((P = Parent(this->Ptr)) != this->End && this->Ptr == Right(P))
						this->Ptr = P;
					this->Ptr = P;
				}
			}

			void Dec() {
				if (this->Last->Right != this->End)
					ReCount((nodeptr)this->End->Right);
				if (this->Ptr == this->End && this->End != this->Last) {
					this->Ptr = this->Last;
				} else if (this->Ptr == this->Begin) {
					char *ptr = NULL; // Намеренная сега, чтобы пользователь знал, что мы выходим за this->Begin;
					*ptr = 0;
				}
				else if (Left(this->Ptr) != this->End) {
					this->Ptr = Left(this->Ptr);
					while (this->Ptr->Right != this->End)
						this->Ptr = (nodeptr)(this->Ptr->Right);
				} else {
					nodeptr P;
					while ((P = Parent(this->Ptr)) != this->End && this->Ptr == Left(P))
						this->Ptr = P;
					this->Ptr = P;
				}
			}

			void ReCount (const_nodeptr NValue) {
					this->End = (nodeptr)NValue;
					while (this->End != this->End->Left)
						this->End = Left(this->End);					
					this->Last = Right(this->End);
					this->Begin = Right(this->End);
					while (Left(this->Begin) != this->End)
						this->Begin = Left(this->Begin);
					while (Right(this->Last) != this->End)
						this->Last = Right(this->Last);
			};
	};

}

#endif