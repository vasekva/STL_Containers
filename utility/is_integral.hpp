#ifndef FT_IS_INTEGRAL
# define FT_IS_INTEGRAL

namespace ft
{
	template< class T > 
    struct remove_const { typedef T type; };
    
    template< class T > 
    struct remove_const<const T> { typedef T type; };

    struct true_type { static const int value = 1; };
    struct false_type { static const int value = 0; };
    struct int_type { static const int value = 42; };

    template <typename>
    struct is_integral_base
			: public false_type {};

    template<>
    struct is_integral_base<bool>
			:	public true_type {};
    
    template<>
    struct is_integral_base<char>
			: public true_type {};
    
    template<>
    struct is_integral_base<signed char>
			: public true_type {};
    
    template<>
    struct is_integral_base<unsigned char>
			: public true_type {};
    
    template<>
    struct is_integral_base<wchar_t>
			: public true_type {};
    
    template<>
    struct is_integral_base<char16_t>
			: public true_type {};
    
    template<>
    struct is_integral_base<char32_t>
			: public true_type {};
    
    template<>
    struct is_integral_base<short>
			: public true_type {};
    
    template<>
    struct is_integral_base<unsigned short>
			: public true_type {};
    
    template<>
    struct is_integral_base<int>
			: public int_type {};
    
    template<>
    struct is_integral_base<unsigned int>
			: public true_type {};
    
    template<>
    struct is_integral_base<long>
			: public true_type {};
    
    template<>
    struct is_integral_base<unsigned long>
			: public true_type {};
    
    template<>
    struct is_integral_base<long long>
			: public true_type {};
    
    template<>
    struct is_integral_base<unsigned long long>
			: public true_type {};
    
    template<>
    struct is_integral_base<__int128_t>
			: public true_type {};
    
    template<>
    struct is_integral_base<__uint128_t>
			: public true_type {};


    template < class T >
    struct is_integral
			: public is_integral_base<typename remove_const<T>::type>
    {
    
    };

}

#endif