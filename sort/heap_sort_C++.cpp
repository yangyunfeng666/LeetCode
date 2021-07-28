
void heap(int a[]) {
priority_queue<int> q;
for (int i = 0; i < a.length; i++) {
	q.push(-a[i]]);
}

for (int i = 0;i < a.length; i++) {
	a[i] =  -q.top();
	q.pop();
}
}
