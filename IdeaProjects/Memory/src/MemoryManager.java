import java.util.LinkedList;

final class FreeBlock{
    private int size;
    private boolean isAlloced;
    private int startAddr;

    FreeBlock(int size,boolean isAlloced,int startAddr){
        this.size = size;
        this.isAlloced = isAlloced;
        this.startAddr = startAddr;
    }

    FreeBlock(){
        this.size = 0;
        this.isAlloced = false;
        this.startAddr = 0;
    }


    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public boolean isAlloced() {
        return isAlloced;
    }

    public void setAlloced(boolean alloced) {
        isAlloced = alloced;
    }

    public int getStartAddr() {
        return startAddr;
    }

    public void setStartAddr(int startAddr) {
        this.startAddr = startAddr;
    }
}


public abstract class MemoryManager {
    protected LinkedList<FreeBlock> freeBlockList;
    public abstract boolean MemoryAlloc(int size);
    public abstract void MemoryFree(FreeBlock freeBlock);
    public abstract void MemoryInit(int size);
    public abstract void showMemory();
}
