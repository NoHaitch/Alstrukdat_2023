<div align="center">
<h1>Mata Kuliah IF2110 Algoritma dan Stuktur Data 2023</h1>
<b>Semua program, materi dan data Mata Kuliah IF2110 Algoritma dan Struktur Data</b>
<br>
<h3> Praktikum Menggunakan Bahasa C dengan Basis ADT (Abstract Data Type) </h3>
<br>
<h3><a href="https://github.com/mrsuiii/Tubes-Alstrukdat"> Tugas Besar IF2110 Alstrukdat 2023 </a></h3>
</div> 
  
## Oleh : 
Nama : **Raden Francisco Trianto Bratadiningrat**  
NIM : **13522091**   
Jurusan : Teknik Informatika'22  
Fakultas : STEI - Komputasi  

## Getting Started for Pratikum   

1. Clone repository    
```bash
git clone https://github.com/NoHaitch/Alstrukdat_2023
``` 
2. Pindah Direktori  
```bash
# Replace X with the number of praktikum
cd Praktikum/Praktikum_X 
```
3. Lihat Soal pada Folder Soal  
4. Pastikan Isi file yang ingin dijalankan tidak include header file  
   Contoh :
  - Ubah datetime.h menjadi datetime.c
  - Ubah time.h menjadi time.c
``` c
#include <stdio.h>
#include "datetime.h"
#include "time.h"  
```  
   
5. Build
```bash
# Dengan Mingw
gcc nama_file.c -o nama_file_hasil

# contoh gcc test.c -o main
```

6. Run
```bash
# Main adalah file hasil build
main

# try ./main if it doesnt work
```
