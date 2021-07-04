// https://leetcode-cn.com/problems/lru-cache/

// LRU 缓存机制

// 实现 LRUCache 类：
//
// LRUCache(int capacity) 以正整数作为容量capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value)如果关键字已经存在，则变更其数据值；
// 如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，
// 它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。


// 双链表维护cache value的先后顺序

/**
 * @param {string} key
 * @param {number} value
 * return {this}
 * */
function Node(key, value) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
}
/**
 * @param {number} capacity
 */
const LRUCache = function(capacity) {
    this.size = 0;
    this.capacity = capacity;

    // map key -> Node. 使得查询操作为O(1)
    this.map = new Map();

    // prepare double linked list
    this.head = new Node(null, null);
    this.tail = new Node(null, null);
    this.head.next = this.tail;
    this.tail.prev = this.head;
};


/**
 * @param {Node} node
 */
LRUCache.prototype.deleteNode = function(node) {
    let prev = node.prev;
    let next = node.next;
    prev.next = next;
    next.prev = prev;
    this.map.delete(node.key);
    this.size--;
}

/**
 * @param {Node} node
 */
LRUCache.prototype.insertHead = function(node) {
    let headNext = this.head.next;
    this.head.next = node;
    node.prev = this.head;
    node.next = headNext;
    headNext.prev = node;
    this.map.set(node.key, node);
    this.size++;
}



/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.map.has(key)) {
        let node = this.map.get(key);
        // 首先从链上删除，然后插入到头部
        this.deleteNode(node);
        this.insertHead(node);
        return node.value;
    }
    return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {null}
 */
LRUCache.prototype.put = function(key, value) {
    let newNode = new Node(key, value);
    if (this.map.has(key)) {
        let node = this.map.get(key);
        // 首先从链上删除，然后插入到头部
        this.deleteNode(node);
        this.insertHead(newNode);
    } else {
        // 是一个新的key
        // 插入之前查看size
        if (this.size === this.capacity) {
            // 删除最末尾的
            this.deleteNode(this.tail.prev);
        }

        this.insertHead(newNode);
    }
    return null;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */