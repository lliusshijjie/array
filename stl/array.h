#pragma once
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "array_iterator.h"
#include "const_array_iterator.h"
#include "reverse_array_iterator.h"

namespace stl
{
	template<typename T, int N>
	class Array
	{
	public:
		typedef ArrayIterator<T> iterator;
		typedef ConstArrayIterator<T> const_iterator;
		typedef ReverseArrayIterator<T> reverse_iterator;

	public:
		Array() {
			memset(m_data, 0, sizeof(T) * N);
		}

		~Array() {
			
		}

		int size() const {
			return N;
		}

		bool empty() const {
			return N == 0;
		}

		T *data() {
			return m_data;
		}

		const T *data() const {
			return m_data;
		}

		// 要求大小相同
		void swap(Array<T, N> &other) {
			if (this == &other) return;

			for (int i = 0; i < N; i++) {
				auto temp = other.m_data[i];
				other.m_data[i] = m_data[i];
				m_data[i] = temp;
			}
		}

		void fill(const T &value) {
			for (int i = 0; i < N; i++) {
				m_data[i] = value;
			}
		}

		T &front() {
			return m_data[0];
		}

		const T &front() const {
			return m_data[0];
		}

		T &back() {
			return m_data[N - 1];
		}

		const T &back() const {
			return m_data[N - 1];
		}

		T &at(int index) {
			if (index < 0 || index >= N) {
				throw std::out_of_range("out of range");
			}
			return m_data[index];
		}

		const T &at(int index) const {
			if (index < 0 || index >= N) {
				throw std::out_of_range("out of range");
			}
			return m_data[index];
		}

		T &operator[](int index) {
			// 不检查下标范围
			return m_data[index];
		}

		const T &operator[](int index) const {
			// 不检查下标范围
			return m_data[index];
		}

		void show() const {
			std::cout << "size = " << size() << std::endl;
			for (int i = 0; i < N; i++) {
				std::cout << m_data[i] << " ";
			}
			std::cout << "\n";
		}
		
		// 普通迭代器
		iterator begin() {
			return iterator(m_data);
		}

		iterator end() {
			return iterator(m_data + N);
		}

		// 常量迭代器
		const_iterator cbegin() const {
			return const_iterator(m_data);
		}

		const_iterator cend() const {
			return const_iterator(m_data + N);
		}

		// 重载const版本的begin和end，返回常量迭代器
		const_iterator begin() const {
			return const_iterator(m_data);
		}

		const_iterator end() const {
			return const_iterator(m_data + N);
		}

		// 反向迭代器
		reverse_iterator rbegin() {
			return reverse_iterator(m_data + N);
		}

		reverse_iterator rend() {
			return reverse_iterator(m_data);
		}

	private:
		T m_data[N];
	};
}