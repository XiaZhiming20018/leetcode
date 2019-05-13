#include "pch.h"
#include "allHeader.h"

using namespace std;

// ��һ��
/*
1020. ������ֳɺ���ȵ���������  ��ʾӢ������  

	����һ���������� A��ֻ�����ǿ��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false��
	��ʽ�ϣ�������ǿ����ҳ����� i+1 < j ������ (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) �Ϳ��Խ��������ȷ֡�
	
	ʾ�� 1��
		�����[0,2,1,-6,6,-7,9,1,2,0,1]
		�����true
		���ͣ�0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
	ʾ�� 2��
		���룺[0,2,1,-6,6,7,9,-1,2,0,1]
		�����false
	ʾ�� 3��
		���룺[3,3,6,5,-2,2,5,1,-9,4]
		�����true
		���ͣ�3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
*/

bool canThreePartsEqualSum(vector<int>& A) {
	long long sum = 0;     
	for (int i = 0; i < (int)A.size(); ++i) 
		sum += A[i];
	if (sum % 3 == 0) {
		long long x = A[0];
		int cnt = 0;
		for (int i = 1; i < (int)A.size(); ++i) {
			if (x == sum / 3) 
				x = 0, cnt += 1;
			x += A[i];
		}
		if (x == sum / 3) 
			cnt += 1;
		return cnt == 3;
	}
	else 
		return false;
}


// �ڶ���
/*
	1022. �ɱ� K ��������С����  ��ʾӢ������

		���������� K������Ҫ�ҳ����Ա� K �����ġ����������� 1 ����С������ N��
		���� N �ĳ��ȡ���������������� N���ͷ��� -1��

	ʾ�� 1��
		���룺1
		�����1
		���ͣ���С�Ĵ��� N = 1���䳤��Ϊ 1��
	ʾ�� 2��
		���룺2
		�����-1
		���ͣ������ڿɱ� 2 ������������ N ��
	ʾ�� 3��
		���룺3
		�����3
		���ͣ���С�Ĵ��� N = 111���䳤��Ϊ 3��
*/

int smallestRepunitDivByK(int K) {
	int sum = 0;
	for (int i = 1; i <= 10 * K; ++i) {
		(sum = sum * 10 + 1) %= K;
		if (sum == 0) return i;
	}
	return -1;
}

//������
/*
	1021. ��ѹ۹����  ��ʾӢ������
		�������������� A��A[i] ��ʾ�� i ���۹⾰������֣������������� i �� j ֮��ľ���Ϊ j - i��
		һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ��A[i] + A[j] + i - j�������������֮�ͼ�ȥ��������֮��ľ��롣
		����һ�Թ۹⾰����ȡ�õ���߷֡�

	ʾ����
		���룺[8,1,5,2,6]
		�����11
		���ͣ�i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
*/
int maxScoreSightseeingPair(vector<int>& A) {
	int mx = -10000000;
	int ans = mx;
	for (int i = 1; i < (int)A.size(); ++i) {
		mx = max(mx, A[i - 1] + i - 1);
		ans = max(ans, A[i] - i + mx);
	}
	return ans;
}

//������
/*
	1023. �Ӵ��ܱ�ʾ�� 1 �� N ���ֵĶ����ƴ�  ��ʾӢ������

		����һ���������ַ��� S��һ���������� '0' �� '1' ���ɵ��ַ�������һ�������� N��������ڴ� 1 �� N ��ÿ������ X��������Ʊ�ʾ���� S ���Ӵ����ͷ��� true�����򷵻� false��

	ʾ�� 1��
		���룺S = "0110", N = 3
		�����true
	ʾ�� 2��
		���룺S = "0110", N = 4
		�����false
*/

bool queryString(string S, int N) {
	int len = S.size();
	set<int> s;
	for (int j = 1; j <= min(len, 30); ++j) {
		for (int i = 0; i + j - 1 < len; ++i) {
			int num = 0;
			for (int k = i; k < i + j; ++k) {
				num <<= 1;
				num |= (int)(S[k] - '0');
			}
			//printf("%d\n", num);
			if (num <= N && num > 0) s.insert(num);
		}
	}
	return s.size() == N;
}