int main() {
 
int a[] = {1,2,3432,32,3,23,1,4,153,1}
int partition(a[],)

}

void quickSort(int a[],int l,int r) {
	if (l == r) return ;
	int mid = partition(a,l,r);
	quickSort(a,l,mid);
	quickSort(a,mid + 1,r);
}

static int partition(int a[],int l,int r) {
  int prot = l + Math.random() * (r - l + 1);
  int partion = a[prot];
  while (l <= r) {
	if (a[l] < partion) l++;
	if (a[r] > partion) r--;
	if(l <= r ) {
	int tmp = a[r];
	a[r] = a[l];
	a[l] = tmp;
	} 
	l--;
	r--;
 }
 return r;
}


