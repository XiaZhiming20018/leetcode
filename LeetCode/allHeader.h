#pragma once

#include <algorithm>
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

//¶þ²æÊ÷
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// Á´±í
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};