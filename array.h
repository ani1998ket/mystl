#include <cstdlib>
#include <stdexcept>
#include <string>

namespace mystl{

template <typename T, size_t N>
class array{
    using value_type                = T;
    using size_type                 = std::size_t;
    using reference                 = value_type&;
    using const_reference           = const value_type&;
    using pointer                   = value_type*;
    using const_pointer             = const value_type*;
    using reverse_iterator          = std::reverse_iterator< iterator >
    using const_reverse_iterator    = td::reverse_iterator< const_iterator > 
private:
    T m_data[N]; 
public:
    constexpr size_type size() noexcept 
    { return N; }

    constexpr bool  empty() noexcept 
    { return N == 0; }

    void fill( const value_type& val ) // Handle exceptions
    {
        for( size_type i = 0; i < N; i++ ){
            m_data[i] = val;
        }
    }

    pointer data() noexcept{
        return m_data;
    }

    const pointer data() const noexcept{
        return m_data;
    }

    reference operator[] ( size_type n ){
        return m_data[n];
    }
    const_reference operator[] ( size_type n ) const {
        return m_data[n];
    }

    reference at ( size_type n ){
        if( n >= N ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }
    const_reference at ( size_type n ) const {
        if( n >= N ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }

    // iterators
    iterator begin() noexcept {
        return m_data;
    }
    
    const_iterator begin() const noexcept {
        return m_data;
    }

    iterator end() noexcept{
        return (m_data + N);
    }
    
    const_iterator end() const noexcept {
        return (m_data + N);
    }

    reverse_iterator rbegin() noexcept {
        return reverse_iterator( end() );
    }
    
    const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator( end() );
    }

    reverse_iterator rend() noexcept {
        return reverse_iterator( begin() );
    }
    
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator( begin() );
    }
};

}