/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:25:50 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/05 07:28:22 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class contact
{
	std::string str[5];
	static std::string inputs[5];

	public:
	void	set(void)
	{
		int	i;

		i = -1;
		while (++i < 5)
		{
			std::cout << "input " << inputs[i] << ":";
			std::cin >> str[i];
		}
	}
	void	show_one(int index)
	{
		int	i;
		int	j;

		i = -1;
		std::cout << "         " << index << "|";
		while (++i < 3)
		{
			if (str[i].length() > 10)
				std::cout << str[i].substr(0, 10) << ".";
			else
			{
				j = -1;
				while (++j < 10 - str[i].length())
					std::cout << " ";
				std::cout << str[i];
			}
			if (i < 2)
				std::cout << "|";
		}
		std::cout << std::endl;
	}
	void	show_all(void)
	{
		int	i;

		i = -1;
		while (++i < 5)
			std::cout << inputs[i] << ":" << str[i] << std::endl;
	}
};

std::string contact::inputs[5] = {"first name", "last name", "nickname", "phonenumber", "darkest secret"};

class phonebook
{
	contact	*list;
	int		n;

	public:
	phonebook(void)
	{
		n = 0;
		list = 0;
	}
	~phonebook(void)
	{
		if (n)
		{
			delete []list;
			std::cout << "contact deleted bye\n";
		}
	}
	void	add(void)
	{
		if (!n)
			list = new contact[8];
		list[n % 8].set();
		++n;
	}
	void	show(void)
	{
		int	i;

		i = -1;
		if (!n)
			return ;
		std::cout << "     index|" << " first name|" << "  last name|" << "  nickname" << std::endl;
		while (++i < n && i <= 7)
			list[i].show_one(i + 1);
		i = wait_input();
		if (i <= n && i)
			list[i - 1].show_all();
		else
			std::cout << "please type correct one" << std::endl;
	}
	int	wait_input(void)
	{
		std::string	str;

		std::cin >> str;
		if (str.compare("1") == 0)
			return (1);
		else if (str.compare("2") == 0)
			return (2);
		else if (str.compare("3") == 0)
			return (3);
		else if (str.compare("4") == 0)
			return (4);
		else if (str.compare("5") == 0)
			return (5);
		else if (str.compare("6") == 0)
			return (6);
		else if (str.compare("7") == 0)
			return (7);
		else if (str.compare("8") == 0)
			return (8);
		return (0);
	}
};

int	process(void)
{
	std::string	str;

	std::cin >> str;
	if (str.compare("ADD") == 0)
		return (1);
	else if (str.compare("EXIT") == 0)
		return (0);
	else if (str.compare("SEARCH") == 0)
		return (2);
	return (3);
}

int	main(void)
{
	phonebook	p;
	int			code;

	code = 1;
	while (code)
	{
		code = process();
		if (code == 1)
			p.add();
		else if (code == 2)
			p.show();
	}
}
