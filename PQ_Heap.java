//Nolan Jaeger
package A3;
import java.util.*;

public class PQ_Heap {
	public static void BuildHeap(int[] a) {
		int n = a.length;
		for (int i = n / 2 -1; i >= 0; i--) {
            Heapify(a,n, i);
		}
		for(int i = n-1; i >= 0; i--) {
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
			n--;
			Heapify(a,i,0);
		}
		return;
	}
	public static void Heapify(int[] a,int n,int i) {
		int left = 2*i+1;
		int right = 2*i+2;
		int max = i;
		if(left < n && a[left] > a[max]) {
			max = left;
		}
		else {
			max = i;
		}
		if(right < n && a[right] > a[max]) {
			max = right;
		}
		if(max != i) {
			int temp = a[max];
			a[max] = a[i];
			a[i] = temp;
			Heapify(a,n,max);
		}
		
	}
	public static void main(String[]args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter array size");
		int N = scan.nextInt();
		int[] arr = new int[N];
		System.out.println("Enter array values(press ENTER after each entry)");
		for(int i = 0; i < N;i++) {
			arr[i] = scan.nextInt();
		}
		BuildHeap(arr);
		for(int x: arr) {
			System.out.print(x + " ");
		}
	}
}
