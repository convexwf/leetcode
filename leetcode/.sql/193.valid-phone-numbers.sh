#
# @lc app=leetcode id=193 lang=bash
#
# [193] Valid Phone Numbers
#
# https://leetcode.com/problems/valid-phone-numbers/description/
#
# shell
# Easy (26.04%)
# Likes:    322
# Dislikes: 811
# Total Accepted:    62.9K
# Total Submissions: 241.5K
# Testcase Example:  '0'
#
# Given a text file file.txt that contains a list of phone numbers (one per
# line), write a one-liner bash script to print all valid phone numbers.
#
# You may assume that a valid phone number must appear in one of the following
# two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
#
# You may also assume each line in the text file must not contain leading or
# trailing white spaces.
#
# Example:
#
# Assume that file.txt has the following content:
#
#
# 987-123-4567
# 123 456 7890
# (123) 456-7890
#
#
# Your script should output the following valid phone numbers:
#
#
# 987-123-4567
# (123) 456-7890
#
#
#

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
# @lc code=end

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
# @lc code=end

# @lc code=start
# Read from the file file.txt and output all valid phone numbers to stdout.
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
# @lc code=end
