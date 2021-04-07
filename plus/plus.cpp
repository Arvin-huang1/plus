#include "plus.h"

int my_plus(int a, int b)
{
	return a + b;
}

//find����,��������ָ���������������
template<class Iterator, class T>
Iterator find(Iterator First, Iterator Last, const T &val)
{
	while (*First != val && First != Last)
	{
		First++;
	}
	return First;
}

//�Ӵ�����
int lengthOfLongestSubstring(string s) {
	int maxLength = 0;
	//˳����ң�һ���ҵ�ÿ������ظ��Ӵ����ù�ϣ���ϱ���
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

//4.��λ���ϲ�
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

//5.�����Ӵ�
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
	//�������ҵ����е��Ӵ��ж��Ƿ��ǻ����ַ�����
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

	//������չ���������Ŀ�ʼ���ң����ǻ���next
	if (s.size() <= 1)
	{
		return s;
	}
	int maxLen = 0;
	string  maxStr = "";
	//������
	for (int c = 0; c < s.size(); c++)
	{
		int i = 0;//0��ʱ��϶���ȣ���һ�ο϶�����
		while ((c - i) >= 0 && (c + i) <s.size() && s[c - i] == s[c + i])
		{
			i++;
		}
		i = i - 1;
		if (2 * i + 1>maxLen)//�����ַ���
		{
			maxStr = s.substr(c - i, 2 * i + 1);
			maxLen = maxStr.size();
		}
	}

	//ż����
	for (int c = 0; c < s.size() - 1; c++)
	{
		if (s[c] == s[c + 1])
		{
			int i = 0;//0��ʱ��϶���ȣ���һ�ο϶�����
			while (s[c - i] == s[c + 1 + i] && (c - i) >= 0 && (c + i + 1) < s.size())
			{
				i++;
			}
			i = i - 1;
			if (2 * i + 2 > maxLen)//�����ַ���
			{
				maxStr = s.substr(c - i, 2 * i + 2);
				maxLen = maxStr.size();
			}
		}

	}
	return maxStr;
}

//6.�ַ���Z������ȡ��
string convert(string s, int numRows) {
	//���ַ�s��û�д洢
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

//.*�ַ�ƥ��
//bool isMatch(string s, string p) {
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] != p[i])
//		{
//
//		}
//	}
//}

//11.������������
int maxArea(vector<int>& height) {
	//1���������ҳ����е����ӣ���ˮ��,��ʱ
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

	//2.˫ָ�뷨 
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

//8.atoi�ַ�ת��Ϊ����
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
		if (s[i] == ' ' && i < num_loc)//�ո�����
		{
			continue;
		}
		if ((s[i] < '0' || s[i] > '9') && i < num_loc - 1)//ǰ�����ַ�ֱ��Ϊ0
		{
			return 0;
		}
		if (s[i] != '+' && s[i] != '-' && i == num_loc - 1)//ǰ�����ַ�ֱ��Ϊ0
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

//15.����֮��Ϊ0,ѡȡ1������ת��Ϊ����֮�ͣ�Ȼ����˫ָ��
vector<vector<int>> threeSum(vector<int>& nums)
{
	int size = nums.size();
	if (size < 3)   return{};          // ����
	vector<vector<int> >res;            // �����������в��ظ�����Ԫ�飩
	std::sort(nums.begin(), nums.end());// ����Ĭ�ϵ�����
	for (int i = 0; i < size; i++)      // �̶���һ������ת��Ϊ������֮��
	{
		if (nums[i] > 0)    return res; // ��һ�������� 0�����涼�ǵ������������������Ϊ����
										// ȥ�أ���������Ѿ�ѡȡ��������
		if (i > 0 && nums[i] == nums[i - 1])  continue;
		// ˫ָ����nums[i]�����������Ѱ�Һ�Ϊ0-nums[i]������������
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			if (nums[left] + nums[right] > -nums[i])
				right--;    // ����֮��̫����ָ������
			else if (nums[left] + nums[right] < -nums[i])
				left++;     // ����֮��̫С����ָ������
			else
			{
				cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;
				// �ҵ�һ����Ϊ�����Ԫ�飬��ӵ�����У�����ָ������������Ѱ��
				res.push_back(vector<int>{nums[i], nums[left], nums[right]});
				left++;
				right--;
				// ȥ�أ��ڶ������͵�������Ҳ���ظ�ѡȡ
				// ���磺[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
				while (left < right && nums[left] == nums[left - 1])  left++;
				while (left < right && nums[right] == nums[right + 1])    right--;
			}
		}
	}
	return res;
}

//12. ����ת��������,�ҹ���
string intToRoman(int num) {
	/*
	int RomanNum[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	vector<string> RomanChar = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	string mystr;
	for (int i = 0; i < size(RomanNum); i++)
	{
	if (num / RomanNum[i] < 1 )//û��
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
	//����map
	map<int, string> RomanNum = { { 1000,"M" },{ 900,"CM" },{ 500,"D" },{ 400,"CD" },{ 100,"C" },{ 90,"XC" },{ 50,"L" },{ 40,"XL" },{ 10,"X" },{ 9,"IX" },{ 5,"V" },{ 4,"IV" },{ 1,"I" } };
	string mystr;
	for (auto it = RomanNum.end(); it != RomanNum.begin();)
	{

		if (num / (--it)->first < 1)//û��
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

//16. ��ӽ�������֮��
int threeSumClosest(vector<int>& nums, int target) {
	//ѡȡһ������˫ָ��
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


//18.����֮��
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

//22.��������
vector<string> generateParenthesis(int n) {
	vector<string> result;
	string current;
	getAllParentheses(4, result, current);
}
//��֤�����Ƿ�ƥ��
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
//����6�����ŵ����п��ܵ����
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


//17.�绰�������ĸ���
vector<string> letterCombinations(string digits) {
	vector<string> result;
	string current;
	getAllAlphabet(0, digits, result, current);
	return result;
}