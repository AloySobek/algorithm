/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBinaryTree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:41:06 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 22:41:06 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BINARY_TREE_HPP
# define CLASS_BINARY_TREE_HPP

# include <cstdint>
# include <iostream>
# include <thread>
# include <cassert>

template <class T>
class BinaryTree
{
	public:
		BinaryTree(T data = 0) : head{data, nullptr, nullptr}, size(1) { }

		uint32_t	getSize() { return size; }

		void push	(T data)					{ __push(data, &head); }
		void map	(void (*pfnFunction)(T &))	{ __map(pfnFunction, &head); }
		void print	()							{ __print(0, &head); }

		 ~BinaryTree() { __clean(&head); }

	protected:
		struct body_s { T data; struct body_s *pRight; struct body_s *pLeft; };
		struct body_s	head;
		uint32_t		size;

		void	__push(T data, struct body_s *pStart);
		void	__map(void (*pfnFunction)(T &), struct body_s *pStart);
		void	__print(uint32_t level, struct body_s *pStart);

		struct body_s	*__leftRotate(struct body_s *pPointAround);
		struct body_s	*__rightRotate(struct body_s *pPointAround);
		void			__clean(struct body_s *pStart);
};

template<typename T>
void BinaryTree<T>::__print(uint32_t level, struct body_s *pStart)
{
	if (pStart)
	{
		__print(level + 1, pStart->pRight);
		for (int i = 0; i < level; ++i)
			std::cout << "      ";
		std::cout << pStart->data << std::endl;
		__print(level + 1, pStart->pLeft);
	}
}

template<typename T>
void BinaryTree<T>::__map(void (pfnFunction)(T &), struct body_s *pStart)
{
	if (pStart)
	{
		__map(pfnFunction, pStart->pRight);
		pfnFunction(pStart->data);
		__map(pfnFunction, pStart->pLeft);
	}
}

template<typename T>
BinaryTree<T>::struct body_s	*BinaryTree<T>::__leftRotate(struct body_s *pPointAround)
{
	assert(pPointAround && "Internal error, algorithm isn't working correct");
	T tmp = pPointAround->pRight;
	pPointAround->pRight = tmp->pLeft;
	tmp->pLeft	= pPointAround;
}

template<typename T>
BinaryTree<T>::struct body_s	*BinaryTree<T>::__rightRotate(struct body_s *pPointAround)
{
	assert(pPointAround && "Internal error, algorithm isn't working correct");
	T tmp = pPointAround->pLeft;
	pPointAround->pLeft = tmp->pRight;
	tmp->pRight = pPointAround;
}

template<typename T>
void BinaryTree<T>::__push(T data, struct body_s *pStart)
{
	if (pStart)
	{
		if (data > pStart->data)
		{
			if (pStart->pRight)
				__push(data, pStart->pRight);
			else
			{
				pStart->pRight = new struct body_s;
				pStart->pRight->data	= data;
				pStart->pRight->pLeft	= nullptr;
				pStart->pRight->pRight	= nullptr;
				++size;
			}
		}
		else
		{
			if (pStart->pLeft)
				__push(data, pStart->pLeft);
			else
			{
				pStart->pLeft = new struct body_s;
				pStart->pLeft->data		= data;
				pStart->pLeft->pLeft	= nullptr;
				pStart->pLeft->pRight	= nullptr;
				++size;
			}
		}
	}
}

template<typename T>
void BinaryTree<T>::__clean(struct body_s *pStart)
{
	if (pStart)
	{
		__clean(pStart->pRight);
		__clean(pStart->pLeft);
		if (pStart != &head)
			delete[] pStart;
	}
}

#endif