// Copyright (c) 2017-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2019 The Titancoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
// Taken from https://gist.github.com/arvidsson/7231973

#ifndef TTN_REVERSE_ITERATOR_H
#define TTN_REVERSE_ITERATOR_H

/**
 * Template used for reverse iteration in C++11 range-based for loops.
 * 
 *   std::vector<int> v = {1, 2, 3, 4, 5};
 *   for (auto x : reverse_iterate(v))
 *       std::cout << x << " ";
 */

template <typename T>
class reverse_range
{
    T &m_x;
    
public:
    explicit reverse_range(T &x) : m_x(x) {}
    
    auto begin() const -> decltype(this->m_x.rbegin())
    {
        return m_x.rbegin();
    }
    
    auto end() const -> decltype(this->m_x.rend())
    {
        return m_x.rend();
    }
};
 
template <typename T>
reverse_range<T> reverse_iterate(T &x)
{
    return reverse_range<T>(x);
}

#endif // TTN_REVERSE_ITERATOR_H
