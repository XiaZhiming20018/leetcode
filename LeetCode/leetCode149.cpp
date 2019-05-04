#include "pch.h"
#include "allHeader.h"

using namespace std;

/*
149. ֱ�������ĵ���
	����һ����άƽ�棬ƽ������ n ���㣬������ж��ٸ�����ͬһ��ֱ���ϡ�

	ʾ�� 1:
			����: [[1,1],[2,2],[3,3]]
			���: 3
			����:
			^
			|
			|        o
			|     o
			|  o
			+------------->
			0  1  2  3  4

	ʾ�� 2:
			����: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
			���: 4
			����:
			^
			|
			|  o
			|     o        o
			|        o
			|  o        o
			+------------------->
			0  1  2  3  4  5  6
*/


// ������뷨�Ƚϼ򵥣����ȸ�������һ���������������б�ʼ��㣬���б��һ��������һ��ֱ����
// ����Ҫע���������⣬��һ�� б�ʲ����ڵ������
//					  �ڶ��� ��һ����Զ����ݾ��������⣬[[0,0],[94911151,94911150],[94911152,94911151]] �������ݵĲ�����Ҫʹ��long double
//					  ������ �ظ���Ĵ���


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


// ����Ϊ��վ���Ž�

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
				for (int j = 0; j < points.size(); j++) {//���ظ���
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