# Answer summary for interview

## Answer structure

1. Restate the problem to confirm understanding.
2. Explain the key idea or insight needed to solve the problem.
3. Describe the algorithm or approach step-by-step.
4. Analyze time and space complexity.
5. Provide an example to illustrate the solution.

## Answer example

Let me restate the problem first. We need to find a contiguous subarray that gives the largest product. The array may contain positive, negative, and zero values.

The key idea is that the product can flip its sign when multiplied by a negative number. So we need to keep track of both the maximum and minimum product up to each index.

For each number nums[i], we update: (we can write the following equations)

```ini
maxProd = max(nums[i], nums[i] * prevMax, nums[i] * prevMin)
minProd = min(nums[i], nums[i] * prevMax, nums[i] * prevMin)
```

Then we keep a global result that stores the maximum maxProd so far.

This takes linear time O(n) and constant space O(1).

For example, given [2,3,-2,4], the answer is 6.”

(Pause)
“Does that make sense?”
