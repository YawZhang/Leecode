# Strings

## 344 反转字符串

双指针法，各指头尾，同时交换收缩，中间剩余的单独元素不用管





## 541 反转字符串ii

**题目：**

给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由小写英文组成
- `1 <= k <= 104`

**思路：**

- 先判断剩余子串是否小于k，若符合条件，将剩余字符串开头到字符串末尾全部翻转
- 否则，直接翻转剩余子串的前k个，字符串指针每次+2k
  - 当剩余字符串大于2k，i+2k还在范围内，继续一次循环
  - 当剩余字符串小于2k，大于k，循环过后，指针溢出。直接break

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size() == 1) return s;
        int k2 = 2*k;
        int slen = s.size();
        int i = 0;
        while (i< s.size()) {
            int i0 = i;

            if ((slen -i) < k) {
                int j = slen - 1;//双指针
                while(i<(i0 + (s.size() - i0)/2)) {
                    swap(s[i++], s[j--]);
                }
            }
            else {
                int j = k+i0-1;
                while ( i < (i0+k/2)) {
                    swap(s[i++], s[j--]);
                }
                if ((slen -i0) < k2 && (slen-i0)>=k) {
                    i = slen; 

                }
            }
            i = i0 + k2;
        }
        return s;
    }
};
```





## 剑指Offer05 替换空格

**题目：**

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

**提示：**

- `0 <= s 的长度 <= 10000`

**思路：**

- 创建新扩容后的字符串，从前向后逐一替换

- 双指针法，先扩容，再从后向前逐一替换
  - 从后向前不用重复移动后面n个字符串
  - 从前向后，时间复杂度$O(n^2)$

解法：双指针法

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;//统计空格数，确定需要扩容的大小
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int oldSize = s.size();
        s.resize(oldSize + count*2);
        //一个指针指向扩容后的末尾，一个指针指向未扩容前的末尾
        for (int i = s.size()-1,  j = oldSize -1; j >=0; i--, j-- ) {
            if (s[j] == ' '){
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
            else {
                s[i] = s[j];
            }
        }
        return s;
    }
};
```



## 151 反转字符串中的单词

**题目：**

给你一个字符串 `s` ，请你反转字符串中 **单词** 的顺序。

**单词** 是由非空格字符组成的字符串。`s` 中使用至少一个空格将字符串中的 **单词** 分隔开。

返回 **单词** 顺序颠倒且 **单词** 之间用单个空格连接的结果字符串。

**注意：**输入字符串 `s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

**提示：**

- `1 <= s.length <= 104`
- `s` 包含英文大小写字母、数字和空格 `' '`
- `s` 中 **至少存在一个** 单词

**思路：**

- 双指针法

//版本1

- 定义新的字符串，直接查找单词
- 从而往前找单词，找到即插入，并在单词后插入空格
- 最后查找完后删除最后一个空格，由于删除最后一个空格，所以erase复杂度为O（1）

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string t;

        for (int j = s.size()-1; j>=0; j--) {
            if (s[j] == ' '){
                continue;//尾指针不能是空格
            } 
            int i = j;
            //是找到区间为(i, j]的单词
            while ( i>-1 && s[i] != ' ') {
                i--;
            };//头指针得是空格，但最多遍历到字符串头，此时i=-1
            

            if (i<-1) break;
            // 将每个单词插入新字符串中
            int k = i;
            for (i =k+1 ; i<=j; i++){
                t.push_back(s[i]);
            }
            j = k+1;
            t.push_back(' ');//插入一个单词就茶一个空格
        }
        t.erase(t.size()-1);//最后删除最后一个多余空格
        return t;
    }
};
```

//版本二

- 先去冗余空格
  - 利用快慢指针，找到字符串中的单词
  - 快指针的值替换到慢指针，只有除了第一个单词前不加空格，其他均加空格
  - resize字符串，大小等于慢指针的大小

- 再从后向前查找子串，插入到新字符串中

```
class Solution {
public:
    // 反转子串
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i<j; i++, j--) {
            swap(s[i] , s[j]);
        }
    }

    // 去除冗余空格
    void removeExtraSpace(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' '){
                if (slow!=0 ) s[slow++] = ' ';//如果slow不在字符串开头，就加个空格
                while(fast < s.size() && (s[fast] != ' ')) {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    //插入新字串
    void insertSubString(string& s, string& t, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
                t.push_back(s[i]);
            }
        if (start > -1)  t.push_back(' ');

    }


    string reverseWords(string s) {
        string t;
        //去重冗余空格
        removeExtraSpace(s);
        
        //反转子串
        for (int j = s.size()-1; j>=0; j--) {
            if (s[j] == ' ') continue;
            int i = j;
            while (i>=0 && s[i] != ' ') {
                i--;
            }//此时(i, j]为子串
            
            insertSubString(s, t, i , j);

            j = i;

        }
        return t;
    }
};
```

