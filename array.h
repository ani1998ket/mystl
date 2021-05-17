#include <cstdlib>
#include <stdexcept>
#include <string>
#include <iterator>

namespace mystl{

template <typename T, size_t N>
class array{
public:
    using value_type                = T;
    using size_type                 = std::size_t;
    using reference                 = value_type&;
    using const_reference           = const value_type&;
    using pointer                   = value_type*;
    using const_pointer             = const value_type*;
    using iterator                  = pointer;
    using const_iterator            = const_pointer;
    using reverse_iterator          = std::reverse_iterator< iterator >;
    using const_reverse_iterator    = std::reverse_iterator< const_iterator >;
private:
    T m_data[N]; 
public:
    //Capacity
    constexpr size_type size() noexcept 
    { return N; }

    constexpr bool  empty() noexcept 
    { return N == 0; }

    constexpr size_type max_size() noexcept
    {
        return N;
    }

    // Modifiers
    void fill( const value_type& val ) // Handle exceptions
    {
        for( size_type i = 0; i < N; i++ )
        {
            m_data[i] = val;
        }
    }

    // void swap (array& x) noexcept(noexcept(swap(declval<value_type&>(),declval<value_type&>()))){
    //     /// See details
    // }

    // Element Access
    pointer data() noexcept
    {
        return m_data;
    }

    const pointer data() const noexcept
    {
        return m_data;
    }

    reference operator[] ( size_type n )
    {
        return m_data[n];
    }
    const_reference operator[] ( size_type n ) const 
    {
        return m_data[n];
    }

    reference at ( size_type n )
    {
        if( n >= N ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }

    const_reference at ( size_type n ) const 
    {
        if( n >= N ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }

    reference front(){
        return *begin();
    }
    const_reference front() const{
        return *begin();
    }
    reference back(){
        return *rbegin();
    }
    const_reference back() const{
        return *rbegin();
    }


    // iterators
    iterator begin() noexcept 
    {
        return m_data;
    }
    
    const_iterator begin() const noexcept 
    {
        return m_data;
    }

    iterator end() noexcept
    {
        return (m_data + N);
    }
    
    const_iterator end() const noexcept 
    {
        return (m_data + N);
    }

    reverse_iterator rbegin() noexcept 
    {
        return reverse_iterator( end() );
    }
    
    const_reverse_iterator rbegin() const noexcept 
    {
        return const_reverse_iterator( end() );
    }

    reverse_iterator rend() noexcept 
    {
        return reverse_iterator( begin() );
    }
    
    const_reverse_iterator rend() const noexcept 
    {
        return const_reverse_iterator( begin() );
    }

    const_iterator cbegin() const noexcept
    {
        return begin();
    }

    const_iterator cend() const noexcept
    {
        return end();
    }

    const_reverse_iterator crbegin() const noexcept
    {
        return const_reverse_iterator( end() );
    }

    const_reverse_iterator crend() const noexcept
    {
        return const_reverse_iterator( begin() );
    }
};

}