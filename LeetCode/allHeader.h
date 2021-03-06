#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <memory>
#include <sstream>
#include <stack>
#include <map>
#include <climits>

//������
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ����
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};