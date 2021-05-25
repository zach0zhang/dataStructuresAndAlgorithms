#ifndef __LINKED_BINARY_TREE__
#define __LINKED_BINARY_TREE__
#include <list>
#include <queue>

template <typename E>
class LinkedBinaryTree {
protected:
    struct Node {
        E elt;
        Node* par;
        Node* left;
        Node* right;
        Node() : elt(), par(NULL), left(NULL), right(NULL) { }
    };

public:
    class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v) { }
        E& operator*() { return v->elt; }
        E* operator->() const { return &v->elt; }
        bool operator==(const Position& p) const { return v == p.v; }
        Position left() const { return Position(v->left); }
        Position right() const { return Position(v->right); }
        Position parent() const { return Position(v->par); }
        bool isRoot() const { return v->par == NULL; }
        bool isExternal() const { return v->left == NULL && v->right == NULL; }
        bool isInternal() const { return v->left != NULL || v->right != NULL; }
        friend class LinkedBinaryTree;
    };
    typedef std::list<Position> PositionList;

public:
    LinkedBinaryTree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expendExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
    void addNode(const E& e);
    PositionList levelOrder() const;

protected:
    void preorder(Node* v, PositionList& pl) const;
private:
    Node* _root;
    int n;
};


template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree() : _root(NULL), n(0) { }

template <typename E>
int LinkedBinaryTree<E>::size() const {
    return n;
}

template <typename E>
bool LinkedBinaryTree<E>::empty() const {
    return size() == 0;
}

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::root() const {
    return Position(_root);
}

template <typename E>
void LinkedBinaryTree<E>::addRoot() {
    _root = new Node;
    n = 1;
}

template <typename E>
void LinkedBinaryTree<E>::expendExternal(const Position& p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

template <typename E>
typename LinkedBinaryTree<E>::Position LinkedBinaryTree<E>::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    Node* v = w->par;
    Node* sib = (w == v->left ? v->right : v->left);

    if (v == _root) {
        _root = sib;
        sib->par = NULL;
    } else {
        Node* gpar = v->par;
        if (v == gpar->left)
            gpar->left = sib;
        else
            gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}

template <typename E>
void LinkedBinaryTree<E>::preorder(Node *v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL)
        preorder(v->left, pl);
    if (v->right != NULL)
        preorder(v->right, pl);
}

template <typename E>
typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::positions() const {
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

template <typename E>
void LinkedBinaryTree<E>::addNode(const E& e) {
    if (empty() == true) {
        addRoot();
        _root->elt = e;
        return;
    }

    Node* addNode = new Node;
    addNode->elt = e;

    PositionList pl;
    preorder(_root, pl);
    typename PositionList::iterator it = pl.begin();
    while (it != pl.end()) {
        Node* n = it->v;
        if (n->left == NULL) {
            addNode->par = n;
            n->left = addNode;
            return;
        } else if (n->right == NULL) {
            addNode->par = n;
            n->right = addNode;
            return;
        } else {
            it++;
            continue;
        }
    }
}

template <typename E>
typename LinkedBinaryTree<E>::PositionList LinkedBinaryTree<E>::levelOrder() const {
    PositionList pl;
    std::queue<Node*> nodeQueue;

    nodeQueue.push(_root);

    while(!nodeQueue.empty()) {
        Node* tmp = nodeQueue.front();
        if (tmp->left != NULL) {
            nodeQueue.push(tmp->left);
        }

        if (tmp->right != NULL) {
            nodeQueue.push(tmp->right);
        }

        pl.push_back(Position(tmp));
        nodeQueue.pop();
    }
    return PositionList(pl);
}
#endif