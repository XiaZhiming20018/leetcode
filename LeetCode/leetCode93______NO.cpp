#include "pch.h"
#include "allHeader.h"
using namespace std;

/*

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:
	输入: "25525511135"
	输出: ["255.255.11.135", "255.255.111.35"]

*/



//从第l位置取m个
//atoi()   转化为数字，但是只适用于char类型数组
// substr(pos,n)  从第pos个位置拷贝n个字符
// c_str()   将string类型转化为char类型数组


void findIp(string s, int f, int idx, string ip, vector<string> &res) {
	if (idx == 3)
	{
		if (s.size() - 1 - f < 3)
		{
			if (s[f] == '0' && f != s.size() - 1) return;
			int num = stoi(s.substr(f, s.size() - f));
			if (num < 256)
			{
				ip += to_string(num);
				res.push_back(ip);
			}
		}
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			if (f + i >= s.size()) break;
			int num = stoi(s.substr(f, i));
			if (num < 256)
				findIp(s, f + i, idx + 1, ip + to_string(num) + ".", res);
			if (s[f] == '0' && i == 1) break;
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	findIp(s, 0, 0, "", res);
	return res;
}

// 网站最优解

class Solution {
private:
	bool isValid(string s) {
		if (s.empty() || s.size() > 3) {
			return false;
		}
		if ('0' == s.at(0) && s.size() > 1) {
			return false;
		}
		if (stoi(s) < 0 || stoi(s) > 255) {
			return false;
		}

		return true;
	}

	void restoreIpAddresses(string s, string tmp, vector<string>& res, int segnum) {
		if (4 == segnum && isValid(s)) {
			res.push_back(tmp + s);
			return;
		}
		if (segnum > 4) {
			return;
		}

		for (int i = 1; i < 4 && i < s.size(); i++) {
			string sub = s.substr(0, i);

			if (isValid(sub)) {
				restoreIpAddresses(s.substr(sub.size()), tmp + sub + ".", res, segnum + 1);
			}
		}
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;

		if (s.size() < 4 || s.size() > 4 * 3) {
			return res;
		}

		restoreIpAddresses(s, "", res, 1);
		return res;
	}
};




