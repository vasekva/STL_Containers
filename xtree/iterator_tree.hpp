#ifndef FT_ITERATOR_TREE
#define FT_ITERATOR_TREE

#include "./xtree_prototypes.hpp"

namespace ft
{
	template <class Tree_traits>
	class iterator_tree : public Bidit<typename Tree<Tree_traits>::value_type,
		typename Tree<Tree_traits>::difference_type,
		typename Tree<Tree_traits>::pointer,
		typename Tree<Tree_traits>::reference>,
	public iterator_pointers<Tree_traits>
	{
		public:
			typedef Bidit<typename Tree<Tree_traits>::value_type,
			 			typename Tree<Tree_traits>::difference_type,
						typename Tree<Tree_traits>::pointer,
						typename Tree<Tree_traits>::reference> Mybase;
							
			typedef typename Mybase::iterator_category	iterator_category;
			typedef typename Mybase::difference_type	difference_type;
			typedef typename Mybase::value_type			value_type;
			typedef typename Mybase::pointer			pointer;
			typedef typename Mybase::reference			reference;

			typedef typename Tree<Tree_traits>::Nodeptr			nodeptr;
			typedef typename Tree<Tree_traits>::NodeptrConst	const_nodeptr;

			iterator_tree()
				: iterator_pointers<Tree_traits>(){}

			iterator_tree(const nodeptr &P)
				: iterator_pointers<Tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}

			iterator_tree(const const_nodeptr &P)
				: iterator_pointers<Tree_traits>(P) {
					this->End = P;
					ReCount(P);
			}

			nodeptr GetNode() const
			{
				return (this->End);
			}

			reference operator*() const {
				return (this->Ptr->Value);
			}

			typename Tree<Tree_traits>::pointer operator->() const {
				return (&**this);
			}

			bool		operator==(const iterator_tree X) const { return (GetNode() == X.GetNode()); }
//			bool		operator==(const iterator_tree X) const { return (Ptr == X.Ptr); }
			bool		operator!=(const iterator_tree X) const { return (!(*this == X)); }

//			template <class It1, class It2>
//			friend bool operator==(const It1& X, const It2& Y);

			template <class It1, class It2>
			friend bool operator!=(const It1& X, const It2& Y);

			iterator_tree &operator++()
			{
				Inc();
				return (*this);
			}

			iterator_tree operator++(int)
			{
				iterator_tree Tmp = *this;
				++*this;
				return (Tmp);
			}

			iterator_tree &operator--() {
				Dec();
				return (*this);
			}

			iterator_tree operator--(int) {
				iterator_tree Tmp = *this;
				--*this;
				return (Tmp);
			}
		protected:
			nodeptr Left(const nodeptr& node){
				return ((nodeptr)(node->Left));
			}

			nodeptr Right(const nodeptr& node){
				return ((nodeptr)(node->Right));
			}

			nodeptr Parent(const nodeptr& node){
				return ((nodeptr)(node->Parent));
			}
			
			void Inc() {
				if (this->Last->Right != this->End) {
					ReCount((nodeptr)(this->End->Right));
				}
				if (this->Ptr == this->End) {
					char *ptr = NULL;	// Намеренная сега, чтобы пользователь знал, что мы выходим за this->End;
					*ptr = 0;
				}
				else if (Right(this->Ptr) != this->End) {
					this->Ptr = Right(this->Ptr);
					while (this->Ptr->Left != this->End)
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
					ReCount((nodeptr)(this->End->Right));
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
			// Пересчет указателей			
			void ReCount (nodeptr NValue) {
					
					this->End = NValue;
					// NIL в левом указателе ссылается на самого себя
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