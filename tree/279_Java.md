 # 279 二叉树的序列化与反序列化
```
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

```
code
```
public class Code {
    //定义解码成功后的，数组
    private List<String> seq = new ArrayList();
    private int curr = 0; //移动的下标
    public String serialize(TreeNode root) {
        seq = new ArrayList();
        resetver(root);
        return String.join(" ",seq);
    }

    public void resetver(TreeNode root) {
        if (root == null) {
            seq.add("null");
            return;
        }
        seq.add(Integer.toString(root.val));
        resetver(root.left);
        resetver(root.right);
    }

    // Decodes your encoded data to tree.
    // [1 2 null null 3 4 null null 5 null null]
    public TreeNode deserialize(String data) {
        //反解成 数组对象
        seq = Arrays.asList(data.split(" "));
        curr = 0;
        return cacl();
    }
    //计算
    public TreeNode cacl() {
        if (seq.get(curr).equals("null")) {
            curr++;
            return null;
        }
        //复原根
        TreeNode tree = new TreeNode(Integer.parseInt(seq.get(curr)));
        //计算左右
        curr++;
        tree.left = cacl(); //依次递归
        tree.right = cacl();
        return tree;
    }
}
```




