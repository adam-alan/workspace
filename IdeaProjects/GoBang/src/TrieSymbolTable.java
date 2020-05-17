public class TrieSymbolTable<Value> {
    private static int RANGE = 256;
    private TrieTreeNode root;
    private static class TrieTreeNode{
        private Object value;
        private TrieTreeNode [] children = new TrieTreeNode[RANGE];
    }



    public Value get(String key){

    }
}
