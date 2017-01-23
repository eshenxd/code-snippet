#ifndef _SPLIT_PATH_H_
#define _SPLIT_PATH_H_

#include <vector>
#include <string>



/*!
 * \brief 字符串分割函数
 * \param str  待分割的字符串
 * \param pattern  分割依据
 * \return 以pattern分割的所有子串
 *
*/
std::vector<std::string> SplitPath(std::string str, std::string pattern);


std::vector<std::string> SplitPath(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作
	size_t size = str.size();

	for (size_t i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

/*
//test
  int main(int argc, char* argv[])
  {
  string out1 = "D:/test1/test2/test3/test4.jpg";
  string out2 = "2";

  vector<string>results = SplitPath(out1, "/");
  return 0;
  }
*/

#endif /* end split_path.hpp */