# LeetCode-Practice

My LeetCode solutions, synced automatically from LeetCode to this repository.

## Goal

Work through the [NeetCode 150](https://neetcode.io/practice/practice/neetcode150) roadmap:

- **One new problem per day**, following the NeetCode 150 order.
- **Plus the reviews LeetSRS says are due that day**, so older problems stay fresh through spaced repetition.

## Tools

Both browser extensions are included as git submodules in [`extensions/`](extensions):

| Extension | What it does |
| --- | --- |
| [LeetSync](https://github.com/LeetSync/LeetSync) (`extensions/leetsync`) | Pushes every accepted LeetCode submission to this repo (one folder per problem, with its `README.md`). |
| [LeetSRS](https://github.com/mattcdrake/leetsrs) (`extensions/leetsrs`) | Spaced repetition for LeetCode: I rate how well I remembered each problem, and it schedules the next review. It also tracks progress on the NeetCode 150 roadmap. |

## Daily workflow

1. **Solve the new problem.** Pick the next unsolved problem from NeetCode 150.
2. **Check the extension.** Open LeetSRS to see which problems are due for review today.
3. **Solve on LeetCode.** Submit the new problem and the due reviews on LeetCode. LeetSync commits each accepted solution here.
4. **Resubmit on NeetCode.** Submit the same solution on NeetCode so its NeetCode 150 progress tracker stays in sync.

## Cloning

```sh
git clone --recurse-submodules https://github.com/petrubraha/leetcode-practice.git
# or, in an existing clone:
git submodule update --init
```
