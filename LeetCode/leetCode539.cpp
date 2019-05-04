#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	539. 最小时间差

	给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并已分钟数表示。

	示例 1：
		输入: ["23:59","00:00"]
		输出: 1

	备注：
		列表中时间数在 2~20000 之间。
		每个时间取值在 00:00~23:59 之间。
*/

// 我的思路： 1. 转为数字存入二维数组； 2. 排序， 然后顺序相减； 3. 排序得最小值
int findMinDifference(vector<string>& timePoints) {
	vector<vector<int>> ls{};
	vector<int> res{};
	for (size_t i = 0; i < timePoints.size(); i++)
	{
		int f = atoi((timePoints[i].substr(0, 2)).c_str());
		int s = atoi((timePoints[i].substr(3, 2)).c_str());
		ls.push_back(vector<int>{f, s});
	}
	sort(ls.begin(), ls.end());
	for (size_t i = 1; i < ls.size(); i++)
	{
		int tmp = ls[i][0] * 60 + ls[i][1] - (ls[i - 1][0] * 60 + ls[i - 1][1]);
		res.push_back(tmp);
		res.push_back(1440 - tmp);
	}
	// 同时还有最大时间和最小时间的差值
	int tmp = ls[ls.size() - 1][0] * 60 + ls[ls.size() - 1][1] - (ls[0][0] * 60 + ls[0][1]);
	res.push_back(tmp);
	res.push_back(1440 - tmp);
	//排序求最小值
	sort(res.begin(), res.end());	
	return res[0];
}

// 网站最优解，思路基本一致，省略第二次排序

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		if (timePoints.size() > size) {
			return 0;
		}

		sort(begin(timePoints), end(timePoints));

		auto minDiff = INT_MAX;
		auto pre = str2Int(*(timePoints.end() - 1)) - size;
		for (auto time : timePoints) {
			auto intVal = str2Int(time);
			auto diff = intVal - pre;
			minDiff = min(minDiff, diff);
			pre = intVal;
		}

		return minDiff;
	}

	int str2Int(string &str) {
		return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3));
	}

	static constexpr int size = 60 * 24;
};