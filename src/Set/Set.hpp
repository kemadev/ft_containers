#ifndef SET_HPP
#define SET_HPP
#include <cmath>
#include <iostream>
#include <string>

#include "../Map/Map.hpp"

namespace ft {

template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class set {
	private:
		ft::map<T,T,Compare,Alloc> _container;
	public:
		typedef typename ft::map<T,T,Compare,Alloc>::iterator iterator;
		typedef typename ft::map<T,T,Compare,Alloc>::const_iterator const_iterator;
		typedef typename ft::map<T,T,Compare,Alloc>::reverse_iterator reverse_iterator;
		typedef typename ft::map<T,T,Compare,Alloc>::const_reverse_iterator const_reverse_iterator;
		typedef typename ft::map<T,T,Compare,Alloc>::key_type key_type;
		typedef typename ft::map<T,T,Compare,Alloc>::value_type value_type;
		typedef typename ft::map<T,T,Compare,Alloc>::key_compare key_compare;
		typedef typename ft::map<T,T,Compare,Alloc>::value_compare value_compare;
		typedef typename ft::map<T,T,Compare,Alloc>::allocator_type allocator_type;
		// typedef typename ft::map<T,T,Compare,Alloc>::reference reference;
		// typedef typename ft::map<T,T,Compare,Alloc>::const_reference const_reference;
		typedef typename ft::map<T,T,Compare,Alloc>::size_type size_type;
		typedef typename ft::map<T,T,Compare,Alloc>::difference_type difference_type;
		// typedef typename ft::map<T,T,Compare,Alloc>::pointer pointer;
		// typedef typename ft::map<T,T,Compare,Alloc>::const_pointer const_pointer;

		set() : _container() {};
		set(const set& other) : _container(other._container) {};
		template<class InputIterator>
		set(InputIterator first, InputIterator last) : _container(first, last) {};
		set& operator=(const set& other) {
			_container = other._container;
			return *this;
		};

		iterator begin() { return _container.begin(); };
		iterator end() { return _container.end(); };
		const_iterator begin() const { return _container.begin(); };
		const_iterator end() const { return _container.end(); };
		reverse_iterator rbegin() { return _container.rbegin(); };
		reverse_iterator rend() { return _container.rend(); };
		const_reverse_iterator rbegin() const { return _container.rbegin(); };
		const_reverse_iterator rend() const { return _container.rend(); };

		bool empty() const { return _container.empty(); };
		size_type size() const { return _container.size(); };
		size_type max_size() const { return _container.max_size(); };
		ft::pair<iterator, bool> insert(const value_type& val) { return _container.insert(val); };
		iterator insert(iterator position, const value_type& val) { return _container.insert(position, val); };
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last) { _container.insert(first, last); };
		void erase(iterator it) { _container.erase(it); };
		void erase(iterator first, iterator last) { _container.erase(first, last); };
		size_type erase(const T& value) { return _container.erase(value); };
		void swap(set& other) { _container.swap(other._container); };
		void clear() { _container.clear(); };
		key_compare key_comp() const { return _container.key_comp(); };
		value_compare value_comp() const { return _container.value_comp(); };

		iterator find(const T& value) { return _container.find(value); };
		const_iterator find(const T& value) const { return _container.find(value); };
		size_type count(const T& value) const { return _container.count(value); };
		iterator lower_bound(const T& value) { return _container.lower_bound(value); };
		const_iterator lower_bound(const T& value) const { return _container.lower_bound(value); };
		iterator upper_bound(const T& value) { return _container.upper_bound(value); };
		const_iterator upper_bound(const T& value) const { return _container.upper_bound(value); };
		ft::pair<iterator, iterator> equal_range(const T& value) { return _container.equal_range(value); };
		ft::pair<const_iterator, const_iterator> equal_range(const T& value) const { return _container.equal_range(value); };
		allocator_type get_allocator() const { return _container.get_allocator(); };
};
}  // namespace ft
#endif
