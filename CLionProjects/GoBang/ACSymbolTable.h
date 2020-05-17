//
// Created by zhuxingtian on 19-11-6.
//

#ifndef GOBANG_ACSYMBOLTABLE_H
#define GOBANG_ACSYMBOLTABLE_H

#include <memory>
#include <string>
#include <queue>
#include <set>
template <typename Value>
struct ACNode{
    char data;
    bool isEndOfString;
    std::size_t length;
    std::shared_ptr<ACNode> failurePointer;
    std::shared_ptr<Value> value;
    std::shared_ptr<ACNode> children[256];
    ACNode(char data):
    failurePointer(nullptr),
    value(nullptr),
    length(-1),
    isEndOfString(false)
    {
        this->data = data;
    }
};

template <typename Value>
class ACSymbolTable {

private:
    using ACNodePtr = std::shared_ptr<ACNode<Value>>;
    ACNodePtr root;
public:
    ACSymbolTable():root(std::make_shared<ACNode<Value>>('/')){}

    void put(const std::string & key,Value value){
        ACNodePtr acNodePtr = root;
        for (int i = 0 ;i < key.length();i++){
            if (acNodePtr->children[key[i]] == nullptr){
                acNodePtr->children[key[i]] = std::make_shared<ACNode<Value>>(key[i]);
            }

            acNodePtr = acNodePtr->children[key[i]];
        }
        acNodePtr->value = std::make_shared<Value>(value);
        acNodePtr->isEndOfString = true;
        acNodePtr->length = key.length();
    }

    std::shared_ptr<Value> get(const std::string & key){
        ACNodePtr acNodePtr= root;
        for (int i = 0;i < key.length();i++){
            if (acNodePtr->children[key[i]] == nullptr){
                return nullptr;
            }
            acNodePtr = acNodePtr->children[key[i]];
        }
        if (acNodePtr->isEndOfString == true){
            return acNodePtr->value;
        } else{
            return nullptr;
        }
    }

    void buildFailurePointer(){
        std::queue<ACNodePtr> queue;
        root->failurePointer = nullptr;
        queue.push(root);

        while (!queue.empty()) {
            ACNodePtr  acNodePtr1 = queue.front();
            queue.pop();
            for (int i = 0;i < 256;i++){
                ACNodePtr acNodePtr1Child = acNodePtr1->children[i];
                if (acNodePtr1Child == nullptr){
                    continue;
                }
                if (acNodePtr1 == root){
                    acNodePtr1Child->failurePointer = root;
                } else {
                    ACNodePtr acNodePtr2 = acNodePtr1->failurePointer;
                    while (acNodePtr2 != nullptr){
                        ACNodePtr  acNodePtr2Child = acNodePtr2->children[acNodePtr1Child->data];
                        if (acNodePtr2Child != nullptr) {
                            acNodePtr1Child->failurePointer = acNodePtr2Child;
                            break;
                        }
                        acNodePtr2 = acNodePtr2->failurePointer;
                    }

                    if (acNodePtr2 == nullptr) {
                        acNodePtr1Child->failurePointer = root;
                    }
                }
                queue.push(acNodePtr1Child);
            }
        }
    }

    std::set<std::string> match(const std::string & key) {
        ACNodePtr acNodePtr = root;
        std::set<std::string> matchStrings;
        for (int i = 0;i < key.length();i++) {
            while (acNodePtr->children[key[i]] == nullptr and acNodePtr != root) {
                acNodePtr = acNodePtr->failurePointer;
            }

            acNodePtr = acNodePtr->children[key[i]];
            if (acNodePtr == nullptr) {
                acNodePtr = root;
            }
            ACNodePtr tmpAcNodePtr = acNodePtr;
            while (tmpAcNodePtr != root) {
                if (tmpAcNodePtr->isEndOfString) {
                    int begin = i + 1 - tmpAcNodePtr->length;
                    int end = i + 1;
                    std::string matchString = "";
                    while (begin < end) {
                        matchString += key[begin];
                        begin += 1;
                    }
                    matchStrings.insert(matchString);
                }
                tmpAcNodePtr = tmpAcNodePtr->failurePointer;
            }

        }
        return matchStrings;
    }


};


#endif //GOBANG_ACSYMBOLTABLE_H
