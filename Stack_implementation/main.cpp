// Stack_implementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <exception>


/* Write routines to implement two stacks using only one array. Your stack routines
should not declare an overflow unless every slot in the array is used. */

/* That is why we assume that our stack is fixed (otherwise we could use std::vector or at least implement push_back, erase and insert methods in our array)
   in size and it is 8 cells in total */

template<typename T>
class Stack
{
public:
	Stack(const Stack&) = delete;
	explicit Stack()
	{
		capacity_st1 = capacity_st2 = size / 2;
		stack = new T[size];
	}

	T top_stack1() const // [0, capacity)
	{
		
	}

	T top_stack2() const // [capacity, size)
	{
		//return
	}

	bool empty_stack1() const
	{
		return !is_initialized_st1;
	}

	bool empty_stack2() const
	{
		return !is_initialized_st2;
	}

	void push_st1(const T& x) // [0, capacity)
	{
		if (capacity_st1) /* If stack is not full */
		{
			int temp_capacity = capacity_st1;
			stack[temp_capacity - capacity_st1] = x; // access violation
			--capacity_st1;
			is_initialized_st1 = true;
			++sz_st1;
		}
		else
			std::exception("Stack_1 is full\n");
	}

	void push_st2(const T& x) // [capacity, size)
	{
		if (capacity_st2) /* If stack is not full */
		{
			int temp_capacity = capacity_st2;
			stack[size - capacity_st2] = x;
			--capacity_st2;
			is_initialized_st2 = true;
			++sz_st2;
		}
		else
			std::exception("Stack_2 is full\n");
	}

	void pop_st1()
	{
		if (!empty_stack1())
		{
			++capacity_st1;
			--sz_st1;
		}
	}

	void pop_st2()
	{
		if (!empty_stack1())
		{
			++capacity_st2;
			--sz_st1;
		}
	}

	int size_st1() const
	{
		return sz_st1;
	}

	int size_st2() const
	{
		return sz_st2;
	}

private:
	T* stack;
	int capacity_st1;
	int capacity_st2;
	int size = 8;
	int sz_st1 = 0;
	int sz_st2 = 0;
	bool is_initialized_st1 = false;
	bool is_initialized_st2 = false;
};


int main()
{
	Stack<int> st;

	st.push_st1(2);
	std::cout << st.size_st1() << std::endl;
	std::cout << st.top_stack1() << std::endl;

    return 0;
}

