# 剑指 Offer II JZ087-复原 IP

## 题目描述

<!-- description:start -->

<p>给定一个只包含数字的字符串 <code>s</code> ，用以表示一个 IP 地址，返回所有可能从&nbsp;<code>s</code> 获得的 <strong>有效 IP 地址 </strong>。你可以按任何顺序返回答案。</p>

<p><strong>有效 IP 地址</strong> 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 <code>0</code>），整数之间用 <code>&#39;.&#39;</code> 分隔。</p>

<p>例如：&quot;0.1.2.201&quot; 和 &quot;192.168.1.1&quot; 是 <strong>有效</strong> IP 地址，但是 &quot;0.011.255.245&quot;、&quot;192.168.1.312&quot; 和 &quot;192.168@1.1&quot; 是 <strong>无效</strong> IP 地址。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;25525511135&quot;
<strong>输出：</strong>[&quot;255.255.11.135&quot;,&quot;255.255.111.35&quot;]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;0000&quot;
<strong>输出：</strong>[&quot;0.0.0.0&quot;]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;1111&quot;
<strong>输出：</strong>[&quot;1.1.1.1&quot;]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;010010&quot;
<strong>输出：</strong>[&quot;0.10.0.10&quot;,&quot;0.100.1.0&quot;]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>s = &quot;10203040&quot;
<strong>输出：</strong>[&quot;10.20.30.40&quot;,&quot;102.0.30.40&quot;,&quot;10.203.0.40&quot;]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code> 仅由数字组成</li>
</ul>

<p>&nbsp;</p>
<p><meta charset="UTF-8" />注意：本题与主站 93&nbsp;题相同：<a href="https://leetcode.cn/problems/restore-ip-addresses/">https://leetcode.cn/problems/restore-ip-addresses/</a></p>

<!-- description:end -->

## Code

1. 使用回溯算法，IP地址由四个整数组成，需要分成四段。
2. 对于每一段，长度可以是 1、2 或 3，但需要检查是否合法：
   - 不能有前导零（除非就是 "0" 本身）。
   - 数值必须在 0-255 之间。
3. 回溯过程中，记录当前分段数和当前位置，当分成四段且用完所有字符时，记录结果。
4. 剪枝优化：剩余字符数必须在剩余段数的合理范围内。
5. 时间复杂度 $O(3^4)$，因为每段有最多 3 种长度选择。

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& path, vector<string>& result) {
        if (path.size() == 4) {
            if (start == s.size()) {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }
        
        int remaining = s.size() - start;
        int segmentsLeft = 4 - path.size();
        if (remaining < segmentsLeft || remaining > segmentsLeft * 3) {
            return;
        }
        
        for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
            string segment = s.substr(start, len);
            if (isValid(segment)) {
                path.push_back(segment);
                backtrack(s, start + len, path, result);
                path.pop_back();
            }
        }
    }
    
    bool isValid(const string& segment) {
        if (segment.empty() || segment.size() > 3) return false;
        if (segment[0] == '0' && segment.size() > 1) return false;
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }
};
```
<p><meta charset="UTF-8" />注意：本题与主站 93&nbsp;题相同：<a href="https://leetcode.cn/problems/restore-ip-addresses/">https://leetcode.cn/problems/restore-ip-addresses/</a>&nbsp;</p>

<!-- description:end -->
