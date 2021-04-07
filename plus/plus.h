#ifndef _PLUS_H_
#define _PLUS_H_

#include "stdio.h"
#include "linkedlist.h"
#include "iostream"
#include<python.h>
#include "opencv.hpp"
#include "new.h"
#include "set"
using namespace cv;
using namespace std;

 __declspec(dllexport) int my_plus(int a, int b);


 int lengthOfLongestSubstring(string s);
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
 bool isPalindrome(string s);
 string longestPalindrome(string s);
 int maxArea(vector<int>& height);
 int myAtoi(string s);
 vector<vector<int>> threeSum(vector<int>& nums);
 string intToRoman(int num);
 int threeSumClosest(vector<int>& nums, int target);
 void getAllAlphabet(int index, string &digits, vector<string> &result, string &current);
 vector<string> letterCombinations(string digits);
 vector<vector<int>> fourSum(vector<int>& nums, int target);
 bool parenthesesValid(const string str);
 void getAllParentheses(int n, vector<string> &result, string &current);
#endif // !_PLUS_H_
 //