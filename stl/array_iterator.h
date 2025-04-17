#pragma once

namespace stl
{
	template<typename T>
	class ArrayIterator 
	{
		typedef ArrayIterator<T> iterator;

	public:
		ArrayIterator() : m_pointer(nullptr) {}
		ArrayIterator(T *pointer) : m_pointer(pointer) {}
		~ArrayIterator() {}

		bool operator == (const iterator& other) const {
			return m_pointer == other.m_pointer;
		}

		bool operator != (const iterator& other) const {
			return m_pointer != other.m_pointer;
		}

		iterator & operator = (const iterator & other) {
			if (this == &other) return *this;
			m_pointer = other.m_pointer;
			return *this;
		}

		// 前缀++
		iterator &operator ++ () {
			m_pointer++;
			return *this;
		}

		// 后缀++
		iterator operator ++ (int) {
			auto it = *this;
			++(*this);
			return it;
		}

		iterator operator + (int n) {
			auto it = *this;
			it.m_pointer += n;
			return it;
		}

		iterator & operator += (int n) {
			m_pointer += n;
			return *this;
		}

		// 前缀--
		iterator & operator -- () {
			m_pointer--;
			return *this;
		}

		// 后缀--
		iterator operator --(int) {
			auto it = *this;
			--(*this);
			return it;
		}

		iterator operator - (int n) {
			auto it = *this;
			it.m_pointer -= n;
			return it;
		}

		iterator operator -= (int n) {
			m_pointer -= n;
			return *this;
		}

		int operator - (const iterator &other) const {
			return m_pointer - other.m_pointer;
		}

		T &operator *() {
			return *m_pointer;
		}

		T *operator ->() {
			return m_pointer;
		}

	private:
		T *m_pointer;
	};
}