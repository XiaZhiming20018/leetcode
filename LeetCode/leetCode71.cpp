#include "pch.h"
#include "allHeader.h"
using namespace std;

/*
�� Unix ������һ���ļ��ľ���·��������Ҫ���������߻��仰˵������ת��Ϊ�淶·����

�� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼�������⣬������ ��..�� ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼�������߶������Ǹ������·������ɲ��֡�������Ϣ����ģ�Linux / Unix�еľ���·�� vs ���·��

��ע�⣬���صĹ淶·������ʼ����б�� / ��ͷ����������Ŀ¼��֮�����ֻ��һ��б�� /�����һ��Ŀ¼����������ڣ������� / ��β�����⣬�淶·�������Ǳ�ʾ����·��������ַ�����


ʾ�� 1��
	���룺"/home/"
	�����"/home"
	���ͣ�ע�⣬���һ��Ŀ¼������û��б�ܡ�

ʾ�� 2��
	���룺"/../"
	�����"/"
	���ͣ��Ӹ�Ŀ¼����һ���ǲ����еģ���Ϊ��������Ե������߼���

ʾ�� 3��
	���룺"/home//foo/"
	�����"/home/foo"
	���ͣ��ڹ淶·���У��������б����Ҫ��һ��б���滻��

ʾ�� 4��
	���룺"/a/./b/../../c/"
	�����"/c"

ʾ�� 5��
	���룺"/a/../../b/../c//.//"
	�����"/c"

ʾ�� 6��
	���룺"/a//b////c/d//././/.."
	�����"/a/b/c"
*/

string simplifyPath1(string path)
{
	/**   �ҵ�˼·��
	***   �Ƚ��ַ������� / ���зָ�
	***   �� ���ַ��� ѹ��ջ
	**/
	path = path + '/'; // ��ֹ���һ�� ���ַ����޷�ʶ��
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
	// �������
	while (!tmp.empty())
	{
		result = tmp.top() + result;
		tmp.pop();
	}
	// ����������Ϊ��
	if (result.length() == 0)
		return "/";           
	return result;
}



//��վ���Ž⣬ ˼·��ͬ
string simplifyPath(string path) {
	stringstream ss(path);
	stack<string>s;
	string line;
	/**  
	***   ���ַ������� / �������У� �γ� ���ַ��� 
	***   û�н� / ��������
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