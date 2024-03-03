#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int *val2);
void printBuffer(int *buffer, int len);

/*
	BUBBLE SORT ALG. 2 LI 2 LI GÝDEREK TUM DIZIYE BAKAR. 
	HER ÝKÝLÝ ADIMDA SWAP ISLEMI VARSA YAPILIR
	SWAP ÝSLEMÝ DEVAMLI YAPILARAK EN BUYUK DEGER EN SAGA ATILIR.
	SONRA EN BUYUK 2. DEGER SAÐDAN 2. SIRAYA ATILIR...
	SONRA EN BUYUK 3. DEGER SAÐDAN 3. SIRAYA ATILIR. VE BÖYLE DEVAM EDER

	KARMASIKLIK N2
*/
void bubleSort(int *buf, int len_buf); //void bubleSort2(int buf[], int len_buf);
void SelectionSort(int *buf, int len_buf);
/*
	DİZİNİN/ LİSTENİN 0. ELEMANINDAN DEĞİL 1. ELEMANINDAN BAKMAYA BASLANIR
	ARAMAYA BAŞLAMADAN ONCE KARŞILAŞTIRMA YAPILACAK DEĞER BİR DEĞİŞKENE ATANIR
	ATANAN DEĞİŞKENDEN DAHA BÜYÜK BİR DEĞER OLUP OLMADIĞI KONTROL EDİLİR
	EGER DEĞİŞKENİN DEĞERİNDEN DAHA BĞYÜK BİR DEĞER İLE KARŞILAŞILIRSA
	BÜYÜK DEĞER BİR BİRİM SAĞA KAYDIRILIR. VE İNDİS 1 AZALTILIR VE BU İŞLEMLER TEKRARLANIR
	BÜTÜN DEĞERLER KONTROL EDİLDİKTEN SONRA AZALTILMIS OLAN SON INDISE DEĞİŞKEN DEĞERİ EKLENİR
*/
void InsertionSort(int *buf, int len_buf);
void MergeSort(int *buf, int indis_left, int indis_right);
/*
	ONCE BUFFER LEFT VE RÝGHT OLMAK ÜZERE ÝKÝYE AYRILIR
	RECURSÝVE FONKSÝYONU YARDIMIYLA, LEFT VE RÝGHT BUFFER KENDÝ ÝÇERÝSÝNDE SÜREKLÝ OLARAK LEFT VE RÝGHT OLARAK ÝKÝYE BÖLÜNÜR
	CALISMA SIRASIYLA 
	ÝLK OLARAK LEFT BUFFER ÝÇÝN 0. VE 1. ÝNDÝS BAKILIR. KARSILASTIRMA YAPILIR GEREKÝYORSA SWAP ÝÞLEMÝ YAPILIR
	2. VE 3. ÝNDÝS E BAKILIR. AYNI ÝÞLEM YÝNE YAPILIR
	0. 1. VE 2. 3. INDIS ÝÇÝN AYNI ÝÞLEM YAPILIR.
	BU  ÝÞLEMLER RÝGTH BUFFER ÝÇÝNDE YAPILIR
	SON OLARAK SIRALI LEFT VE SIRALI RÝGHT BUFFER KENDÝ ARALARINDA KARSILASTIRMA GEREKÝRSE SWAP ÝÞLEMÝ YAPILIR

	KARMASIKLIK N.LOGN DÝR.
	*/
void Merge_Sort(int *buf, int indis_left, int indis_med, int indis_right);
void HeapSort(int *buf, int len_buf);
/*
	EN IYI ALGORİTMALARDAN BİRİDİR.
	LEFT : 2*İ
	RIGHT : 2*I+1
	PARRENT : İ/2

	SOL SAG VE UST (LARGEST) DUGUMLERDEN OLUSMAKTA. 
	EN TEPE DE Kİ [0]. 
	EN TEPEDEKİ INDIS EN KUCUK DEGERE SAHİP OLACAK 

	BU ALGORTİTMA İLK OLARAK HEAP OLUŞTURUR. BU HEAP İÇERİSİNDE DEGERLER RASTGELE DAGILMISTIR
	BU HEAP YAPILIRKEN SIRASIYLA 8. 7. 6. 5. 4. 3. 2. 1. 0. INDIS DEGERLERİ  HEAP E KOYULMUSTUR
	
	hEAP OLUSTURULDUKTAN SONRA (HEAP İÇERİSİNDEN EXTRACT YAPILARAK VERİLER SIRALANIR)
	EN AŞAĞIDAN [8]. INDISTEN İTİBAREN, EN YUKSEK DEGER EN ALTTA OLUCAK ŞEKİLDE,
	7. 6. 5. ...0. INDISE KADAR YUKARI DOGRU CIKARKEN SWAP İŞLEMLERİ GERCEKLEŞTİRİLİR

	BOYLECE EN YUKARIDA EN KUCUK EN AŞAĞIDA EN BÜYÜK DEGERLER OLACAK SEKİLDE SIRALANMA YAPILMIS OLUR

	EXTRA:

	MAX VE MIN DEGER VARDIR
	MAX KUCULUR MİN BUYUR

	EKLEME VE SILME İSLEMLERI YAPILIR
	EKLENEN BİR UST DUGUMDEN KUCUK ISE SWAP YAPILIR BİR UST DUGUME GECER VE BU SEKİLDE DEAVM EDER
	SILME ISLEMINDE EN TEPE DUGUMDEKİ DEGER SİLİNİR

	KARMASIKLIK N.LOGN DİR.
	*/
