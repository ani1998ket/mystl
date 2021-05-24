#pragma once

#include <cstdlib>
#include <memory>
#include <algorithm>

using std::fill;

namespace mystl{

template < class T >
class vector{
public:
    using value_type                    = T;
    using reference                     = value_type&;
    using const_reference               = const value_type&;
    using pointer                       = value_type*;
    using const_pointer                 = const value_type*;
    using size_type                     = std::size_t;
    using iterator                      = pointer;
    using const_iterator                = const_pointer;
    using reverse_iterator              = std::reverse_iterator< iterator >;
    using const_reverse_iterator        = std::reverse_iterator< const_iterator >;

private:
    pointer m_data;
    size_type m_size;
public:
    vector()
    {
        m_data = new value_type[0];
        m_size = 0;
    }

    explicit vector (size_type n, const value_type& val = value_type())
    {
        m_size = n;
        m_data = new value_type[n];
        fill(m_data, m_data + n, val);
    }

    vector (const vector& x)
    {
        // Implement
    }

    ~vector(){
        delete[] m_data;
        m_data = NULL;
    }

    void assign (size_type n, const value_type& val){
        delete[] m_data;
        m_size = n;
        m_data = new value_type[n];
        fill(m_data, m_data + n, val);
    }

    // Element Access
    pointer data() noexcept
    {
        return m_data;
    }

    const pointer data() const noexcept
    {
        return m_data;
    }

    reference at ( size_type n )
    {
        if( n >= m_size ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }

    const_reference at ( size_type n ) const 
    {
        if( n >= m_size ){
            throw std::out_of_range( "array::at" );
        } 
        return m_data[n];
    }

    reference operator[] ( size_type n )
    {
        return m_data[n];
    }

    const_reference operator[] ( size_type n ) const 
    {
        return m_data[n];
    }

    size_type size() const{
        return m_size;
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
        return (m_data + m_size);
    }
    
    const_iterator end() const noexcept 
    {
        return (m_data + m_size);
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