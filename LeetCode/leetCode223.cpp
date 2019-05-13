#include "pch.h"
#include "allHeader.h"
using std::min;
using std::max;
/*
	223. 矩形面积

	在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

	每个矩形由其左下顶点和右上顶点坐标表示，如图所示。

	示例:
		输入: -3, 0, 3, 4, 0, -1, 9, 2
		输出: 45
		说明: 假设矩形面积不会超出 int 的范围。
*/


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int l = max(A, E), r = min(C, G), t = min(D, H), b = max(B, F);
	return (C - A)*(D - B) - (l < r ? r - l : 0)*(b < t ? t - b : 0) + (G - E) * (H - F);
}

// 网站最优解
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A)*(D - B);
		int area2 = (G - E)*(H - F);
		if (E >= C || F >= D || G <= A || H <= B) 
			return area1 + area2; //disjoint

		else if ((E >= A && G <= C && F >= B && H <= D) || (E <= A && G >= C && F <= B && H >= D)) 
			return max(area1, area2); //contain

		int overlap = (max(A, E) - min(C, G))*(max(B, F) - min(D, H));
		return area1 + area2 - overlap;
	}
};