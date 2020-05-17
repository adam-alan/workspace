import java.util.LinkedList;

public class TrieST<Value> {
    private static int R = 256;

    private Node root;
    TrieST(){

    }
    private static class Node{
        private Object val;
        private Node [] next = new Node[R];
    }

    @SuppressWarnings("unchecked")
    public Value get(String key){
        Node x = get(root,key,0);
        if (x == null) return null;
        return (Value) x.val;
    }

    private Node get(Node x,String key,int d){
        if (x == null) return null;
        if (d == key.length()) return x;
        char c = key.charAt(d);
        return get(x.next[c],key,d+1);
    }

    public void put(String key,Value val){
        root = put(root,key,val,0);
    }

    private Node put(Node x,String key,Value val,int d){
        if (x == null) x = new Node();
        if (d == key.length()) {x.val = val;return x;}
        char c = key.charAt(d);
        x.next[c] = put(x.next[c],key,val,d+1);
        return x;
    }

    public Iterable<String> keysThatMatch(String pat){
        LinkedList<String> linkedList = new LinkedList<>();
        collect(root,"",pat,linkedList);
        return linkedList;
    }

    private void collect(Node x,String pre,String pat,LinkedList<String> linkedList){
        int d = pre.length();

        if (x == null) return;
        if (d == pat.length() && x.val != null) {
            linkedList.add(pre);
        }
        if (d == pat.length()) return;
        char next = pat.charAt(d);

        for (char c = 0;c < R;c++){
            if (next == '.' || next == c)
                collect(x.next[c],pre + c,pat,linkedList);
        }
    }
}
