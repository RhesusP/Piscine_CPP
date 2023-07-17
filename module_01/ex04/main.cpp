/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:06:13 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/17 15:45:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

// ./prog filename s1 s2
int	main(int argc, char **argv) {
	char		*filename;
	std::string	line;

	if (argc != 4)
	{
		std::cout << "Usage error: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	filename = argv[1];
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	std::ifstream	file(filename);
	std::ofstream	outfile(filename + std::string(".replace"));
	int i;
	while (std::getline(file, line))
	{
		i = 0;
		while (i < (int)line.size())
		{
			if (line.substr(i, s1.size()) == s1)
			{
				outfile << s2;
				i += s1.size();
			}
			else
			{
				outfile << line[i];
				i++;
			}
		}
		outfile << "\n";
	}
	file.close();
	outfile.close();
	return (0);
}
