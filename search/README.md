# 773. 滑动谜题

```
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.

一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

示例：
输入：board = [[1,2,3],[4,0,5]]
输出：1
解释：交换 0 和 5 ，1 步完成
输入：board = [[1,2,3],[5,4,0]]
输出：-1
解释：没有办法完成谜板

```
思路
```
1.把二维数组转换成单数组
2.把单数组转换成常数的转换
3.寻找0移动的位置,进行移动，计算最小值移动数
```

CODE
```
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        //二维数转成一维数组
       vector<int> list;
       for (int i = 0; i < 2; i++) {
           for (int j = 0; j < 3; j++) {
               list.push_back(board[i][j]);
           }
       }
       int val = zip(list);
       int endVal = 123450;
       dist[val] = 0;
       q.push(val);
       //bfs
       while(!q.empty()) {
           int now = q.front();
           q.pop();
           auto a = unzip(now);
           //查找0的位置
           int pos = getZeroIndex(a);
           // pos  pos - 1 向左
           if( pos != 0 && pos != 3) move(pos,pos - 1,now,a);
           // pos pos + 1向右
           if( pos != 2 && pos != 5) move(pos,pos + 1,now,a);
           // pos pos - 3 下上
           if( pos >= 3) move(pos,pos - 3,now,a);
           // pos pos + 3 向下
           if( pos < 3) move(pos,pos + 3,now,a);
           //判断是否已经找到移动步数
           if (dist.find(endVal) != dist.end()) return dist[endVal];
       }
       return - 1;
    }

private:
    unordered_map<int,int> dist;
    queue<int> q;
    //移动0的位置，然后存储移动后的步数
    void move(int pos,int nextPos,int now,vector<int>& a) {
        swap(a[pos],a[nextPos]);
        int newNow = zip(a);
        if (dist.find(newNow) == dist.end() || dist[newNow] > dist[now] + 1) {
            dist[newNow] = dist[now] + 1;
            q.push(newNow);
        }
        //移动回来 重置
        swap(a[pos],a[nextPos]);
    }

    //数组的值转换成常数
    int zip(vector<int>& a) {
        int ans = 0;
        for (int i = 0; i < 6; i++ ) {
           ans = ans * 10 + a[i];
        }
        return ans;
    }
    //寻找0的下标位置
    int getZeroIndex(vector<int>& a) {
        for (int i = 0; i < 6; i++) {
            if (a[i] == 0) return i;
        }
        return - 1;
    }
    //把常数值转换成数组
    vector<int> unzip(int state) {
        vector<int> ans(6,0);
        for (int i = 5; i >= 0; i--) {
            ans[i] = state % 10;
            state /= 10;
        }
        return ans;
    }
};

```

