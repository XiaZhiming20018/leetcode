#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。


示例 1：
	输入："/home/"
	输出："/home"
	解释：注意，最后一个目录名后面没有斜杠。

示例 2：
	输入："/../"
	输出："/"
	解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。

示例 3：
	输入："/home//foo/"
	输出："/home/foo"
	解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。

示例 4：
	输入："/a/./b/../../c/"
	输出："/c"

示例 5：
	输入："/a/../../b/../c//.//"
	输出："/c"

示例 6：
	输入："/a//b////c/d//././/.."
	输出："/a/b/c"
*/

string simplifyPath1(string path)
{
	/**   我的思路：
	***   先将字符串按照 / 进行分割
	***   将 子字符串 压入栈
	**/
	path = path + '/'; // 防止最后一个 子字符串无法识别
	vector<string> re{};
	string result{};	
	stack<string> tmp{};
	string::size_type pos1 = 0, pos2 = path.find('/',1);
	while (string::npos!=pos2)
	{
		re.push_back(path.substr(pos1, pos2 - pos1));

		pos1 = pos2;
		pos2 = path.find('/', pos1 + 1);
	}
	//if (pos1 != path.length())
	//	re.push_back(path.substr(pos1));

	for (auto r : re)
	{
		if (r == "/." || r == "/")
			continue;
		else if (r == "/..")
		{
			if (!tmp.empty())
				tmp.pop();
		}
		else
			tmp.push(r);
	}
	// 倒序输出
	while (!tmp.empty())
	{
		result = tmp.top() + result;
		tmp.pop();
	}
	// 最后输出不能为空
	if (result.length() == 0)
		return "/";           
	return result;
}



//网站最优解， 思路相同
string simplifyPath(string path) {
	stringstream ss(path);
	stack<string>s;
	string line;
	/**  
	***   将字符串按照 / 输入流中， 形成 子字符串 
	***   没有将 / 放入其中
	***
	**/
	while (getline(ss, line, '/'))
	{
		if (line == "/" || line == "." || line.size() == 0)
			continue;
		else if (line == "..")
		{
			if (!s.empty())
				s.pop();
		}
		else
			s.push(line);
	}
	string res = "";
	while (!s.empty())
	{
		res = "/" + s.top() + res;
		s.pop();
	}
	return res.size() == 0 ? "/" : res;
}