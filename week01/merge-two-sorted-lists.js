// https://leetcode-cn.com/problems/merge-two-sorted-lists

// 合并两个有序链表

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let protectNode = new ListNode();
    let tail = protectNode;
    while (l1 != null && l2 != null) {
        if (l1.val <= l2.val) {
            tail.next =l1;
            l1 = l1.next;
        } else {
            tail.next = l2;
            l2 = l2.next;
        }
        tail = tail.next;
    }
    let remains = l1 == null ? l2 : l1;
    tail.next = remains;

    return protectNode.next;
};