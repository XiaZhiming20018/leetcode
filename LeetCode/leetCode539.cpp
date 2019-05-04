#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
	539. ��Сʱ���

	����һ�� 24 Сʱ�ƣ�Сʱ:���ӣ���ʱ���б��ҳ��б�����������ʱ�����Сʱ���ѷ�������ʾ��

	ʾ�� 1��
		����: ["23:59","00:00"]
		���: 1

	��ע��
		�б���ʱ������ 2~20000 ֮�䡣
		ÿ��ʱ��ȡֵ�� 00:00~23:59 ֮�䡣
*/

// �ҵ�˼·�� 1. תΪ���ִ����ά���飻 2. ���� Ȼ��˳������� 3. �������Сֵ
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
	// ͬʱ�������ʱ�����Сʱ��Ĳ�ֵ
	int tmp = ls[ls.size() - 1][0] * 60 + ls[ls.size() - 1][1] - (ls[0][0] * 60 + ls[0][1]);
	res.push_back(tmp);
	res.push_back(1440 - tmp);
	//��������Сֵ
	sort(res.begin(), res.end());	
	return res[0];
}

// ��վ���Ž⣬˼·����һ�£�ʡ�Եڶ�������

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