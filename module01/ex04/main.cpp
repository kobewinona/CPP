/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <dklimkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:07:05 by dklimkin          #+#    #+#             */
/*   Updated: 2024/05/13 23:31:37 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#define READFILE_ERR "Cannot open file"
#define FEWARGS_ERR "Too few arguments provided"

std::string getFileContent(char *filename)
{
  std::string fileContent, line;
  std::ifstream file;

  file.open(filename);
  if (file.fail())
    return (std::cerr << READFILE_ERR << std::endl, "");

  while (std::getline(file, line))
    fileContent += file.eof() ? line : (line + '\n');

  return (file.close(), fileContent);
};

void replaceStringsInContent(std::string &content, const std::string &s1, const std::string &s2)
{
  size_t s1Len = s1.length(), s2Len = s2.length();
  size_t pos = 0;

  while ((pos = content.find(s1, pos)) != std::string::npos)
  {
    std::string before = content.substr(0, pos);
    std::string after = content.substr((pos + s1Len));
    content = before + s2 + after;
    pos += s2Len;
  }
};

void createFileWithNewContent(char *filename, std::string newFileContent)
{
  std::ofstream file;

  file.open((std::string(filename) + ".replace").c_str());
  if (file.fail())
  {
    std::cerr << READFILE_ERR << std::endl;
    return;
  }

  file << newFileContent;

  return (file.close());
};

int main(int argc, char **argv)
{
  if (argc < 4)
    return (std::cerr << FEWARGS_ERR << std::endl, EXIT_FAILURE);

  std::string fileContent = getFileContent(argv[1]);
  if (fileContent.empty())
    return (EXIT_FAILURE);

  replaceStringsInContent(fileContent, argv[2], argv[3]);
  createFileWithNewContent(argv[1], fileContent);

  return (EXIT_SUCCESS);
};
