<div align="center">
<h1>Mata Kuliah Algoritma dan Stuktur Data 2023</h1>
<b>Semua program, materi dan data Mata Kuliah Algoritma dan Struktur Data</b>
<br>
<h3> Praktikum Menggunakan Bahasa C</h3>
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
