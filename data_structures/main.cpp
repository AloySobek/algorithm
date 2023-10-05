/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:47:59 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 23:47:59 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClassBinaryTree.hpp"
# include <time.h>

void test(int32_t &data)
{
	data *= 2;
}

int	main(int argc, char **argv)
{
	BinaryTree<int32_t>	tree(25);

	srand(time(nullptr));

	for (int i = 0; i < 30; ++i)
		tree.push(rand() % 50);

	tree.print();
	return (0);
}