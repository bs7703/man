/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:32:04 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/11 12:28:12 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class megaphone
{
	std::string	*data;

	public:
	megaphone() {};
	public:
	megaphone(char **args)
	{
		int	i;

		i = 0;
		while (*(args + i))
			++i;
		if (i > 1)
		{
			data = new std::string[i];
			data[i - 1] = "";
			while (--i)
			{
				data[i - 1] = args[i];
				upper(data + i - 1);
			}
		}
		else
		{
			data = new std::string[2];
			data[0] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
			data[1] = "";
		}
	};
	public:
	void shout()
	{
		int	i;

		i = -1;
		while (data[++i].length() > 0)
			std::cout << data[i];
		std::cout << std::endl;
	}
	private:
	void upper(std::string *str)
	{
		int	i;
		int	size;

		i = -1;
		size = str->length();
		while (++i < size)
			(*str)[i] = toupper((*str)[i]);
	}
	public:
	~megaphone(void)
	{
		delete [] data;
	}
};

int	main(int n, char **args)
{
	megaphone	t = megaphone(args);

	t.shout();
}
