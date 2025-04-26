
#include <iostream>
#include <stdio.h>
#include <fstream>;
#include <Windows.h>
struct Student
{
    char FIO[1024];
    int vozrast;
    double mass;
    float len;
};

void CezarC_txt(const char* fname);
void FileC_binary(const char* fname);
void CezarSTD_txt(const char* fname);
void WndFileWorker(const char* fname);
void FileCoder(const char* fname);
void FileEncoder(const char* fname);
void Print(const char* fname);

int main()
{
    FileCoder("5.txt");
    Print("5.txt");
}

void CezarC_txt(const char* fname)
{
    int key = 7;
    char m[1024] = "Hello my friend!";
    FILE* pfile = NULL;
    fopen_s(&pfile, fname, "w");
    if (pfile != NULL)
    {
        for (int i = 0; i < strlen(m); i++)
        {
            char c = m[i];
            c = c + key;
            fprintf(pfile, "%c", c);
        }
        fclose(pfile);
    }
    printf("\nDecode file data:\n");
    fopen_s(&pfile, fname, "r");
    if (pfile != NULL)
    {
        while (!feof(pfile))
        {
            char c;
            fscanf_s(pfile, "%c", &c);
            if (!feof(pfile))
            {
                c = c - key;
                printf("%c", c);
            }
        }
        fclose(pfile);
    }
}
void FileC_binary(const char* fname)
{
    Student st;
    strcpy_s(st.FIO, 1024, "Petrov Petr Ivanovich");
    st.vozrast = 20;
    st.mass = 82.5;
    st.len = 182.7;
    FILE* pfile = NULL;
    fopen_s(&pfile, fname, "wb");
    if (pfile != NULL)
    {
        fwrite(&st, sizeof(Student), 1, pfile);
        fclose(pfile);
    }
    printf("\nRead Binary data C");
    Student np;
    fopen_s(&pfile, fname, "rb");
    if (pfile != NULL)
    {
        while (!feof(pfile))
        {
            fread(&np, sizeof(Student), 1, pfile);
            if (!feof(pfile))
            {
                printf("FIO:%s, mass:%f", np.FIO, np.mass);
            }
        }
        fclose(pfile);
    }
}
void CezarSTD_txt(const char* fname) {
    std::ofstream fo;
    fo.open(fname,std::ios::binary);
    if (fo.is_open()) {
        fo << "hello file";
        
        fo.close();
    }
    printf("\n red data STD\n");
    std::ifstream fi(fname);
    if (fi)
    {
        while (!fi.eof())
        {
            char c;
            fi >> c;
            if (!fi.eof())
                printf("%c", c);
        }
    }
}

void WndFileWorker(const char* fname) {
    HANDLE pfile = NULL;
    pfile = CreateFileA(fname
                        ,GENERIC_WRITE
                        ,0
                        ,NULL
                        ,CREATE_ALWAYS
                        ,0
                        ,NULL);
    if (pfile != INVALID_HANDLE_VALUE) 
    {
        char m[1024] = "\nhello file";
        DWORD writen = 0;
        WriteFile(pfile, m, strlen(m),&writen,NULL);
        CloseHandle(pfile);

    }
    else
    {
        DWORD code = GetLastError();


    }
    printf("\print");

}
void Print(const char* fname)
{
    FILE* pfile = NULL;
    fopen_s(&pfile, fname, "r");
    if (pfile != NULL)
    {
        while (!feof(pfile))
        {
            char c;
            fscanf_s(pfile, "%c", &c);
            if (!feof(pfile))
            {
                printf("%c", c);
            }
        }
        fclose(pfile);
    }

}
void FileCoder(const char* fname)
{
    char m[5];
    FILE* pfile = NULL;
    unsigned int i = 0;
    fopen_s(&pfile, fname, "r");
    if (pfile != NULL) {
        while (!feof(pfile)) {
            char c;
            fscanf_s(pfile, "%c", &c);
            m[i] = c;
            i++;
        }
        fclose(pfile);
    }
    
    fopen_s(&pfile, fname, "w");
    if (pfile != NULL)
    {
        for (int i = 0; i < strlen(m); i++)
        {
            unsigned char c;
            if (m[i] <= 192 && m[i] <= 239) {
                 c = m[i];
                c = c - 64;
                fprintf(pfile, "%c", c);
            }
            if(m[i] >= 240 && m[i] <= 255)
            {
                c = m[i];
                c = c - 17;
                fprintf(pfile, "%c", c);
                
            }
            else 
            {
                c = m[i];
                fprintf(pfile, "%c", c);
            }
            
            
        }
        fclose(pfile);
    }


}
void FileEncoder(const char* fname) {



}
