#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class SegTree{
// Saya pake class karena ini lebih versatile, tinggal diubah sesuai dengan kebutuhan aja.
// Ini saya bikinnya pake tipe data long long ya kak, tapi kalau kakak mau tipe data lain, nanti tinggal kakak ganti aja.
// Oh ya kak, penggunaan segment tree itu biasanya kalau ada data yang berubah,
// karena kompleksitas ngerubah data di segment tree itu O(logN),
// sedangkan kalau DP biasa, kompleksitasnya O(N).
// Tapi fungsi sum dari segment tree itu kompleksitasnya O(logN),
// sedangkan DP cuma O(1).
// Jadi penggunaannya juga sesuai dengan permintaan dan constraints soal.
// Saya pake segment tree karena kemarin pake DP kena WA.
private:
	ll MAXN;
	// Saya pake vector karena ini pake class, jadi tinggal di resize aja di inisialisasi class nya.
	// Kalau buat soal  yang kemarin, saya sarankan jangan pake vector, terus jangan pake class juga.
	// Kakak keluarin aja variabel dan kode kode yang ada disini ke global, terus diganti beberapa biar lebih cepat.
	vector<ll>tree;
	vector<ll>array;
public:
	SegTree(ll n)
	{
		// Declare ukuran input.
		MAXN=n;
		// Atur ukuran tree menjadi 4 kali ukuran input.
		// Sebenernya bisa cuma 2 kalinya, tapi saya cuma paham yang 4 kali.
		tree.resize(MAXN*4);
		// Atur ukuran array sebesar ukuran input.
		array.resize(MAXN);
		// Masukin input ke array.
		for (int i=0;i<MAXN;i++)
			cin>>array[i];
		this->build(1, 0, MAXN-1);
	}
	ll merge(ll leftNode, ll rightNode)
	{
		ll ret;
		// Kalau kakak mau pake tipe data lain, bagian ini yang diubah.
		// Bagian ini menentukan kalau mau ngegabungin dua leaf.
		ret=leftNode+rightNode;
		return ret;
	}
	void build(ll vertex, ll leftBound, ll rightBound)
	{
		if (leftBound==rightBound)
		{
			// Kalau kakak mau pake array[rightBound] juga bisa, karena keduanya nunjuk ke index yang sama.
			tree[vertex] = array[leftBound];
		}
		else
		{
			ll mid = (leftBound+rightBound)/2;
			// Bagian di sebelah kiri dari vertex yang sekarang disimpen di vertex*2
			// Bagian kanannya disimpan di vertex*2+1
			build(vertex*2, leftBound, mid);
			build(vertex*2+1, mid+1, rightBound);
			// Node sekarang sama dengan penjumlahan dari node anaknya.
			tree[vertex] = merge(tree[vertex*2],tree[vertex*2+1]);
		}
	}
	ll sum(ll vertex, ll leftBound, ll rightBound, ll leftIndex, ll rightIndex)
	{
		// left dan right index itu yang lagi dicari.
		// Jadi misal lagi nyari jumlah dari index 1 sampai 5, maka leftIndex nya 1, dan rightIndex nya 5.
		if (leftIndex > rightIndex || leftIndex > rightBound || rightIndex < leftBound)
			return 0;
		// Pada dasarnya, ini mirip kayak binary search.
		// Apabila batas kiri dan kanan sesuai, langsung return nilai dari tree[vertex] yang sekarang.
		if (leftIndex==leftBound&&rightIndex==rightBound)
			return tree[vertex];
		ll mid=(leftBound+rightBound)/2;
		// Kalau index kanan lebih kecil sama dengan nilai tengah dari batasan kiri dan kanan,
		// Maka return hasil dari pencarian dengan nilai batas kanan setara mid.
		if (rightIndex<=mid)
			return sum(vertex*2, leftBound, mid, leftIndex, rightIndex);
		// Kalai index kiri lebih besar dari nilai tengah batas kiri dan kanan,
		// Maka return hasil dari pencarian dengan nilai batas kiri setara mid+1.
		else if (leftIndex>mid)
			return sum(vertex*2+1, mid+1, rightBound, leftIndex, rightIndex);
		// Tapi, apabila yang kita cari itu ada sebagian dari sebelah kiri dan kanan mid,
		// Maka pencariannya dipecah jadi dua.
		// Pencarian pertama merupakan dari left bound sampai mid, 
		// dan index yang dicari adalah left index sampai mid
		// Pencarian yang kedua adalah dari mid+1 sampai right bound,
		// dan index yang dicari adalah dari mid+1 sampari rigt index
		// Lalu, kedua hasil dari pencarian kita tambahkan dengan fungsi merge,
		else
			return merge(sum(vertex*2, leftBound, mid, leftIndex, mid), 
				sum(vertex*2+1, mid+1, rightBound, mid+1, rightIndex));
	}
	void update(ll vertex, ll leftBound, ll rightBound, ll position, ll newValue)
	{
		// Ini kalau kakak mau ngeganti nilai dari suatu value di segment tree.
		// Position itu index yang nilainya mau diganti ya kak.
		if (leftBound==rightBound)
			tree[vertex]=newValue;
		else
		{
			// Ini juga pada dasarnya binary search.
			ll mid=(leftBound+rightBound)/2;
			if (position<=mid)
				update(vertex*2, leftBound, mid, position, newValue);
			else
				update(vertex*2+1, mid+1, rightBound, position, newValue);
			tree[vertex]=merge(tree[vertex*2],tree[vertex*2+1]);
		}
	}
};
int main()
{
	ll size, query;
	cin>>size>>query;
	SegTree Tree(size);
	while (query--)
	{
		ll l,r,ans;
		cin>>l>>r;
		// Kalau indexing soal dari 1, jangan lupa l-- dan r--, 
		// karena indexing kode ini dari 0.
		ans=Tree.sum(1, 0, size-1, l, r);
		cout<<ans<<"\n";
	}
}