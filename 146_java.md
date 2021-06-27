### LRU 缓存机制

题目地址<! "https://leetcode-cn.com/problems/lru-cache/submissions/">
```
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

Code解法
思路
```
1.这里主要使用Map来存储key于节点的映射问题，解决快速找到节点
2.使用双链接，是解决快速的删除问题。
3.当读取数据的时候，是先判断在map中是否存在key，如果不存在，那么说明根本就没有数据，直接返回。如果有数据，那么先把他从原来的链表节点中删除，然后插入到队头的后面。
4.当存储数据的时候，也是先判断是否原来的链表已经有了数据，如果已经有了数据，那么也是先从原来的链表中删除数据，把数据重新插入到队头。如果没有数据那么直接插入到队头就行。然后就是判断是否超过容量，如果超过那么删除队尾前面一个值。
```

Code
```
class LRUCache {
    //存储key,Node 快速查找
    public HashMap <Integer,Node> map;
    public Node head; //保护节点对头
    public Node tail; //保护节点队尾
    public int capacity; //容量

    public class Node { //节点数据
        public Node pre; //前数据
        public Node next; //后数据
        public int val; //值
        public int key; //key
    }

    
    public LRUCache(int capacity) { //初始化
            this.capacity = capacity;
            this.head = new Node();
            this.tail = new Node();
            this.head.next = tail; //前头和尾的初始化 
            this.tail.pre =  head;
            this.map = new HashMap<Integer,Node>(); //初始化map
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) return -1; //判断是否有key,没有直接返回
        Node node = map.get(key); //读取值
        //从原来的链表中删除
        this.deleteFromList(node);
        //插入到链表的头部
        this.insertToListHead(key,node.val);
        return node.val; //返回值
    }
    
    public void put(int key, int value) {
        if (map.containsKey(key)) { //如果包含有值
            Node node = map.get(key);
            this.deleteFromList(node); //从链表中删除
            this.insertToListHead(key,value);//插入到队头
        } else { //如果不存在，那么直接插入到队头
            this.insertToListHead(key,value); 
        }
        //判断容量删除数据
        if (this.map.size() > this.capacity) {
            deleteFromList(tail.pre);
        }
    }

    public void deleteFromList(Node node) {
        node.pre.next = node.next; //先把指前对象的后的指针指向后对象
        node.next.pre = node.pre; //然后把后对象的前指针，指向前对象
        map.remove(node.key);
    }

    public void insertToListHead(int key,int value) {
        Node node = new Node();
        node.key = key;
        node.val = value;
        //node与head.next的关系
        node.next = head.next;
        head.next.pre = node;
        //node与head的关系
        node.pre = head;
        head.next = node;
        this.map.put(key,node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

```

