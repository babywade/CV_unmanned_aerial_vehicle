//二叉树三种遍历的递归形式与非递归形式
void preOrder1(BinTree *root) {
    if(root != NULL) {
        cout << root->data << " ";
        preOrder1(root->lchild);
        preOrder1(root->rchild);
    }
}

void inOrder1(BinTree *root) {
    if(root != NULL) {
        inOrder1(root->lchild);
        cout << root->data << " ";
        inOrder1(root->rchild);
    }
}

void postOrder1(BinTree *root) {
    if(root != NULL) {
        postOrder1(root->lchild);
        postOrder1(root->rchild);
        cout << root->data << " ";
    }
}

//利用stack实现非递归遍历
void preOrder2(BinTree *root) {
    stack<BinTree*> s;
    BinTree *p = root;
    while(p != NULL || !s.empty()) {
        while(p != NULL) {
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()) {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void inOrder2(BinTree *root) {
    stack<BinTree*> s;
    BinTree *p = root;
    while(p != NULL || !s.empty()) {
        while(p != NULL) {
            s.push(p);
            p = p->lchild;
        }
        if(!s.empty()) {
            p = s.top();
            cout << p->data << " ";
            s.pop();
            p = p->rchild;
        }
    }
}

void postOrder2(BinTree *root) {
    stack<BinTree*> s;
    BinTree *p = root;
    BinTree *pre = NULL;
    s.push(root);
    while(!s.empty()) {
        cur = s.top();
        if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->child || pre == cur->rchild))) {
            cout << cur->data << " ";
            s.pop();
            pre = cur;
        } else {
            if(cur->rchild != NULL) {
                s.push(cur->rchild);
            } 
            if(cur->lchild != NULL) {
                s.push(cur->lchild);
            }
        }
    }
}