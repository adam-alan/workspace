public class Main {
    public static void main(String [] args){
        LinkedList list = new LinkedList();
        list.addList();
        list.print(list.getHead().getNext());
        System.out.println(list.length(list.getHead().getNext()));
        list.setHead(list.reverse(list.getHead().getNext()));
        list.print(list.getHead());
    }
}
