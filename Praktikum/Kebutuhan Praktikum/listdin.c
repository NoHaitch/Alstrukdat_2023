/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;

    BUFFER(*l) = (ElType *)malloc(CAPACITY(*l) * sizeof(ElType));
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= getFirstIdx(l) && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= getFirstIdx(l) && i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return NEFF(l) == 0;
}

/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int N;
    scanf("%d", &N);
    while (!(0 <= N && N <= CAPACITY(*l)))
    {
        scanf("%d", &N);
    }
    for (int i = IDX_MIN; i < N; i++)
    {
        scanf("%d", &ELMT(*l, i));
    }
    NEFF(*l) = N;
}

void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;
    if (!isEmpty(l))
    {
        printf("[");
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            printf("%d", ELMT(l, i));
            if (i != getLastIdx(l))
            {
                printf(",");
            }
        }
        printf("]");
    }
    else
    {
        printf("[]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki NEFF sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    int i;
    ListDin l3;
    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);

    for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
    {
        if (plus)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }

        else
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if (NEFF(l1) == NEFF(l2))
    {
        boolean equal = true;
        int i;
        for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                equal = false;
                break;
            }
        }
        return equal;
    }

    else
    {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    if (isEmpty(l))
    {
        return IDX_UNDEF;
    }

    else
    {
        int i;
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                return i;
                break;
            }
        }
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i, tempmax, tempmin;
    tempmax = ELMT(l, getFirstIdx(l));
    tempmin = ELMT(l, getFirstIdx(l));

    for (i = getFirstIdx(l) + 1; i <= getLastIdx(l); i++)
    {
        if (ELMT(l, i) > tempmax)
        {
            tempmax = ELMT(l, i);
        }

        if (ELMT(l, i) < tempmin)
        {
            tempmin = ELMT(l, i);
        }
    }
    *max = tempmax;
    *min = tempmin;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = getFirstIdx(lIn); i <= getLastIdx(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{

    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        int i;
        ElType sum = 0;
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            sum += ELMT(l, i);
        }
        return sum;
    }
}

int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    if (isEmpty(l))
    {
        return 0;
    }

    else
    {
        int i, count = 0;
        for (i = getFirstIdx(l); i <= getLastIdx(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                count = count + 1;
            }
        }
        return count;
    }
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int pass, i, temp, imax, imin;
    if (asc)
    {
        for (pass = getFirstIdx(*l); pass <= getLastIdx(*l) - 1; pass++)
        {
            imin = pass;
            for (i = pass + 1; i <= getLastIdx(*l); i++)
            {
                if (ELMT(*l, imin) > ELMT(*l, i))
                {
                    imin = i;
                }
            }
            temp = ELMT(*l, imin);
            ELMT(*l, imin) = ELMT(*l, pass);
            ELMT(*l, pass) = temp;
        }
    }
    else
    {
        for (pass = getFirstIdx(*l); pass <= getLastIdx(*l) - 1; pass++)
        {
            imax = pass;
            for (i = pass + 1; i <= getLastIdx(*l); i++)
            {
                if (ELMT(*l, imax) < ELMT(*l, i))
                {
                    imax = i;
                }
            }
            temp = ELMT(*l, imax);
            ELMT(*l, imax) = ELMT(*l, pass);
            ELMT(*l, pass) = temp;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    if (isEmpty(*l))
    {
        ELMT(*l, IDX_MIN) = val;
    }
    else
    {
        if (!isFull(*l))
        {
            ELMT(*l, getLastIdx(*l) + 1) = val;
        }
    }
    NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    if (!isEmpty(*l))
    {
        *val = ELMT(*l, getLastIdx(*l));
        NEFF(*l) -= 1;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDin lNew;
    CreateListDin(&lNew, CAPACITY(*l) + num);
    NEFF(lNew) = NEFF(*l);

    IdxType i;
    for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
    {
        ELMT(lNew, i) = ELMT(*l, i);
    }
    dealocateList(l);
    *l = lNew;
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDin lNew;
    CreateListDin(&lNew, CAPACITY(*l) - num);
    if (NEFF(*l) < CAPACITY(*l) - num)
    {
        NEFF(lNew) = NEFF(*l);
    }
    else
    {
        NEFF(lNew) = CAPACITY(*l) - num;
    }

    IdxType i;
    for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
    {
        ELMT(lNew, i) = ELMT(*l, i);
    }
    dealocateList(l);
    *l = lNew;
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    ListDin lNew;
    CreateListDin(&lNew, NEFF(*l));
    NEFF(lNew) = NEFF(*l);

    IdxType i;
    for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++)
    {
        ELMT(lNew, i) = ELMT(*l, i);
    }
    dealocateList(l);
    *l = lNew;
}