

struct Node {
	int key;
	Node* listNode;
	Node(int key,Node* listNode): key(key),listNode(listNode){}
}

class BinerSerarch {
    private:
       vector<Node> data;
    public:
       bool empty() {
           return data.size() == 0;
       }
        void push(const Node& node) {
            data.push_back(node);
            int p = data.size() - 1;
            while (p > 0) {
                int fa =  (p - 1) >> 1;
                if (data[fa].key > data[p].key) {
                    swap(data[fa],data[p]);
                    p = fa;
                } else {
                    break;
                }
            }
        }

        Node pop() {
            Node node = data[0];
            data[0] = data[data.size() - 1];
            data.pop_back();
            int p = 0;
            int child = 2 * p + 1;
            while (child < data.size()) {
                int rightChild = 2 * p + 2;
                if (data[child].key > data[rightChild].key) {
                        child = rightChild;
                }
                if (data[p].key > data[child].key) {
                    swap(data[p],data[child]);
                    p = child;
                    child = 2 * p + 1;
                } else {
                    break;
                }
            }
            return node;
        }
};

