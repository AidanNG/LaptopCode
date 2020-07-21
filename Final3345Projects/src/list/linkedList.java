package list;
class listNode<T>{
    private T value;
    public listNode<T> next;

    public listNode(T value) {
        this.value = value;
    }

    public void setNext(listNode<T> next) {
        this.next = next;
    }

    public listNode<T> getNext() {
        return next;
    }

    public T getValue() {
        return value;
    }
}

public class linkedList <T>{
    private listNode<T> head;
    private int size;
    public linkedList(){
        head  = null;
        head.setNext(null);
        size=0;
    }
    public int getSize(){
        return size;
    }
    public void add(T item){
        listNode<T> new_node = new listNode<T>(item);
        new_node.setNext(null);
        if (head == null) {
            head = new_node;
            size++;
        }
        else {
            listNode<T> last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = new_node;
            size++;
        }
    }
    public boolean remove(T item){
        listNode<T> currNode = head, prev = null;
        if (currNode != null && currNode.getValue() == item) {
            head = currNode.next;
            return true;
        }
        while (currNode != null && currNode.getValue() != item) {
            prev = currNode;
            currNode = currNode.next;
        }
        if (currNode != null) {
            prev.next = currNode.next;
            return true;
        }
        if (currNode == null) {
            return false;
        }
        return false;
    }
}
