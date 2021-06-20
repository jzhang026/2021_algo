// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

// K 个一组翻转链表

//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
private:
    ListNode *getEnd(ListNode *pNode, int k) {
        while (pNode != nullptr) {
            if (k == 0) break;
            pNode = pNode->next;
            k--;
        }
        return pNode;
    }

    void reverseList(ListNode *start, ListNode *end) {
        /**
         * 此方法用来反转包括头尾 start 和 end 之间的一段链表
         *
         * 假设链表为 head -> ... -> A -> B -> C -> ... -> nullptr
         * 我们要反转A -> B -> C, 此时不用管 A 和 C之外的部分，因为在主程序里会把它接回去
         * 所以此处的prev是从start开始的。
         *
         * */
        auto prev = start;
        start = start->next;

        while (prev != end) {
            auto t = start->next;
            start->next = prev;
            prev = start;
            start = t;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* protectNode = new ListNode();
        protectNode->next = head;
        auto last = protectNode;
        while (head != nullptr) {
            // k 个节点一组对链表分段
            // 先拿到每段的末端
            // 对链表的操作都是对于链表的边的操作
            // k 个节点，也就是 k - 1 条边。
            // 所以我们在getEnd里传入 k - 1
            ListNode* end = getEnd(head, k-1);

            // 意味着剩下的节点不足 k - 1 个
            if (end == nullptr) break;
            // 记录末尾
            auto nextGroupHead = end->next;

            reverseList(head, end);

            last->next = end;
            head->next = nextGroupHead;
            last = head;
            head = nextGroupHead;
        }

        return protectNode->next;
    }
};
