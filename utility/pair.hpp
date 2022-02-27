#ifndef FT_PAIR
# define FT_PAIR

namespace ft
{
    template <class T, class U>
    struct pair
    {
        typedef T first_type;
        typedef U second_type;
        
        T first;
        U second;
        
        pair() : first(), second() {}

        pair(const T &X, const U &Y)
			: first(X), second(Y) {}
        
        template<class V, class W>
        pair(const pair<V, W> &pr)
			: first(pr.first), second(pr.second) {}

        void swap(pair<T, U> &pr)
        {
            pair<T, U> tmp(pr.first, pr.second);
            pr.first = this->first ;
            pr.second = this->second ;
            this->first = tmp.first;
            this->second = tmp.second;
        }

    };
		
	template <class T, class U>
	pair<T, U> make_pair(T X, U Y)
	{
		return pair<T, U>(X, Y);
	}
    
	template <class T, class U>
	bool  operator==(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return X.first == Y.first && X.second == Y.second;
	}

	template <class T, class U>
	bool operator!=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(X == Y);
	}

	template <class T, class U>
	bool operator<(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return X.first < Y.first || (!(Y.first < X.first) && X.second < Y.second);
	}

	template <class T, class U>
	bool operator>(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return Y < X;
	}

	template <class T, class U>
	bool operator<=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(Y < X);
	}

	template <class T, class U>
	bool operator>=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(X < Y);
	}

}

#endif