void heapify(int *arr, int n, int i);
/*
	AVANTAJI RADÝX SORT ÝLE N2 OLAN KARMASIKLIGI N.LOGN E INDIRIR.
	ANCAK RADIX DE PEK KULLANILMAZ.

	ICI BOS BÝR DIZI TANIMLANIR. BU DIZIDE HER DEGERDEN KAC ADET DEGER VAR ONUN BÝLGÝSÝ GÝRÝLÝR. 1 0 0 2 .. COUNT 
	IKINCI BÝR DIZI TANIMLANIR. BU DÝZÝ DE SIRALI SEKÝKDE INDIS ATANIR. 0. 1. 2. 3... 

	0. INDISTEN BASLAYARAK ÝLK BUFFERDAN ALINAN DEGERELR OUTPUT ÝÇERÝSÝNE COUNT SIRASINA GÖRE YERLEÞTÝRÝLÝR
	OUTPUT A SIRALI YERLEÞMÝÞ DEGERLER ÝLK BUFFERA SIRASIYLA ÝLETÝLÝR.
*/
void CountingSort(int *buf, int len_buf);

int main(void)
{
	int buffer[100];
	int len_buffer;

	cout << "Sort elenan sayisini giriniz.. :";
	cin >> len_buffer; 	cout << endl;

    srand(time(NULL));

	//veriler buffer'a eklendi
	for (int i = 0; i < len_buffer; i++)
		buffer[i] = rand() % 100;

	cout << "Before sort algorithm : ";
	printBuffer(buffer, len_buffer); //Ekrana bas

	//bubleSort(buffer, len_number);
    //SelectionSort(buffer, len_buffer);
    //InsertionSort(buffer, len_buffer);
	//MergeSort(buffer, 0, len_buffer-1);
	//HeapSort(buffer, len_buffer);
    CountingSort(buffer, len_buffer);

	cout << endl << "After sort algorithm : ";
	printBuffer(buffer, len_buffer);

    return 0;
}

void swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void bubleSort(int *buf, int len_buf) //burada direk buffer içindeki deger ile okuma yapýlýr
{
	for (int counter1 = 0; counter1 < len_buf - 1; counter1++) //0 .. n-1
		for (int counter2 = 1; counter2 < len_buf - counter1; counter2++) //1... n-i; (i = 0 ... n-1-1)  //en son buffer dizisi 1 < 2 --> en son [0] dizi ve [1] dizi karsý lastýrýlýr
			if (buf[counter2 - 1] > buf[counter2])
				swap(buf[counter2 - 1], buf[counter2]); //pointer ile cagrýldýðý için & kullanmadým
}

void SelectionSort(int *buf, int len_buf)
{
	int min; int counter1; int counter2;
	// One by one move boundary of unsorted subarray
	for (counter1 = 0; counter1 < len_buf - 1; counter1++)
	{
		// Find the minimum element in unsorted array
		min = counter1;
		for (counter2 = counter1 + 1; counter2 < len_buf; counter2++)
		{
			if (buf[counter2] < buf[min])
				min = counter2;
		}
		// Swap the found minimum element with the first element
		swap(buf[min], buf[counter1]);
	}
}

