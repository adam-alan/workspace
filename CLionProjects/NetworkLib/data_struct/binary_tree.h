//
// Created by zhuxingtian on 19-12-31.
//

#ifndef NETWORKLIB_BINARY_TREE_H
#define NETWORKLIB_BINARY_TREE_H

#include <iterator>
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <queue>
using std::shared_ptr;
using std::ostream;
using std::vector;
using std::copy;
using std::distance;
using std::advance;
using std::cout;
using std::make_shared;

template <typename T>
struct BinaryTreeNode{
    T val;
    shared_ptr<BinaryTreeNode<T>> left_child;
    shared_ptr<BinaryTreeNode<T>> right_child;
};


template <typename T>
class BinaryTree {
public:
    BinaryTree(vector<T> preordered_sequence,
               vector<T> inordered_sequence):
               level_traversal_sequence_()
               {
        root_ = MakeByInorderAndPreorder(preordered_sequence,inordered_sequence);
    }
    shared_ptr<BinaryTreeNode<T>> MakeByInorderAndPreorder(vector<T> preordered_sequence,vector<T> inordered_sequence);
    void LevelTraversal(const shared_ptr<BinaryTreeNode<T>> & root,int level);
    void LevelTraversal(const shared_ptr<BinaryTreeNode<T>> & root);

    void PreorderTraversal(const shared_ptr<BinaryTreeNode<T>> & root) const noexcept ;
    void InorderTraversal(const shared_ptr<BinaryTreeNode<T>> & root) const noexcept ;
    int GetNodeNum(const shared_ptr<BinaryTreeNode<T>> & root);
    shared_ptr<BinaryTreeNode<T>> Root() const ;
private:
    vector<T> Slice(const vector<T> & input,int begin,int end);
    shared_ptr<BinaryTreeNode<T>> root_;
    vector<vector<int>> level_traversal_sequence_;

};
template <typename T>
ostream & operator<<(ostream & os,vector<T> v) {
    for (auto item:v) {
        os << item << " ";
    }
    return os;
}


template <typename T>
int BinaryTree<T>::GetNodeNum(const shared_ptr<BinaryTreeNode<T>> &root) {
    return (root == nullptr) ? 0 : GetNodeNum(root->left_child) + GetNodeNum(root->right_child) + 1;
}

template <typename T>
void BinaryTree<T>::PreorderTraversal(const shared_ptr<BinaryTreeNode<T>> &root) const noexcept {
    if (root != nullptr) {
        cout << root->val << "\t";
        PreorderTraversal(root->left_child);
        PreorderTraversal(root->right_child);
    }
}

template <typename T>
void BinaryTree<T>::InorderTraversal(const shared_ptr<BinaryTreeNode<T>> &root) const noexcept {
    if (root != nullptr) {
        InorderTraversal(root->left_child);
        cout << root->val << "\t";
        InorderTraversal(root->right_child);
    }
}

template <typename T>
void BinaryTree<T>::LevelTraversal(const shared_ptr<BinaryTreeNode<T>> &root, int level) {
    if (root) {
        level_traversal_sequence_[level].push_back(root->val);
        LevelTraversal(root->left_child, level + 1);
        LevelTraversal(root->right_child, level + 1);
    }
}

template <typename T>
vector<T> BinaryTree<T>::Slice(const vector<T> & input, int begin, int end) {
    auto begin_iter = input.begin();
    auto end_iter = input.begin();
    advance(begin_iter,begin);
    advance(end_iter,end);
    vector<T> result;
    copy(begin_iter,end_iter,back_inserter(result));
    return result;
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::MakeByInorderAndPreorder(vector<T> preordered_sequence,
                                                                      vector<T> inordered_sequence) {
    if (preordered_sequence.size() == 0 or inordered_sequence.size() == 0
        or preordered_sequence.size() != inordered_sequence.size()) {
        return nullptr;
    }

    auto iter = find(inordered_sequence.begin(), inordered_sequence.end(), preordered_sequence.front());
    auto step = distance(inordered_sequence.begin(),iter);
    auto root = make_shared<BinaryTreeNode<T>>();
    root->val = preordered_sequence.front();
    root->left_child = MakeByInorderAndPreorder(Slice(preordered_sequence, 1, 1 + step),Slice(inordered_sequence, 0, step));
    root->right_child = MakeByInorderAndPreorder(Slice(preordered_sequence, step + 1, preordered_sequence.size()),
                                                 Slice(inordered_sequence, step + 1, inordered_sequence.size()));
    return root;
}
template <typename T>
void BinaryTree<T>::LevelTraversal(const shared_ptr<BinaryTreeNode<T>> &root) {
    std::queue<shared_ptr<BinaryTreeNode<T>>> queue;
    queue.push(root);
    while (!queue.empty()) {
        shared_ptr<BinaryTreeNode<T>> node = queue.front();
        queue.pop();
        cout << node->val << "\t";
        if (node->left_child) {
            queue.push(node->left_child);
        }
        if (node->right_child) {
            queue.push(node->right_child);
        }
    }
}

template <typename T>
shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::Root() const {
    return root_;
}


#endif //NETWORKLIB_BINARY_TREE_H
