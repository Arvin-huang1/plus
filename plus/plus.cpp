#include "plus.h"

int my_plus(int a, int b)
{
	return a + b;
}

//find函数,迭代器对指针运算符进行重载
template<class Iterator, class T>
Iterator find(Iterator First, Iterator Last, const T &val)
{
	while (*First != val && First != Last)
	{
		First++;
	}
	return First;
}

//子串长度
int lengthOfLongestSubstring(string s) {
	int maxLength = 0;
	//顺序查找，一次找到每个最大不重复子串，用哈希集合保存
	set<char> occ;
	int right = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i > 0)
		{
			occ.erase(occ.begin());
		}
		int m = occ.count(s[right]);
		while (right < s.size() && occ.count(s[right]) == 0)
		{
			occ.insert(s[right]);
			right++;
		}
		cout << occ.size() << endl;
		maxLength = max(maxLength, int(occ.size()));
	}
	return maxLength;
}

//4.中位数合并
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	for (int i = 0; i < nums2.size(); i++)
	{
		nums1.push_back(nums2[i]);
	}
	sort(nums1.begin(), nums1.end());
	if (nums1.size() % 2 == 0)
	{
		return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
	}
	else {
		return nums1[nums1.size() / 2];
	}
}

//5.回文子串
bool isPalindrome(string s) {
	int left = 0;
	int right = s.size() - 1;
	if (s.size() == 1)
	{
		return true;
	}
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		right--;
		left++;

	}
	return true;
}
string longestPalindrome(string s)
{
	//暴力法找到所有的子串判断是否是回文字符串。
	/*
	int maxLength = 0;
	string maxStr;
	if (s.size() <= 1)
	return s;
	for (int i = 0; i < s.size(); i++)
	{
	for (int j = 1; j < s.size()-i+1; j++)
	{
	string s_tmp = s.substr(i, j);
	string s_tmp_rev = s_tmp;
	reverse(s_tmp_rev.begin(), s_tmp_rev.end());
	if (s_tmp == s_tmp_rev && s_tmp.size() > maxLength)
	{
	cout << s_tmp << ' ' << isPalindrome(s_tmp) << " " << i << " " << j << endl;
	maxStr = s_tmp;
	maxLength = max(maxLength, int(s_tmp.size()));
	}

	//if (isPalindrome(s_tmp) && s_tmp.size() > maxLength)
	//{
	//
	//}
	}
	}*/

	//中心扩展法，从中心开始查找，不是回文next
	if (s.size() <= 1)
	{
		return s;
	}
	int maxLen = 0;
	string  maxStr = "";
	//奇数的
	for (int c = 0; c < s.size(); c++)
	{
		int i = 0;//0的时候肯定相等，第一次肯定满足
		while ((c - i) >= 0 && (c + i) <s.size() && s[c - i] == s[c + i])
		{
			i++;
		}
		i = i - 1;
		if (2 * i + 1>maxLen)//更新字符串
		{
			maxStr = s.substr(c - i, 2 * i + 1);
			maxLen = maxStr.size();
		}
	}

	//偶数的
	for (int c = 0; c < s.size() - 1; c++)
	{
		if (s[c] == s[c + 1])
		{
			int i = 0;//0的时候肯定相等，第一次肯定满足
			while (s[c - i] == s[c + 1 + i] && (c - i) >= 0 && (c + i + 1) < s.size())
			{
				i++;
			}
			i = i - 1;
			if (2 * i + 2 > maxLen)//更新字符串
			{
				maxStr = s.substr(c - i, 2 * i + 2);
				maxLen = maxStr.size();
			}
		}

	}
	return maxStr;
}

//6.字符串Z行排列取出
string convert(string s, int numRows) {
	//把字符s按没行存储
	if (numRows == 1)
		return s;
	vector<string> res(numRows < s.size() ? numRows : s.size());
	bool goDown = false;
	int row = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (row == numRows - 1 || row == 0)
		{
			goDown = !goDown;
		}
		res[row] += s[i];
		goDown ? row++ : row--;
	}
	string mystr = "";
	for (string m : res)
	{
		mystr += m;
	}
	return mystr;
}

