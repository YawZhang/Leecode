# 哈希

## 基本概念

### 1 哈希函数



![image-20230320130149264](hash.assets/image-20230320130149264.png)

### 2 哈希碰撞

不同key值映射到相同的哈希表的索引中，**这一现象叫做哈希碰撞。**

![image-20230320130357589](hash.assets/image-20230320130357589.png)

==解决方法：==

- 拉链法

  - 冲突元素存储在链表中

    <img src="hash.assets/image-20230320130503824.png" alt="image-20230320130503824" style="zoom: 50%;" />

- 线性试探法

  - tablesize >> datasize
  - 冲突元素向下寻找空位

  <img src="hash.assets/image-20230320130545431.png" alt="image-20230320130545431" style="zoom:50%;" />

### 3 STL hashTable实现方式

| 集合               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::multiset      | 红黑树   | 有序     | 是               | 否           | O(logn)  | O(logn)  |
| std::set           | 红黑树   | 有序     | 否               | 否           | O(log n) | O(log n) |
| std::unordered_set | 哈希表   | 无序     | 否               | 否           | **O(1)** | **O(1)** |



`std::unordered_set`底层实现为哈希表，``std::set` 和`std::multiset` 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以只能删除和增加。

| 映射               | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------------- | ------------ | -------- | -------- |
| std::map           | 红黑树   | key有序  | key不可重复      | key不可修改  | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | key有序  | key可重复        | key不可修改  | O(log n) | O(log n) |
| std::unordered_map | 哈希表   | key无序  | key不可重复      | key不可修改  | **O(1)** | **O(1)** |

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。



### 4 **总结：**

总结一下，**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法**。

但是哈希法也是**牺牲了空间换取了时间**，因为我们要使用额外的数组，set或者是map来存放数据，才能实现快速的查找。

如果在做面试题目的时候遇到需要判断一个元素是否出现过的场景也应该第一时间想到哈希法！



## 242 有效的字母异位词

**题目：**

给定两个字符串 `*s*` 和 `*t*` ，编写一个函数来判断 `*t*` 是否是 `*s*` 的字母异位词。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同，则称`*s*` 和 `*t*` 互为字母异位词。

**提示：**

- `1 <= s.length, t.length <= 5 * 104`
- `s` 和 `t` 仅包含小写字母

**思路：**

- 暴力双循环，记录字符串中字符出现次数
- 哈希表，记录字符串字符出现次数

> 一般要查询某元素是否在集合中时，第一时间采用哈希法



解法：哈希表

- 集合长度较短，先采取数组方式构建哈希表
- 将所有字符映射到哈希表中，即`char - 'a' = i ` 

- 统计两个字符串字符出现次数
  - 为节省空空间，只需前一个字符串字符数++，后一个字符串字符数--

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};//用数组初始化哈希表
        for (int i = 0; i < s.size(); i++) {
            //当两个字符做减法，编辑器自动将字符转换成对应的ASCII码
            hash[s[i] - 'a']++;//统计字符s[i]出现的次数，若出现hash[s[i]]++
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;//统计字符t[i]在t中出现的次数，若出现，hash--
        }

        // 当此时hash表中所有元素为0时，证明两个字符串为字母异位词
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false;
        }

        return true;

    }
};

```



## 349 两个数组的交集

**题目：**

给定两个数组 `nums1` 和 `nums2` ，返回 *它们的交集* 。输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 。

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

**思路：**

- 数组作为哈希表
- `set`作为哈希表

解法一：数组作为哈希表

- 首先要初始化数组的哈希表，哈希表长度为数组内元素的最大值
- 将数组`nums1`映射到哈希表
- 遍历`nums2`中元素，找对应的哈希表，若哈希表的值不为0，则表明该值为交集元素，将该值插入到结果vector中
  - 可以用**unordered_set**作为结果类型，==自动去重交集元素==

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& s, vector<int>& t) {
        unordered_set<int> result_set;//结果保存集合
        int  num_hash[1001] = {0};//数组初始化哈希表全为0，哈希表长度对应输入数组的元素值的最大返回

        for (int i = 0; i < s.size(); i++) {
            num_hash[s[i]] = 1;//将第一个数组映射到哈希表中，出现则哈希表中值为1
        }

        for (int i = 0; i < t.size(); i++) {
            if (num_hash[t[i]] == 1) {//查找对应数组2在哈希表中的对应值，若值==1，意味此值是与数组1的交集元素
                result_set.insert(t[i]);
            }
        }
        return vector<int> (result_set.begin(), result_set.end());//将unordered_set结果类型转换成vector输出

    }
};
```

解法二：set构建哈希表

- set作为哈希表
  - 优点：查找效率O(1)，增删效率O(1)
  - 缺点：空间复杂度高
- 其他过程与数组类似

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& s, vector<int>& t) {
        unordered_set<int> result_set;
        unordered_set<int> num_set(s.begin(), s.end());//将数组1映射到哈希表中中

        for (int i = 0; i < t.size(); i++) {
            if (num_set.find(t[i]) != num_set.end()) {//在哈希表中查找数组2元素，若存在，则该值为交集元素，放入结果集合中
                result_set.insert(t[i]);
            }
        }
        return vector<int> (result_set.begin(), result_set.end());//将unordered_set结果类型转换成vector输出

    }
};
```