void InsertionSort(int *buf, int len_buf)
{
	int counter1, counter2, value;
	for (counter1 = 1; counter1 < len_buf; counter1++)
	{
		value = buf[counter1];
		counter2 = counter1 - 1;

		while (counter2 >= 0 && buf[counter2] > value)
		{
			buf[counter2 + 1] = buf[counter2];
			counter2 = counter2 - 1;
		}
		buf[counter2+1] = value;
	}
}

void MergeSort(int *buf, int indis_left, int indis_right)
{
	if (indis_left < indis_right)
	{
		int indis_med = indis_left + (indis_right - indis_left) / 2;

		MergeSort(buf, indis_left, indis_med);
		MergeSort(buf, indis_med + 1, indis_right);

		Merge_Sort(buf, indis_left, indis_med, indis_right);
	}
}

void Merge_Sort(int *buf, int indis_left, int indis_med, int indis_right)
{
	int temp_left_indis, temp_right_indis, all_indis;
	int len_left = indis_med - indis_left + 1;
	int len_right = indis_right - indis_med;

	/* Create temp arrays */
	int left_buffer[100];
	int right_buffer[100];


	/* Copy data to temp arrays */
	for (temp_left_indis = 0; temp_left_indis < len_left; temp_left_indis++)
		left_buffer[temp_left_indis] = buf[temp_left_indis+ indis_left];
	for (temp_right_indis = 0; temp_right_indis < len_right; temp_right_indis++)
		right_buffer[temp_right_indis] = buf[indis_med + 1 + temp_right_indis];


	temp_left_indis = 0;
	temp_right_indis = 0;
	all_indis = indis_left;


	while (temp_left_indis < len_left && temp_right_indis < len_right)
	{
		if (left_buffer[temp_left_indis] < right_buffer[temp_right_indis])
		{
			buf[all_indis] = left_buffer[temp_left_indis];
			temp_left_indis++;
		}

		else {
			buf[all_indis] = right_buffer[temp_right_indis];
			temp_right_indis++;
		}
		all_indis++;
	}

	while (temp_left_indis < len_left)
	{
		buf[all_indis] = left_buffer[temp_left_indis];
		temp_left_indis++;
		all_indis++;
	}

	while (temp_right_indis<len_right)
	{
		buf[all_indis] = right_buffer[temp_right_indis];
		temp_right_indis++;
		all_indis++;
	}
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */

void heapify(int *arr, int n, int i) //void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void HeapSort(int *buf, int len_buf)
{
	// Build heap (rearrange array)
	for (int i = len_buf / 2 - 1; i >= 0; i--)
		heapify(buf, len_buf, i);

	// One by one extract an element from heap
	for (int i = len_buf - 1; i > 0; i--) {
		// Move current root to end
		swap(buf[0], buf[i]);

		// call max heapify on the reduced heap
		heapify(buf, i, 0);
	}
}

void CountingSort(int *buf, int len_buf)
{
    #define Length 100

	int output[Length];

	// Find the largest element of the array
	int max = buf[0];
	for (int i = 1; i < len_buf; i++) {
		if (buf[i] > max)
			max = buf[i];
	}

	// The size of count must be at least (max+1) but
	// we cannot declare it as int count(max+1) in C as
	// it does not support dynamic memory allocation.
	// So, its size is provided statically.
	int count[Length];

	// Initialize count array with all zeros.
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Store the count of each element
	for (int i = 0; i < len_buf; i++) {
		count[buf[i]]++;
	}

	// Store the cummulative count of each array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = len_buf - 1; i >= 0; i--) {
		output[count[buf[i]] - 1] = buf[i];
		count[buf[i]]--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < len_buf; i++) {
		buf[i] = output[i];
	}
}

void bubleSort2(int buf[], int len_buf) //burada buffer içerisindeki adres ile okuma yapýlýr
{
	for (int counter1 = 0; counter1 < len_buf - 1; counter1++) //0 .. n-1
		for (int counter2 = 1; counter2 < len_buf - counter1; counter2++) //1... n-i; (i = 0 ... n-1-1)  //en son buffer dizisi 1 < 2 --> en son [0] dizi ve [1] dizi karsýlastýrýlýr
			if (buf[counter2 - 1] > buf[counter2])
				swap(&buf[counter2 - 1], &buf[counter2]); //pointer ile çaðrýlmadýðý için & kullandým
}

void printBuffer(int *buffer, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(buffer + i) << " "; 
		//cout << buffer[i] << " "; //buda olurdu
	cout << endl;
}

void printBuffer2(int buffer[], int len)
{
	for (int i = 0; i < len; i++)
		cout << buffer[i] << " ";
	cout << endl;
}