//.*字符匹配
//bool isMatch(string s, string p) {
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] != p[i])
//		{
//
//		}
//	}
//}

//11.接雨最多的容器
int maxArea(vector<int>& height) {
	//1、暴力法找出所有的柱子，接水量,超时
	/*int maxWater = 0;
	for (int i = 0; i < height.size()-1; i++)
	{
	for (int j = i+1; j < height.size(); j++)
	{

	int tmp = (j - i)*min(height[i], height[j]);
	maxWater = maxWater >  tmp  ?maxWater : tmp;
	}
	}
	return maxWater;*/

	//2.双指针法 
	int left = 0;
	int right = height.size() - 1;
	int maxWater = 0;
	while (left < right)
	{
		int tmp = (right - left)*min(height[right], height[left]);
		cout << tmp << endl;
		maxWater = maxWater > tmp ? maxWater : tmp;
		if (height[right]>height[left])
		{
			left++;
		}
		else
		{
			right--;
		}

	}
	return maxWater;
}

//8.atoi字符转换为数字
int myAtoi(string s) {
	int top = pow(2, 31) - 1;
	int bot = 0 - pow(2, 31);
	long long  num = 0;
	int num_loc = 0;
	int num_len = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num_loc = i;
			break;
		}
	}
	for (int i = num_loc; i < s.size(); i++)
	{

		if (s[i] < '0' || s[i] > '9')
		{
			cout << i << endl;
			num_len = i - num_loc;
			break;
		}
		if (i == s.size() - 1)
		{
			num_len = i - num_loc + 1;
		}
	}
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && i < num_loc)//空格跳过
		{
			continue;
		}
		if ((s[i] < '0' || s[i] > '9') && i < num_loc - 1)//前面有字符直接为0
		{
			return 0;
		}
		if (s[i] != '+' && s[i] != '-' && i == num_loc - 1)//前面有字符直接为0
		{
			return 0;
		}
		if (s[i] == '+' && i == num_loc - 1)
		{
			flag = 1;
		}
		if (s[i] == '-' && i == num_loc - 1)
		{
			flag = -1;
		}
	}

	for (int i = num_loc; i < num_loc + num_len; i++)
	{
		if ((s[i] - '0') * pow(10, num_loc + num_len - i - 1) > top)
		{
			if (flag == 1)
				return top;
			else
				return bot;
		}
		num += (s[i] - '0') * pow(10, num_loc + num_len - i - 1);

	}
	if (num * flag < bot)
		return bot;
	if (num * flag > top)
	{
		return top;
	}
	return num * flag;
}

//15.三数之和为0,选取1个数，转化为两数之和，然后用双指针
vector<vector<int>> threeSum(vector<int>& nums)
{
	int size = nums.size();
	if (size < 3)   return{};          // 特判
	vector<vector<int> >res;            // 保存结果（所有不重复的三元组）
	std::sort(nums.begin(), nums.end());// 排序（默认递增）
	for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
	{
		if (nums[i] > 0)    return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
										// 去重：如果此数已经选取过，跳过
		if (i > 0 && nums[i] == nums[i - 1])  continue;
		// 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			if (nums[left] + nums[right] > -nums[i])
				right--;    // 两数之和太大，右指针左移
			else if (nums[left] + nums[right] < -nums[i])
				left++;     // 两数之和太小，左指针右移
			else
			{
				cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;
				// 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
				res.push_back(vector<int>{nums[i], nums[left], nums[right]});
				left++;
				right--;
				// 去重：第二个数和第三个数也不重复选取
				// 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
				while (left < right && nums[left] == nums[left - 1])  left++;
				while (left < right && nums[right] == nums[right + 1])    right--;
			}
		}
	}
	return res;
}

