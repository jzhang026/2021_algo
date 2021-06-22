## 概念模型
当我们要处理一个list或者一条链表时，常常需要遍历每一个元素，
遍历的模型基本是：
- array list: `dataList`
```
FOR each data IN list {
    // ... other logic
    process(data);
}
```

- link list: `head`是这里的头指针
```
WHILE (head NOT null) {
    // ... other logic
    process(head)
    head = head.next;
}
```

#### 示例：
    
反转链表的某一区间，区间的开始节点为 start ，结束节点为 end 。
 ```

 // 链表节点的结构是：Node(): val(dataType), next(*Node)
 // 节点里又两个字段：
 //    value: 数据类型是dataType，
 //    next: 只想下个节点的指针或者reference
 
 // head 是链表的头节点
function reverseSection(ListNode head, ListNode start, ListNode end,) {
    // 当反转区间的起始节点是头节点时，代码就会变得很难看
    // 为了简化这种问题，我们给链表开头加个保护节点
    ListNode protectNode = new Node("N/A")
    protectNode.next = head;
    
    // protectNode -> head -> ... -> before -> start -> ... -> end -> after -> ... 
    //反转前，需要记录 before 和 after, 方便我们反转后接回去
    before = protectNode;
    while (before.next != start) before = before.next; // 因为是伪代码，不考虑before为null的这些细节问题
    after = end.next
    
    // 记录好边界开始反转
    reverseList(LinstNode start, ListNode end);
    
    // 把反转后的区间接回去
    before.next = end;
    start.next = after;
    
    // 返回链表,在这里可以体会一下保护节点的好处
    return protectNode.next;
}

function reverseList(LinstNode start, ListNode end) {
    if (start == end) return;
    // 反转链表的思路就是，当前节点的next要指向链表的上一个节点
    // 我们用prev记录上一个节点
    // curr 记录当前正在处理的节点
    prev = start;
    curr = start.next;
    while (curr != end) {
        nextCurr = curr.next;
        // 换curr 节点的边，指向上一个节点
        curr.next = prev;
        // 更新节点
        prev = curr;
        curr = nextCurr;
    }
    // 注意while的判断条件是到达end时停止了换边的操作
    // 所以我们在推出while后，要补上这个换边操作
    curr.next = prev;
}
```
### 栈
解决最近相关性的问题，都可以用栈。 什么叫最近相关性呢？
假如有一批待处理的数据序列，在当前k位置时，程序的状态，不仅仅由k决定时，需要考虑k的领近节点时，
我们就称为最近相关性。
```
stack s
for (data in list) {
    //... logic
    a = s.pop();// 你可能需要pop多个元素
    ret = process(a, data)
    s.push(ret) // 保存当前状态
}
```
