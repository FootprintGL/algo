


class bstnode {
    /* 二叉搜索树节点 */
    int val;
    /* 节点的秩 */
    int leftsize;
    /* 左儿子 */
    bstnode *left;
    /* 右儿子 */
    bstnode *right;
public:
    bstnode(int val) {
        this->val = val;
        this->leftsize = 1;
        left = NULL;
        right = NULL;
    }

    void insert(int val) {
        if (this->val >= val) {
            /* 放入左子树，更新当前节点的秩 */
            this->leftsize++;
            if (this->left == NULL) {
                this->left = new bstnode(val);
            } else {
                this->left->insert(val);
            }
        } else {
            /* 放入右子树 */
            if (this->right == NULL) {
                this->right = new bstnode(val);
            } else {
                this->right->insert(val);
            }
        }
    }

    int find(int val) {
        if (this->val > val) {
            /* 在左子树 */
            if (this->left == NULL)
                return 0;
            return this->left->find(val);
        } else {
            /* 在右子树 */
            if (this->right == NULL) {
                return this->leftsize;
            }
            return this->leftsize + this->right->find(val);
        }
    }
};

/*
 * 二叉搜索树
 * 将小于等于this->val的值插入左子树，然后把this->leftsize++
 * leftsize记录的是它的左子树的节点个数，即当前节点的秩
 */
class BST {
    bstnode *root;
public:
    BST() {
        root = NULL;
    }
    void insert(int val) {
        if (root == NULL) {
            root = new bstnode(val);
        } else {
            root->insert(val);
        }
    }
    int find(int val) {
        if (root == NULL) {
            return 0;
        } else {
            return root->find(val);
        }
    }
};

class StreamRank {
public:
    /* 二叉搜索树加速插入和搜索 */
    BST *bst;

    StreamRank() {
        bst = new BST();
    }

    void track(int x) {
        bst->insert(x);
    }

    int getRankOfNumber(int x) {
        return bst->find(x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
