public class Main {
    public static void main(String[] args) {
        MemoryManager memoryManager = new FirstFitManager();
        memoryManager.MemoryInit(4096);
        memoryManager.MemoryAlloc(450);
        memoryManager.showMemory();
    }
}
