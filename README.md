# Welcome to Splitwise Readme!

Generally, splitwise is a free app that allows consumers to split expenses with friends. For splitting bills with friends and family, splitwise can track each expense and the amount that each person in the group owes.

## About the Project:

This is a ```C++``` program which is used to minimize the cash flow (or the number of transactions) among a set of friends who have borrowed money from each other. 

---

# Getting Started

### Approach:

The idea is to use **Greedy Algorithm** where at every step, such that the program settle all amounts of one person and recur for remaining n-1 persons. 

### How to proceed?

For example, if the following weighted directed graph represents some people and the arrows represent debts between them (Alice owes Bob Rs. 20 and Charlie Rs. 5, Bob owes Charlie Rs. 10, etc.):

![Spliwise](https://user-images.githubusercontent.com/53916781/126199164-ee102ce7-45c8-41dc-8478-51efa8dda890.png)

There's no sense in Rs. 10 making its way from Alice to Bob and then from Bob to Charlie if Alice could just give it to Charlie directly. The goal, then, in the general case is to take a debt graph and simplify it (i.e. produce a new graph with the same nodes but different edges).

How to pick the first person in such a case? 
- To pick the first person, we first calculate the net amount for every person where net amount is obtained by subtracting all debts (amounts to pay) from all credits (amounts to be paid). 
- Once net amount for every person is evaluated, we find two persons with maximum and minimum net amounts. These two persons are the most creditors and debtors. The person with minimum of two is our first person to be settled and removed from list. 
- Let the minimum of two amounts be x. We pay ‘x’ amount from the maximum debtor to maximum creditor and settle one person. 
- If x is equal to the maximum debit, then maximum debtor is settled, else maximum creditor is settled.
