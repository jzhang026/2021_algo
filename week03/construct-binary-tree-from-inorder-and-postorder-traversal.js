/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {

    // 从后序遍历的最后一个元素开始
    let post_idx = postorder.length - 1;
    const inorderValue2Key = {};
    // 建立（元素，下标）键值对的哈希表
    inorder.forEach((val, idx) => {
        inorderValue2Key[val] = idx;
    });

    function construct (in_left, in_right) {
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return null;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        const root_val = postorder[post_idx];
        const root = new TreeNode(root_val);

        // 根据 root 所在位置分成左右两棵子树
        const index = inorderValue2Key[root_val];

        // 下标减一
        post_idx--;
        // 构造右子树
        root.right = construct(index + 1, in_right);
        // 构造左子树
        root.left = construct(in_left, index - 1);
        return root;
    }

    return construct(0, inorder.length - 1);
};