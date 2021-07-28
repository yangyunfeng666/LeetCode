
void mergeSort(int a[],int l,int r) {
  if (l >= r) return; 
  int mid = (l + r) >> 1;
  mergeSort(a,l,mid);
  mergeSort(a,mid + 1,l);
  merge(a,l,mid,r);
}


static void merge(int a[],int l,int mid,int r) {
   int i = l,int j = mid + 1;
   int temp = new int[r - l + 1];
   for (int k = 0; k < temp.length; k++) {
     if (j > r || (i <= mid && a[i] <= a[j])) {
	temp[k] = a[i++];
     } else {
	temp[k] = a[j++];
     }
   }
   for (int k = 0 ; k < tmp.length; k++ ) {
	a[k + l] = tmp[k];
   }
 }
}