// 版本三

- 去冗余空格
  - 利用快慢指针，找到字符串中的单词
  - 快指针的值替换到慢指针，只有除了第一个单词前不加空格，其他均加空格
  - resize字符串，大小等于慢指针的大小

- 反转整个字符串
  - 利用双指针，头指针和尾指针，将数组翻转
  - 遍历条件是头指针小于尾指针

- 反转每个子串
  - 头指针为每个单词的开头，尾指针为字符串size-1


```cpp
class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};
```



## 剑指Offer58-II 左旋字符串

**题目：**

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"

**提示：**

- `1 <= k < s.length <= 10000`

**思路：**

- 先局部后整体翻转
- 先整体后局部翻转

解法一：先局部后整体翻转

- 前k个字符翻转，后n-k个字符翻转

- 整体n个字符翻转

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        
        reverse(s.begin() s.begin() + n);
        reverse( s.begin() + n, s.end());
        reverse(s.begin(), s.begin() + n);

        return s;
    }
};
```

解法二：先整体后局部翻转

- 整体n个字符翻转
- 前n-k个字符翻转，后k个字符翻转

```
class Solution {
public:
	void reverse(string& s, int start, int end) {
        int j = end;
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.size()-1);//整体翻转
        //局部翻转
        reverse(s, 0, s.size()-n-1);
        reverse(s, s.size()-n, s.size() -1);
        
        return s;
    }
};
```



## 28 找出字符串中第一个匹配项的下表

**题目：**

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

**提示：**

- `1 <= haystack.length, needle.length <= 104`
- `haystack` 和 `needle` 仅由小写英文字符组成

**思路：**

- 暴力迭代法，匹配每一个模式串，时间复杂度$O(n^2)$
- KMP算法

解法一：暴力迭代法

- 每次一一比对文本串字符和模式串元素
  - 若两个元素相同，两个指针均+1
  - 若两个元素不同，文本串指针+1，模式串指针从头重新开始

```cpp
class Solution {
public:
    int strStr(string h, string n) {
        if (h.size() < n.size()) return -1;//判断边界条件

		for (int i = 0; i < h.size() - n.size()+1; i++) {//此时巧妙的将h.size() < s.size()的情况算进去了
            int k = i;
            int j = 0;
            while( j < n.size()) {
                if ( h[k] == n[j]) {
                    j++;
                	k++;
                }
                    
                else break;
            }
            if ( j == n.size() ) return i;
        }
        return -1;
    }
};
```



解法二：KMP

- 由于暴力解法每次匹配不成功时，都将模式串指针从头开始，造成重复匹配的问题，因此KPM算法就是减少重复匹配，从上一个已匹配好的位置重新匹配
- 首先为了引入前缀表的原因是
  - 当模式串前缀和后缀相等时，**下次匹配就只需要从前缀的后面重新匹配就可以**
  - **前缀表中就是为了存放模式串的最长相等前后缀长度**
- 构造前缀表的三个步骤
  - **初始化**，确定前缀表规则，是统计长相等前后缀长度，还是统计长相等前后缀长度-1
  - **当前后缀不相同时**，更新j为上一个最长相等前缀的后面位置，即`j=next[j+1]` or `j=next[j]` 
  - **当前后缀相同时**，j指针+1
- 开始进行串匹配
  - 首先需要对边界进行控制,即模式串长度必须小于等于文本串，<这是个好习惯，虽然有得题不用>
  - 开始遍历文本串
    - **元素不匹配**，将模式串指针从前缀表中找下一个开始匹配的位置
    - **元素匹配**，模式串和文本串指针都+1
    - **元素全部匹配**，即指针大小与模式串长度相同，返回文本串起始位置

```cpp
// KMP算法，时间复杂度O(n+m)
    void getNext(int* next, string s) {
        // 初始化，目的是第一个字符没有前缀后缀
        int j = -1;
        next[0] = j;//初始化next数组初始值为-1，即所有最长相等前后子串长度-1；

        for (int i = 1; i < s.size(); i++) {
            // 当前后缀末尾不相同时，
            while ( j > -1 && s[i] != s[j+1]) {
                j = next[j];//j回退找前一个最长相等前后子串长度
            }

            // 如果前后缀末尾相同，i和j同时++
            if (s[i] == s[j+1]) {
                j++;//此时在这里对i++,因为执行完这个预计，会进入下个循环，i++
            }
            next[i] = j; //将j（前缀长度）赋给next[i]
        }
    }
    
    
    int strStr(string h, string n) {
        //先处理边界条件
        if (h.size() < n.size()) return -1;

        //初始化next数组
        int next[n.size()];
        getNext(next, n);
        int i = 0;
        while(i != n.size()) {
            cout << next[i] << " ";
            i++;
        }
        cout << endl;

        // 开始从文本串中查找模式串
        int j = -1;
        for (int i = 0; i < h.size(); i++) {
            //如果当前字符与模式串字符不匹配，找前缀表的上一个位置
            while( j > -1 && h[i] != n[j+1]) {
                j = next[j];
            }

            if (h[i] == n[j+1]) {
                j++;
            }

            if (j == (n.size()-1)) {
                return i - n.size()+1;
                // 这个+1是因为 
                // - i此时指向的文本串中匹配到的模式串的最后一个字符的位置
                // - 而头指针从0开始，因此需要+1
            }
        }
        return -1;
    }

