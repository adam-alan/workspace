    import java.util.LinkedList;

public class FirstFitManager extends MemoryManager{

    FirstFitManager(){
        freeBlockList = new LinkedList<>();
    }

    @Override
    public void MemoryInit(int size) {
        if (freeBlockList.isEmpty() == true){
            freeBlockList.add(new FreeBlock(size,false,0));
        }
    }

    @Override
    public boolean MemoryAlloc(int size) {
        boolean isChanged = false;
        //freeBlockList.sort();
        for (int i = 0;i < freeBlockList.size();i++) {
            if (freeBlockList.get(i).getSize() >= size &&
                    freeBlockList.get(i).isAlloced() == false){
                if (freeBlockList.get(i).getSize() == size){
                    freeBlockList.get(i).setAlloced(true);
                    return true;
                } else {
                    freeBlockList.add(new FreeBlock(size,true,freeBlockList.get(i).getStartAddr()));
                    freeBlockList.get(i).setSize(freeBlockList.get(i).getSize() - size);
                    freeBlockList.get(i).setStartAddr(freeBlockList.get(i).getStartAddr() + size);
                    return true;
                }
            }

        }
        return false;
    }

    @Override
    public void MemoryFree(FreeBlock freeBlock) {

    }

    @Override
    public void showMemory() {
        System.out.printf("%-16s%-16s%-16s\n","Size","isAlloced","StartAddr");
        for (FreeBlock freeBlock:freeBlockList) {
            System.out.printf("%-16s%-16s%-16s\n",freeBlock.getSize(),freeBlock.isAlloced(),freeBlock.getStartAddr());

        }
    }

}
