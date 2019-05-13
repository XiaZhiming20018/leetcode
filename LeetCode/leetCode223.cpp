#include "pch.h"
#include "allHeader.h"
using std::min;
using std::max;
/*
	223. �������

	�ڶ�άƽ���ϼ����������ֱ�߹��ɵľ����ص����γɵ��������

	ÿ�������������¶�������϶��������ʾ����ͼ��ʾ��

	ʾ��:
		����: -3, 0, 3, 4, 0, -1, 9, 2
		���: 45
		˵��: �������������ᳬ�� int �ķ�Χ��
*/


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int l = max(A, E), r = min(C, G), t = min(D, H), b = max(B, F);
	return (C - A)*(D - B) - (l < r ? r - l : 0)*(b < t ? t - b : 0) + (G - E) * (H - F);
}

// ��վ���Ž�
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