```



## 459 重复的子字符串

**题目：**
给定一个非空的字符串 `s` ，检查是否可以通过由它的一个子串重复多次构成。

**提示：**

- `1 <= s.length <= 104`
- `s` 由小写英文字母组成

**思路：**

- 暴力匹配（时间复杂度$O(n^2)$
- 移动匹配
- KMP算法

解法一：暴力匹配

- 首先找子串长度，即i=1开始，毕竟至少有个子串嘛，但遍历截止条件为n/2+1,因为长度大于n/2的子串必然不能重复

- 其次枚举每个元素，有几点需要注意

  - 1.子串长度一定要被字符串长度整除
  - 2.如果是重复子串，那必有移动每间隔i个长度，所有字符都相同，即s[j] = s[j-i]

  ```cpp
  class Solution {
  public:
      bool repeatedSubstringPattern(string s) {
          if (s.size() == 0) return false;
  
          for (int i = 1; i <(s.size()/2)+1; i++) {
              if ((s.size() % i) == 0 ) {
                  bool match = true;
                  for (int j = i; j < s.size(); j++) {
                      if (s[j] != s[j-i]) {
                          match =  false;
                          break;
                      }
                  }
                  if (match) return true;
              }
          }
          return false;
      }
  };
  ```

解法二：移动匹配

- 要点是若是重复字符串，那么再重复加一遍字符串，即`t = s+s`，则`t`中一定能找到一个与`s`相匹配的子串
- 需要注意的是需要将新串`t`去掉首尾（保证至少重复子串长度为1的时候也成立），这样前后的`s`就不会记录到匹配子串中去
- 当已有的算法的时候需要考虑到算法复杂度，`t.find`和`t.contain`的复杂度都是$O(m+n)$

```cpp
    // 移动匹配
    bool repeatedSubstringPattern(string s) {
        string a(s+s);
        cout <<  a << endl;
        a.erase(a.begin());
        a.erase(a.end()-1);
        if (a.find(s) != std::string::npos) return true;
        return false;
    }
```

**解法三：KMP算法**

- **如果是重复字符串的话，最长相等后缀所不包含的第一个子串就是重复子串**
- 算法随想录的推到思想是根据前缀和后缀逐元素相同
  - 即`f(0)=b(0) ··· f(k) = b(k)`，其中k代表重复子串长度，而按相对位置又可知`f(0)=f(0+k) ··· f(k) = b(k+k)`
  - 实际上这和暴力匹配的思想一样，**间隔为k的所有元素均相同，这是是重复子串的必要且充分条件**
- 基于上述理论，可以按照下面两个步骤来完成
  - 1.构造前缀表，此时前缀表最后一个元素的值与字符串作差就是第一个子串的长度
  - 2.只要判断这个**第一个子串长度是否能被字符串长度整除**，就能判断是否为重复子串

```cpp
  void getNext(int* next, string s ) {
        //初始化
        int j = 0;
        next[0] = j;

        //开始查找前缀表
        for (int i = 1; i < s.size(); i++) {
            //当前后缀不相同时，指针回退
            while ( j>0 && s[i] != s[j]) {
                j = next[j-1];
            }
            //当前后缀相同时，指针前进
            if ( s[i] == s[j]) {
                j++;
            }
            // 给前缀表幅值
            next[i] = j;

        }
    }


    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) return false;//边界条件控制

        int next[s.size()];
        getNext(next, s);//构建前缀表
        int nlen = next[s.size()-1];
        int sublen = s.size() - nlen;
        if ((nlen != 0) && (s.size() % sublen == 0)) return true;
        return false;
    }
```

