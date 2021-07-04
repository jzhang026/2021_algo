// https://leetcode-cn.com/problems/merge-k-sorted-lists/

// 合并K个升序链表

// 给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。


/**
 * Definition for singly-linked list.
 */

#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        auto midIndex = int(lists.size() / 2);
        auto firstHalf = slicing(lists, 0, midIndex - 1);
        auto secondHalf = slicing(lists, midIndex, lists.size() - 1);
        return mergeTwoLists(mergeKLists(firstHalf), mergeKLists(secondHalf));
    }

private:
    ListNode *mergeTwoLists(ListNode *list_1, ListNode *list_2) {
        ListNode protectNode = ListNode();
        auto head = &protectNode;
        while (list_1 != nullptr && list_2 != nullptr) {
            if (list_1->val < list_2->val) {
                head->next = list_1;
                list_1 = list_1->next;
            } else {
                head->next = list_2;
                list_2 = list_2->next;
            }
            head = head->next;
        }

        auto remaining = list_1 == nullptr ? list_2 : list_1;
        head->next = remaining;

        return protectNode.next;
    }

    vector<ListNode *> slicing(vector<ListNode *> const &v, int X, int Y) {

        // Begin and End iterator
        auto first = v.begin() + X;
        auto last = v.begin() + Y + 1;

        // Copy the element
        vector < ListNode * > vector(first, last);

        // Return the results
        return vector;
    }
};
