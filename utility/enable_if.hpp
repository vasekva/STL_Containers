#ifndef FT_ENABLE_IF
# define FT_ENABLE_IF


/*
** Тип T включается как тип элемента enable_if::тип, если условие равно true.
** 
** В противном случае enable_if::тип не определен.
**
** Это полезно для скрытия подписей во время компиляции, когда не выполняется определенное условие, так как в этом случае элемент enable_if::тип не будет определен, и попытка компиляции с его использованием должна завершиться неудачей
**
*/

// 1. возвращаемый тип (bool) допустим только в том случае, если T является целочисленным типом:
// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type   is_odd (T i)
// {
//     return bool(i % 2);
// }

// // 2. второй аргумент шаблона допустим только в том случае, если T является целочисленным типом:
// template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even (T i)
// {
//     return !bool(i % 2);
// }

// int main()
// {
//     short int i = 1;    // code does not compile if type of i is not integral

//     std::cout << std::boolalpha;
//     std::cout << "i is odd: " << is_odd(i) << std::endl;
//     std::cout << "i is even: " << is_even(i) << std::endl;

//     return 0;
// }

namespace ft
{
	template<bool B, class T = void>
    struct enable_if
    {

    };
    
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

}

#endif