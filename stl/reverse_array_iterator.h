#pragma once

namespace stl
{
	template<typename T>
	class ReverseArrayIterator
	{
		typedef ReverseArrayIterator<T> reverse_iterator;

	public:
		ReverseArrayIterator() : m_pointer(nullptr) {}
		ReverseArrayIterator(T *pointer) : m_pointer(pointer) {}
		~ReverseArrayIterator() {}

		bool operator == (const reverse_iterator& other) const {
			return m_pointer == other.m_pointer;
		}

		bool operator != (const reverse_iterator& other) const {
			return m_pointer != other.m_pointer;
		}

		reverse_iterator & operator = (const reverse_iterator & other) {
			if (this == &other) return *this;
			m_pointer = other.m_pointer;
			return *this;
		}

		// 前缀++，反向迭代器++是向前移动，所以指针要--
		reverse_iterator &operator ++ () {
			m_pointer--;
			return *this;
		}

		// 后缀++
		reverse_iterator operator ++ (int) {
			auto it = *this;
			++(*this);
			return it;
		}

		reverse_iterator operator + (int n) {
			auto it = *this;
			it.m_pointer -= n; // 注意这里是减
			return it;
		}

		reverse_iterator & operator += (int n) {
			m_pointer -= n; // 注意这里是减
			return *this;
		}

		// 前缀--，反向迭代器--是向后移动，所以指针要++
		reverse_iterator & operator -- () {
			m_pointer++;
			return *this;
		}

		// 后缀--
		reverse_iterator operator --(int) {
			auto it = *this;
			--(*this);
			return it;
		}

		reverse_iterator operator - (int n) {
			auto it = *this;
			it.m_pointer += n; // 注意这里是加
			return it;
		}

		reverse_iterator & operator -= (int n) {
			m_pointer += n; // 注意这里是加
			return *this;
		}

		int operator - (const reverse_iterator &other) const {
			return other.m_pointer - m_pointer; // 注意方向相反
		}

		T &operator *() {
			// 反向迭代器解引用时需要先将指针-1
			return *(m_pointer - 1);
		}

		T *operator ->() {
			return (m_pointer - 1);
		}

	private:
		T *m_pointer;
	};
} 