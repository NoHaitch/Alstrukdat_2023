/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 24 November 2023
    Soal No : Pra - 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* Selektor */
// #define ROOT(p) (p)->info
// #define LEFT(p) (p)->left
// #define RIGHT(p) (p)->right

// typedef int ElType;
// typedef struct treeNode* Address;
// typedef struct treeNode { 
//      ElType info;
//      Address left;
//      Address right;
// } TreeNode;

// /* Definisi PohonBiner */
// /* pohon Biner kosong p = NULL */

// typedef Address BinTree;

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    Address p = newTreeNode(root);
    if(p != NULL){
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    *p = newTreeNode(root);
    if(p != NULL){
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
    Address p = malloc(sizeof(TreeNode));
    if(p != NULL){
        ROOT(p) = val;
        LEFT(p) == NULL;
        RIGHT(p) == NULL;
    }

}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    return p == NULL;
}

boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
}

boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)); 
}

boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
    return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
    return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    if(isTreeEmpty(p)){
        printf("()");
    } else{
        printf("(%d",ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}  

void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    if(isTreeEmpty(p)){
        printf("()");
    } else{
        printf("(");
        printInorder(LEFT(p));
        printf("%d",ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}

void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    if(isTreeEmpty(p)){
        printf("()");
    } else{
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d",ROOT(p));
        printf(")");
    }
}

void printTreeWithDepth(BinTree p, int h, int depth)
/* FUNGSI TAMBAHAN */
/* I.S. p terdefinisi, h adalah jarak antara root dengan node, depth adalah kedalaman indentasi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan phon kanan */
{
    if(!isTreeEmpty(p)){
        int i, space = depth * h;
        for(i = 0; i<space; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeWithDepth(LEFT(p), h, depth+1);
        printTreeWithDepth(RIGHT(p), h, depth+1);
    }
}

void printTree(BinTree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    printTreeWithDepth(p, h, 0);
}

int hitungNode(BinTree root)
// Menerima sebuah pohon biner
// Mengembalikan jumlah minimum node yang perlu ditambahkan
{
    if(isOneElmt(root)){
        return 0;
    } else if(isBinary(root)){
        return hitungNode(LEFT(root)) + hitungNode(RIGHT(root));
    } else if(isUnerLeft){
        return 1 + hitungNode(LEFT(root));
    } else {
        return 1 + hitungNode(RIGHT(root));
    }
}

int hitungBebekRec(BinTree root, int n, int curr){
// hitung bebek yang rekursif dan menyimpan current bebek
    if(curr == 0){
        curr = ROOT(root);
    } else{
    curr = curr * ROOT(root);
    }
    if(isOneElmt(root)){
        printf("      curr =  %d\n",curr);
        if(n != curr){
            return 0;
        } else{
            return curr % (10000);
        }
    } else if(isUnerLeft(root)){
        printf("left  curr =  %d\n",curr);
        return hitungBebekRec(LEFT(root), n, curr);
    } else if(isUnerRight(root)){
        printf("right curr =  %d\n",curr);
        return hitungBebekRec(RIGHT(root), n, curr);
    } else{
        printf(" lr   curr =  %d\n",curr);
        return hitungBebekRec(LEFT(root), n, curr) + hitungBebekRec(RIGHT(root), n, curr);;
    }
}

int hitungBebek(BinTree root, int n)
// Menerima sebuah pohon biner
// Mengembalikan penjumlahan dari hasil kali antara bebek-bebek pada rute 
{
    if(isTreeEmpty(root)){
        return 0;
    } else{
        return hitungBebekRec(root, n, 0);
    }
}

int hitungUangRec(BinTree root, boolean isRobable){
// Menghitung uang jumlah curian secara recursif
    if(isOneElmt(root)){
        if(isRobable){
            return ROOT(root);
        } else{
            return 0;
        }
    } else if(isUnerLeft(root)){
        if(isRobable){
            return ROOT(root) + hitungUangRec(LEFT(root), !isRobable);
        } else{
            return hitungUangRec(LEFT(root), !isRobable);
        }
    } else if(isUnerRight(root)){
        if(isRobable){
            return ROOT(root) + hitungUangRec(RIGHT(root), !isRobable);
        } else{
            return hitungUangRec(RIGHT(root), !isRobable);
        }
    } else{
        int robLeft = hitungUangRec(LEFT(root),!isRobable);
        int robRight = hitungUangRec(RIGHT(root),!isRobable);
        if(isRobable){
            return robLeft + robRight + ROOT(root);
        } else{
            return robLeft + robRight;
        }
    }
}

int hitungUang(BinTree root)
// Menerima sebuah pohon biner yang menyatakan denah perumahan
// Mengembalikan jumlah maksimum uang yang bisa dicuri Burbir
{
    if(isTreeEmpty(root)){
        return 0;
    } else if(isOneElmt(root)){
        return ROOT(root);
    } else{
        int a = hitungUangRec(root, true);
        int b = hitungUangRec(root, false);
        if(a >= b){
            return a;
        } else{
            return b;
        }
    }
}   