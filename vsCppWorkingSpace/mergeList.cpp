# include <iostream>
# include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



ListNode * createList(){
    ListNode *ListHead = new ListNode(0);
    ListNode *ListRail = ListHead;
    for (int i = 0; i < 10; i++)
    {
        ListNode *node = new ListNode(2 * i);
        ListRail->next = node;
        ListRail = ListRail->next;
    }
    return ListHead;
}

void printList(ListNode * ListHead){
    if (ListHead == nullptr || ListHead->next == nullptr) {
        return;
    }
    ListNode *p = ListHead->next;
    while (p!=nullptr) {
        std::cout << p->val << "\t";
        p = p->next;
    }
    std::cout << std::endl;
}

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *resultListHead = new ListNode(-1);
    ListNode *resultListRail{resultListHead};
    if (l1 != nullptr) {
        l1 = l1->next;
    }
    if (l2 != nullptr) {
        l2 = l2->next;
    }
    while (l1 != nullptr and l2 != nullptr)
    {
        if (l1->val <= l2->val) {

            resultListRail->next = l1;
            l1 = l1->next;
        } else {            
            resultListRail->next = l2;
            l2 = l2->next;
        }
        resultListRail = resultListRail->next;
    }

    resultListRail->next = (l1 != nullptr) ? l1 : l2;
    return resultListHead;
}

int main(int argc, const char** argv) {
    ListNode * list[4] = {createList(), createList(), createList(), createList()};
    ListNode *resultList = nullptr;
    for (auto iter : list)
    {
        resultList = mergeList(resultList, iter);
        //printList(resultList);
    }
      


    printList(resultList);
    return 0;
}
