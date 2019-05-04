#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
149. 直线上最多的点数
	给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

	示例 1:
			输入: [[1,1],[2,2],[3,3]]
			输出: 3
			解释:
			^
			|
			|        o
			|     o
			|  o
			+------------->
			0  1  2  3  4

	示例 2:
			输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
			输出: 4
			解释:
			^
			|
			|  o
			|     o        o
			|        o
			|  o        o
			+------------------->
			0  1  2  3  4  5  6
*/


// 这题的想法比较简单，首先根据其中一个点与其他点进行斜率计算，如果斜率一样，就是一条直线上
// 但是要注意三个问题，第一： 斜率不存在的情况；
//					  第二： 有一组测试对数据精度有问题，[[0,0],[94911151,94911150],[94911152,94911151]] 这组数据的测试需要使用long double
//					  第三： 重复点的处理


int maxPoints(vector<vector<int>>& points) {
	int ans = 0;

	map<vector<int>, int> cnts;
	vector<vector<int>> keys{};

	for (auto p : points) {
		if (cnts.find(p) == cnts.end()) {
			cnts[p] = 1;
			keys.push_back(p);
		}
		else
			++cnts[p];
	}
	
	for (size_t i = 0; i < keys.size(); i++)
	{
		map<long double, int> slope{};
		for (size_t j = i + 1; j < keys.size(); j++)
		{
			long double k = DBL_MAX;
			if (keys[i][0] != keys[j][0])
				k = long double(keys[j][1] - keys[i][1]) / long double(keys[j][0] - keys[i][0]);
			
			if (slope.find(k) == slope.end())
				slope[k] = cnts[keys[i]];
			slope[k] += cnts[keys[j]];
		}
		int _max = 0;
		for (auto s : slope) {
			if (s.second > _max)
				_max = s.second;
		}
		ans = max(max(ans,cnts[keys[i]]), _max);
	}
	return ans;
}


// 以下为网站最优解

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 3) 
			return points.size();
		vector<int> temp = points[0];
		int max = 2;
		for (int i = 1; i < points.size(); i++) {
			int count = 0;
			long x1 = temp[0];
			long y1 = temp[1];
			long x2 = points[i][0];
			long y2 = points[i][1];
			if (x1 == x2 && y1 == y2) {
				for (int j = 0; j < points.size(); j++) {//求重复点
					if (x1 == points[j][0] && y1 == points[j][1]) {
						count++;
					}
				}
			}
			else {
				for (int j = 0; j < points.size(); j++) {
					long x3 = points[j][0];
					long y3 = points[j][1];
					if (((y3 - y2)*(x2 - x1)) == ((y2 - y1)*(x3 - x2))) {
						count++;
					}

				}
			}
			temp = points[i];
			max = std::max(max, count);

		}
		return max;
	}
};