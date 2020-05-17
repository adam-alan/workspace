//
// Created by zhuxingtian on 19-11-5.
//

#ifndef GOBANG_TRIESYMBOLTABLE_H
#define GOBANG_TRIESYMBOLTABLE_H

#include <memory>
#include <string>

template <typename Value>
struct TrieTreeNode{
    std::shared_ptr<Value> value;
    std::shared_ptr<TrieTreeNode> children[256];
    TrieTreeNode():value(),children(){

    }
};

template <typename Value>
class TrieSymbolTable {

//private:

public:

    using TrieTreeNodePtr = std::shared_ptr<TrieTreeNode<Value>>;

    TrieTreeNodePtr root;
    TrieSymbolTable():root(std::make_shared<TrieTreeNode<Value>>()){}

    std::shared_ptr<Value> get(std::string key){
        TrieTreeNodePtr trieTreeNodePtr= get(root,key,0);
        if (trieTreeNodePtr == nullptr) {
            return nullptr;
        }
        return trieTreeNodePtr->value;
    }
    void put(std::string key, Value value){
        this->root = put(root,key,value,0);
    }


private:

    TrieTreeNodePtr get(TrieTreeNodePtr trieTreeNodePtr,const std::string & key,int depth){
        if (trieTreeNodePtr == nullptr) {
            return nullptr;
        }
        if (depth == key.length()) {
            return trieTreeNodePtr;
        }
        return get(trieTreeNodePtr->children[key[depth]],key,depth + 1);
    }

    TrieTreeNodePtr put(TrieTreeNodePtr trieTreeNodePtr,const std::string & key,const Value & value,int depth){
        if (trieTreeNodePtr == nullptr) {
            trieTreeNodePtr = std::make_shared<TrieTreeNode<Value>>();
        }
        if (depth == key.length()) {
            trieTreeNodePtr->value = std::make_shared<Value>(value);
            return trieTreeNodePtr;
        }
        trieTreeNodePtr->children[key[depth]] = put(trieTreeNodePtr->children[key[depth]],key,value,depth + 1);
        return trieTreeNodePtr;
    }

};


#endif //GOBANG_TRIESYMBOLTABLE_H
