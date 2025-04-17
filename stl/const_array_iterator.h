#pragma once

namespace stl
{
	template<typename T>
	class ConstArrayIterator
	{
		typedef ConstArrayIterator<T> const_iterator;

	public:
		ConstArrayIterator() : m_pointer(nullptr) {}
		ConstArrayIterator(const T *pointer) : m_pointer(pointer) {}
		~ConstArrayIterator() {}

		bool operator == (const const_iterator& other) const {
			return m_pointer == other.m_pointer;
		}

		bool operator != (const const_iterator& other) const {
			return m_pointer != other.m_pointer;
		}

		const_iterator & operator = (const const_iterator & other) {
			if (this == &other) return *this;
			m_pointer = other.m_pointer;
			return *this;
		}

		// 前缀++
		const_iterator &operator ++ () {
			m_pointer++;
			return *this;
		}

		// 后缀++
		const_iterator operator ++ (int) {
			auto it = *this;
			++(*this);
			return it;
		}

		const_iterator operator + (int n) {
			auto it = *this;
			it.m_pointer += n;
			return it;
		}

		const_iterator & operator += (int n) {
			m_pointer += n;
			return *this;
		}

		// 前缀--
		const_iterator & operator -- () {
			m_pointer--;
			return *this;
		}

		// 后缀--
		const_iterator operator --(int) {
			auto it = *this;
			--(*this);
			return it;
		}

		const_iterator operator - (int n) {
			auto it = *this;
			it.m_pointer -= n;
			return it;
		}

		const_iterator operator -= (int n) {
			m_pointer -= n;
			return *this;
		}

		int operator - (const const_iterator &other) const {
			return m_pointer - other.m_pointer;
		}

		// 这里返回常量引用，不能修改数据
		const T &operator *() const {
			return *m_pointer;
		}

		const T *operator ->() const {
			return m_pointer;
		}

	private:
		const T *m_pointer;
	};
} 