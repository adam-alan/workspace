public class LinkedList {
    private ListNode head;
    private ListNode rail;

    LinkedList(){
        head = rail = new ListNode(0);
    }

    public ListNode getHead() {
        return head;
    }

    public ListNode getRail() {
        return rail;
    }

    public void setHead(ListNode head) {
        this.head = head;
    }

    public void setRail(ListNode rail) {
        this.rail = rail;
    }

    public void addList(){
        ListNode node;
        for (int i = 0;i < 10;i++){
            node = new ListNode(i);
            rail.setNext(node);
            rail = node;
        }
    }

    public void print(ListNode node){
        if (node != null){
            System.out.println(node.getData());
            print(node.getNext());
        }
    }

    public int length(ListNode node){
        if (node != null){
            return length(node.getNext()) + 1;
        }
        return 0;
    }

    public ListNode reverse(ListNode node){
        if (node == null || node.getNext() == null){
            return node;
        }

        ListNode newList = reverse(node.getNext());
        ListNode tmp1 = node.getNext();
        tmp1.setNext(node);
        node.setNext(null);
        return newList;
    }
}

final class ListNode{
    private int data;
    private ListNode next;
    ListNode(int data){
        this.data = data;
        this.next = null;
    }
    public void setData(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setNext(ListNode next) {
        this.next = next;
    }

    public ListNode getNext() {
        return next;
    }
}
