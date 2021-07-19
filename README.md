# Welcome to Splitwise Readme!

Generally, splitwise is a free app that allows consumers to split expenses with friends. For splitting bills with friends and family, splitwise can track each expense and the amount that each person in the group owes.

## About the Project:

This is a ```C++``` program which is used to minimize the cash flow (or the number of transactions) among a set of friends who have borrowed money from each other. 

---

# Getting Started

### Approach:

The idea is to use **Greedy Algorithm** where at every step, such that the program settle all amounts of one person and recur for remaining n-1 persons. 

### How to proceed?

Suppose there are few friends. They have borrowed money from each other. So there will be some cash flow on the network. Our task is to minimize the cash flow in the network. Suppose there are three friends P1, P2, and P3. The cash flow among them is like below −

![Splitwise_1](https://user-images.githubusercontent.com/53916781/126213504-78531a30-4c13-4b56-9688-88e943b3b638.jpg)

This cash flow is not minimum; we have to minimize it. Then the final diagram will be like −

![Splitwise_2](https://user-images.githubusercontent.com/53916781/126213533-f1f2664a-f217-44dc-be37-6f703cf594f6.jpg)

How to pick the first person in such a case? 
- To pick the first person, we first calculate the net amount for every person where net amount is obtained by subtracting all debts (amounts to pay) from all credits (amounts to be paid). 
- Once net amount for every person is evaluated, we find two persons with maximum and minimum net amounts. These two persons are the most creditors and debtors. The person with minimum of two is our first person to be settled and removed from list. 
- Let the minimum of two amounts be x. We pay ‘x’ amount from the maximum debtor to maximum creditor and settle one person. 
- If x is equal to the maximum debit, then maximum debtor is settled, else maximum creditor is settled.

### Algorithm:

1. For every person Pi, from 0 to n – 1, do the following steps.
2. Compute the net amount for every person. Net amount for a person 'i' can be computed by subtracting the sum of all debts from the sum of all credits.
3. Find maximum creditor Pc and maximum debtor Pd. Suppose the maximum amount to be credited to a maximum creditor is maxCredit, and the maximum amount debited from a maximum debtor is called maxDebit.
4. Set x: = minimum of maxCredit and maxDebit. Then debit x from Pd, and credit x to Pc.
5. If x is the same as the maxCredit, then remove Pc from the set and recur for next n-1 persons.
6. If x is same as maxDebit, then remove Pd from a set of persons and recur for next n-1 persons.

### Complexity Analysis:

Time Complexity - O(N^2) where N is the number of persons

Algorithm Paradigm - Greedy