//12. 整数转罗马数字,找规律
string intToRoman(int num) {
	/*
	int RomanNum[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	vector<string> RomanChar = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	string mystr;
	for (int i = 0; i < size(RomanNum); i++)
	{
	if (num / RomanNum[i] < 1 )//没有
	{
	continue;
	}
	while (num / RomanNum[i]>=1)
	{
	num = num - RomanNum[i];
	mystr += RomanChar[i];
	}
	if (num == 0)
	{
	break;
	}
	}
	return mystr;*/
	//改用map
	map<int, string> RomanNum = { { 1000,"M" },{ 900,"CM" },{ 500,"D" },{ 400,"CD" },{ 100,"C" },{ 90,"XC" },{ 50,"L" },{ 40,"XL" },{ 10,"X" },{ 9,"IX" },{ 5,"V" },{ 4,"IV" },{ 1,"I" } };
	string mystr;
	for (auto it = RomanNum.end(); it != RomanNum.begin();)
	{

		if (num / (--it)->first < 1)//没有
		{
			continue;
		}
		while (num / it->first >= 1)
		{
			num = num - it->first;
			mystr += it->second;
		}
		if (num == 0)
		{
			break;
		}
	}
	return mystr;
}

//16. 最接近的三数之和
int threeSumClosest(vector<int>& nums, int target) {
	//选取一个数，双指针
	int closeNum = INT_MAX;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		int fixNum = nums[i];
		int left = i + 1;
		int right = nums.size() - 1;
		while (left<right)
		{
			int tmp = nums[left] + nums[right] + fixNum - target;
			//cout << tmp << endl;
			closeNum = abs(tmp)<abs(closeNum) ? tmp : closeNum;
			if (tmp > 0)
			{
				right--;
			}
			else if (tmp < 0)
			{
				left++;
			}
			else
			{
				return target;
			}

		}
	}
	return closeNum + target;
}


//18.四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> sum;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i>0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		for (int j = i + 1; j < nums.size(); j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[j] + nums[left] + nums[right] > target)
				{
					right--;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
				{
					left++;
				}
				else
				{
					sum.push_back(vector<int>{nums[i] + nums[j], nums[left], nums[right]});
					right--;
					left++;
					while (left<right && nums[left] == nums[left - 1])
						left++;
					while (left < right && nums[right] == nums[right + 1])
						right--;
				}
			}
		}
	}
	return sum;
}

//22.括号生成
vector<string> generateParenthesis(int n) {
	vector<string> result;
	string current;
	getAllParentheses(4, result, current);
}
//验证括号是否匹配
bool parenthesesValid(const string str)
{
	int sum = 0;
	for each (char s in str)
	{
		if (s == ')')
			sum--;
		else
			sum++;
		if (sum<0)
			return false;
	}
	return sum == 0;
}
//生成6个括号的所有可能的组合
void getAllParentheses(int n, vector<string> &result, string &current)
{
	
	static int i = 0;
	if (n == current.size()) {
		if (parenthesesValid(current)) {
			result.push_back(current);
			cout << current << endl;
		}
		return;
	}
	current += '(';
	getAllParentheses(n, result, current);
	current.pop_back();
	current += ')';
	getAllParentheses(n, result, current);
	current.pop_back();
}

void getAllAlphabet(int index, string &digits, vector<string> &result, string &current)
{
	static int t = 0;
	vector<string> alphabet = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	if (current.size() == digits.size()) {
		result.push_back(current);
		cout << current << endl;
		return;
	}

	for (int j = 0; j < alphabet[digits[index] - '2'].size(); j++)
	{
		getAllAlphabet(index+1, digits, result, current + alphabet[digits[index] - '2'][j]);
	}

}


//17.电话号码的字母组合
vector<string> letterCombinations(string digits) {
	vector<string> result;
	string current;
	getAllAlphabet(0, digits, result, current);
	return result;
}